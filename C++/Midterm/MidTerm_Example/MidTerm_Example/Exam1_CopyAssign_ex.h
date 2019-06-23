#pragma once

namespace midterm
{
	enum
	{
		CHAR_MAX_SIZE = 512
	};
	class midtermCopyAndAssign
	{
	public:
		//midtermCopyAndAssign(); // default
		midtermCopyAndAssign(int x, const char* name);
		midtermCopyAndAssign(const midtermCopyAndAssign& other);
		virtual ~midtermCopyAndAssign();

		midtermCopyAndAssign& operator=(const midtermCopyAndAssign& rhs);

	private:
		int mX;
		char* mName;
		size_t mSize;

	};
}