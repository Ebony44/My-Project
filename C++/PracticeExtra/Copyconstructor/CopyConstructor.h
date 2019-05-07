#pragma once

namespace samples
{
	class String
	{
	private:
		char* m_Buffer;
		unsigned int m_Size;
	public:
		String(const char* string);
		String(const String& other);
		~String();
		char& operator[](int index);
		char* GetBuffer();
		
	};

}