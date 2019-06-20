#include "Exam1_Class3.h"

namespace midterm
{
	Class3::Class3(int x)
		:mX(x)
	{
	}

	Class3::~Class3()
	{
	}

	Class3 Class3::operator+(const Class3 & other)
	{
		int x = (mX + other.mX) * 2;
		Class3 temp(x);
		return temp;
	}
	int Class3::GetX() const
	{
		return mX;
	}
}

