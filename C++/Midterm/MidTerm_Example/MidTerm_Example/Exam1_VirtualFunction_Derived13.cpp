#include "Exam1_VirtualFunction_Derived13.h"

void midterm::VirtualFunction_Derived13::method()
{
	std::cout << "from base" << std::endl;
}

midterm::VirtualFunction_Derived13::~VirtualFunction_Derived13()
{
	method();
}