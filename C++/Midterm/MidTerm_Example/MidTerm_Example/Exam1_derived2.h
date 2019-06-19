#pragma once

#include "Exam1_base.h"

namespace midterm
{
	class examDerived2 : public examBase1
	{
	public:
		examDerived2(int x);
		virtual ~examDerived2();
		virtual int GetX() const;
	};
}
