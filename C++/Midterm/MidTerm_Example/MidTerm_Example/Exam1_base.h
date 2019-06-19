#pragma once


namespace midterm
{
	class examBase1
	{
	public:
		examBase1(int x);
		virtual ~examBase1();
		virtual int GetX() const = 0;
	protected:
		int* mX;
	};
}
