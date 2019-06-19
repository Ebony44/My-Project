#include "Exam1_Cat8.h"

midterm::Cat8::Cat8(const char * name)
	: Animal8(name)
{
}

midterm::Cat8::~Cat8()
{
}

void midterm::Cat8::PrintName() const
{
	std::cout << "I'm a cat named " << mName << std::endl;

}
