#include "Exam1_Cat8.h"

namespace midterm
{
	Cat8::Cat8(const char* name)
		: Animal8(name)
	{
	}

	Cat8::~Cat8()
	{
	}

	void Cat8::PrintName() const
	{
		std::cout << "I'm a cat named " << mName << std::endl;

	}

}



