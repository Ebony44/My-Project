#pragma once

#include <iostream>

#include "Exam1_Animal8.h"

namespace midterm
{
	class Cat8 : public Animal8
	{
		friend std::ostream& operator<<(std::ostream& os, const Cat8& cat);
	public:
		Cat8(const char* name);
		~Cat8();
		void PrintName() const;

		

	};

}