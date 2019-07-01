#include "Exam1_StaticVariables10.h"

namespace midterm
{
	int Static10::mCount = 10;
	Static10::Static10()
	{
		mCount++;
	}

	int Static10::GetCount() const
	{
		return mCount / 3;
	}
}

