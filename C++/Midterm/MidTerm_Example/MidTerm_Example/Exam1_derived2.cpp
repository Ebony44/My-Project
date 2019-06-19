#include "Exam1_derived2.h"

midterm::examDerived2::examDerived2(int x)
	: examBase1(x)
{
}

midterm::examDerived2::~examDerived2()
{
}

int midterm::examDerived2::GetX() const
{
	return *mX * 2;
}
