#include <iostream>

#include "Constructor.h"


using namespace std;

namespace samples
{
	Vector1::Vector1(int x, int y, const char* string)
		: mX(x)
		, mY(y)
		, mSize(strlen(string))

	{
		mName = new char[mSize];

	}
	Vector1::Vector1(const Vector1& other)
		: mX(other.mX)
		, mY(other.mY)
		, mSize(other.mSize)
	{
		memcpy(mName, other.mName, mSize);

	}
	Vector1::~Vector1()
	{
		delete[] mName;
	}
	Vector1& Vector1::operator=(const Vector1& rhs)
	{
		mX = rhs.mX;
		mY = rhs.mY;
		mSize = rhs.mSize;

		delete[] mName;
		mName = new char[mSize];
		memcpy(mName, rhs.mName, mSize);

	}
}