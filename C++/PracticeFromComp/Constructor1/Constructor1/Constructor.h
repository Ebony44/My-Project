#pragma once



namespace samples
{
	class Vector1
	{
	private:
		Vector1();

		int mX;
		int mY;
		unsigned int mSize;
		char* mName;

	public:
		~Vector1();
		Vector1(int x, int y, const char* string);
		Vector1(const Vector1& other);
		Vector1& operator=(const Vector1& rhs);

	};




}