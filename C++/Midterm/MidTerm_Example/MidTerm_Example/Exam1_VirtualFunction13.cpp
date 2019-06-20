#include "Exam1_VirtualFunction13.h"

void midterm::VirtualFunction13::method()
{
	std::cout << "from base" << std::endl; 
}

midterm::VirtualFunction13::~VirtualFunction13()
{
	method();
}

void midterm::VirtualFunction13::baseMethod()
{
	method();
}
