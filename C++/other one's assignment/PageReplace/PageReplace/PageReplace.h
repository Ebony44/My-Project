#pragma once

#include <iostream>

namespace samples
{
	class Vector
	{
	public:
		Vector(int pageLimit);
		virtual ~Vector();
		void AddMemory(char x);
		void GetMemory();
		void CompareElement();
		void PushWhole();


	private:
		Vector(); // can use "delete"
		char* mMemArray;
		int mCapacity;
		int mPageLimit;
		
	};
}