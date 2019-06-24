#pragma once

#include <iostream>

namespace midterm
{
	class GlobalMethod
	{
	public:
		GlobalMethod(int x, int y);
		GlobalMethod(const GlobalMethod& other);
		virtual ~GlobalMethod();

		GlobalMethod& operator=(const GlobalMethod& rhs);

		
		GlobalMethod operator+(int number) const;
		friend GlobalMethod operator+(int number, const GlobalMethod& rhs);
		friend GlobalMethod operator+(const GlobalMethod& lhs, const GlobalMethod& rhs);

	private:

		int mX;
		int mY;

	};
}