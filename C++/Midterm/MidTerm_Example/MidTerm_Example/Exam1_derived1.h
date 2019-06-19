#pragma once

#include "Exam1_base.h"

namespace midterm
{
	class examDerived1 : public examBase1
	{
	public:
		examDerived1(int x);
		virtual ~examDerived1();
		virtual int GetX() const;
	};
}
