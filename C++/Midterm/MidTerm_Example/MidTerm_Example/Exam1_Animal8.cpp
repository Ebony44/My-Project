#include "Exam1_Animal8.h"

midterm::Animal8::Animal8(const char* name)
	: mName(name)
{
}

midterm::Animal8::~Animal8()
{
	delete mName;
}
