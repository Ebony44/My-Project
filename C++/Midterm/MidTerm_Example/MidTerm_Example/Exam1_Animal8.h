#pragma once

#include <string>

namespace midterm
{
	class Animal8
	{
	public:
		Animal8(const char* name);
		virtual ~Animal8();
		virtual void PrintName() const = 0;
	protected:
		const char* mName;



	};
}