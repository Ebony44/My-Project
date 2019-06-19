#pragma once

#include <iostream>

#include "Exam1_Animal8.h"

namespace midterm
{
	class Cat8 : public Animal8
	{

	public:
		Cat8(const char* name);
		~Cat8();
		virtual void PrintName() const;


	};
}