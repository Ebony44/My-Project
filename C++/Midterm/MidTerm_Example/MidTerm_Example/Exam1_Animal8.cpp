#include "Exam1_Animal8.h"


namespace midterm
{
	Animal8::Animal8(const char* name)
		: mName(name)
	{
	}

	Animal8::~Animal8()
	{
		//delete[] mName;
		/*
		for (unsigned int i = 0; i < strlen(mName); i++)
		{
			delete mName[i];
		}
		*/
	}
}

