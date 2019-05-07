#include <iostream>

#include "CopyConstructor.h"

using namespace std;

namespace samples
{

	char* m_Buffer;
	int m_Size;
	String::String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size+1];
		for (int i = 0; i < m_Size; i++)
		{
			m_Buffer[i] = string[i];
		}
		m_Buffer[m_Size] = 0;
		//memcpy(m_Buffer, string, m_Size);
	}

	String::String(const String& other)
		: m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
		cout << "Copied Constructor!" << endl;
		//memcpy(this, &other, sizeof(String));
	}

	String::~String()
	{
		delete[] m_Buffer;
	}
	char& String::operator[](int index)
	{
		return m_Buffer[index];
	}
	char* String::GetBuffer()
	{
		return m_Buffer;
	}

}
