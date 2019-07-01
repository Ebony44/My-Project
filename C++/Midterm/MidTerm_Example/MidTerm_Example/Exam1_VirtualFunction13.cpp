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

void midterm::VirtualFunction13_2::method()
{
	std::cout << "from base 2" << std::endl;
}

midterm::VirtualFunction13_2::VirtualFunction13_2()
{
	method();
}

midterm::VirtualFunction13_2::~VirtualFunction13_2()
{
}

void midterm::VirtualFunction13_2::baseMethod()
{
	method();
}
