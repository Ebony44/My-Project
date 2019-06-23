
#include <iostream>

#include "Exam1_CopyAssign_ex.h"

namespace midterm
{
	midtermCopyAndAssign::midtermCopyAndAssign(int x, const char* name)
		: mX(x)
		, mSize(strlen(mName) + 1)
	{
		mName = new char[mSize];
		memcpy(mName, name, mSize);
		//mName = name;
	}

	midtermCopyAndAssign::midtermCopyAndAssign(const midtermCopyAndAssign& other)
		: mX(other.mX)
		, mSize(strlen(mName) + 1)
	{
		mName = new char[other.mSize];
		memcpy(mName, other.mName, mSize);
		//mName = other.mName;
	}

	midtermCopyAndAssign::~midtermCopyAndAssign()
	{
		delete[] mName;
	}

	midtermCopyAndAssign& midtermCopyAndAssign::operator=(const midtermCopyAndAssign& rhs)
	{
		if (this != &rhs)
		{
			delete[] mName;

			mX = rhs.mX;
			mSize = rhs.mSize;


			mName = new char[mSize];

			memcpy(mName, rhs.mName, mSize);
			
			//memcpy(mName, rhs.mName, sizeof(char*) * CHAR_MAX_SIZE);

		}

		return *this;
	}

}