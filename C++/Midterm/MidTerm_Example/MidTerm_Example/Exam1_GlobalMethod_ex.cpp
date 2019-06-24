#include "Exam1_GlobalMethod_ex.h"

using namespace std;

namespace midterm
{
	GlobalMethod::GlobalMethod(int x, int y)
		: mX(x)
		, mY(y)
	{
	}
	GlobalMethod::GlobalMethod(const GlobalMethod & other)
		: mX(other.mX)
		, mY(other.mY)
	{
	}
	GlobalMethod::~GlobalMethod()
	{
	}
	GlobalMethod& GlobalMethod::operator=(const GlobalMethod& rhs)
	{
		if (this != &rhs)
		{
			mX = rhs.mX;
			mY = rhs.mY;
		}

		return *this;
	}
	GlobalMethod GlobalMethod::operator+(int number) const
	{
		GlobalMethod result(mX + number, mY + number);
		return result;
		
	}
	GlobalMethod operator+(int number, const GlobalMethod& rhs)
	{
		GlobalMethod result(rhs.mX + number, rhs.mY + number);
		return result;
		
	}
	GlobalMethod operator+(const GlobalMethod& lhs, const GlobalMethod& rhs)
	{
		GlobalMethod result(lhs.mX + rhs.mX, lhs.mY + rhs.mX);
		return result;
	}
}