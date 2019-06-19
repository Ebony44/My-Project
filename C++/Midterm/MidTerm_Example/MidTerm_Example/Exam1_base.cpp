#include "Exam1_base.h"

midterm::examBase1::examBase1(int x)
{
	mX = new int(x);
}

midterm::examBase1::~examBase1()
{
	delete mX;
}
