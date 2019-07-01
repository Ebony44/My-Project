#pragma once

#include <iostream>

#include "Exam1_VirtualFunction13.h"



namespace midterm
{
	class VirtualFunction_Derived13 : public VirtualFunction13
	{
		void method();
	public:
		virtual ~VirtualFunction_Derived13();
		

		

	};

	class VirtualFunction_Derived13_2 : public VirtualFunction13_2
	{
		void method();
	public:
		VirtualFunction_Derived13_2();
		virtual ~VirtualFunction_Derived13_2();
	};
}