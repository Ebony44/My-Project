#include <iostream>

#include "ConstructorPractice.h"

using namespace std;

namespace samples
{
	
	
	ConstructorPr::ConstructorPr(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
		float x, y;
		/*
		void Init()
		{
			x = 0.0f;
			y = 0.0f;
		}
		*/
		void ConstructorPr::Print()
		{
			cout << x << ", " << y << endl;
		}
}