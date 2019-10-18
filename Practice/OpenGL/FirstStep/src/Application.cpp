#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cassert>

#include <fstream>
#include <string>
#include <sstream>


#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__,__LINE__))


static void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
	
}

static void GLCheckError()
{
	while (GLenum error = glGetError())
	{
		std::cout << "[Open GL Error] (" << error << ")" << std::endl;
	}
}
static bool GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[Open GL Error] (" << error << ")" << function 
			<< " "  << file << ":" << line << std::endl;
		return false;
	}
	return true;
}

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FramentSource;
};

static ShaderProgramSource ParseShader(const std::string& filepath)
{
	std::ifstream stream(filepath);

	enum class ShaderType
	{
		NONE = -1,
		VERTEX = 0,
		FRAGMENT = 1,
	};

	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;
	while (getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				// set mode to vertex
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				// set mode to fragment
				type = ShaderType::FRAGMENT;
			}
		}
		else
		{
			ss[static_cast<int>(type)] << line << '\n';
			// ss[(int)type] << line << '\n';
		}
	}
	return { ss[0].str(), ss[1].str() };

}



static unsigned int CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	
	// if ()
	const char* src = source.c_str();
	// const char* src = &source[0];

	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	// TODO: Error Handling...

	int result;

	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*) alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);

		std::cout << "failed to compile" << (type == GL_VERTEX_SHADER ? "Vertex" : " other" ) << " shader!" << std::endl;
		std::cout << message << std::endl;

		glDeleteShader(id);
		return 0;
	}

	return id;
	
}

// for practice, take parameter as std::string....
// this way is simplified version...
static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
	

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);
	
	// a lot of game engines don't even bother calling glDetachShader()
	// not worth it.

	return program;

}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);


	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error!" << std::endl;
	}
	else
	{
		std::cout << "just fine" << std::endl;
	}
	std::cout << glGetString(GL_VERSION) << std::endl;

	// define vertex buffer
	unsigned int vao;
	GLCall(glGenVertexArrays(1, &vao));
	GLCall(glBindVertexArray(vao));
	

	unsigned int buffer;
	float positions[6] = {
		-0.5f,-0.5f,
		0.0f, 0.5f,
		0.5f, -0.5f
	};
	float sqaurePositions[12] = {
		-0.5f,-0.5f,
		0.5f, -0.5f,
		0.5f, 0.5f,

		0.5f, 0.5f,
		-0.5f, 0.5f,
		-0.5f, -0.5f,
	};
	float modifiedPositions[] = {
		-0.5f,-0.5f, // 0
		0.5f, -0.5f, // 1
		0.5f, 0.5f, // 2
		-0.5f, 0.5f, // 3
	};
	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0

	};
	
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	//glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
	//glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), sqaurePositions, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(float), modifiedPositions, GL_STATIC_DRAW);

	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0));

	unsigned int ibo;
	GLCall(glGenBuffers(1, &ibo));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW));

	
	// shader time
	/*
	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = position;\n"
		"}\n";
	std::string fragmentShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	color = vec4(0.0, 0.0, 1.0, 1.0);\n"
		"}\n";
	*/


	ShaderProgramSource source = ParseShader("res/shaders/Basic.shader");
	//std::cout << "VERTEX SHADER" << std::endl;
	//std::cout << source.VertexSource << std::endl;
	//std::cout << "FRAGMENT SHADER" << std::endl;
	//std::cout << source.FramentSource << std::endl;


	// unsigned int shader = CreateShader(vertexShader, fragmentShader);
	unsigned int shader = CreateShader(source.VertexSource, source.FramentSource);
	GLCall(glUseProgram(shader));

	GLCall(int location = glGetUniformLocation(shader, "u_Color"));
	ASSERT(location != -1);
	GLCall(glUniform4f(location, 0.2f, 0.3f, 0.8f, 1.0f));


	// unbind everything...
	GLCall(glBindVertexArray(0));
	GLCall(glUseProgram(0));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));

	//

	float r = 0.0f;
	float increment = 0.05f;
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		// glDrawArrays(GL_TRIANGLES, 0, 3);
		//glDrawArrays(GL_TRIANGLES, 0, 6);
		
		//GLClearError();

		// bind function in here
		GLCall(glUseProgram(shader)); // bind up shader
		GLCall(glUniform4f(location, r, 0.3f, 0.8f, 1.0f)); //setup uniform



		GLCall(glBindVertexArray(vao)); // now below 3 lines are unnecessary. // vertex array and index buffer will handle..
		// glBindBuffer(GL_ARRAY_BUFFER, buffer); //bind vertex buffer
		// glEnableVertexAttribArray(0); //set up the layout of thet vertex buffer
		// glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0); //set up the layout of thet vertex buffer
		
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo)); //bind out that index buffer


		// glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		//GLCall(glUniform4f(location, r, 0.3f, 0.8f, 1.0f));
		GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr)); // then call draw..

		if (r > 1.0f)
		{
			increment = -0.05f;
		}
		else if (r < 0.0f)
		{
			increment = 0.05f;
		}
		r += increment;

		//glDrawElements(GL_TRIANGLES, 6, GL_INT, nullptr);
		//GLCheckError();
		//ASSERT(GLLogCall());

		// glDrawElements(GL_TRIANGLES,3,)

		/*
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f,-0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		*/

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glDeleteProgram(shader);

	glfwTerminate();
	return 0;
}