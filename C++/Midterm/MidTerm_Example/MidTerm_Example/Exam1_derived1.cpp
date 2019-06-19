#include "Exam1_derived1.h"

midterm::examDerived1::examDerived1(int x)
	: examBase1(x)
{
}

midterm::examDerived1::~examDerived1()
{
}

int midterm::examDerived1::GetX() const
{
	return *mX;
}
