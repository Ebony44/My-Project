#pragma once

#include <iostream>

namespace midterm
{
	class VirtualFunction13
	{
		virtual void method();
	public:
		virtual ~VirtualFunction13();
		void baseMethod();
		


	};

	class VirtualFunction13_2
	{
		virtual void method();
	public:
		VirtualFunction13_2();
		virtual ~VirtualFunction13_2();
		void baseMethod();
	};
}