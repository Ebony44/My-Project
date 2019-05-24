#include <iostream>

#include "PageReplace.h"

using namespace std;

namespace samples
{
	Vector::Vector(int pageLimit)
		: mCapacity(0)
		, mPageLimit(pageLimit)
	{
		mMemArray = new char[pageLimit];
	}
	Vector::~Vector()
	{
		delete[] mMemArray;
	}
	void Vector::AddMemory(char x)
	{

		// must set the pageLimit so it can extends more than just assignment's requirement.
		int tempCount = -1;
		if (mCapacity < mPageLimit)
		{
			mMemArray[mCapacity] = x;
			mCapacity++;
		}
		else
		{
			// count where is same one there
			for (int i = 0; i < mPageLimit; i++)
			{
				if (mMemArray[i] == x)
				{
					tempCount = i;
				}
			}

			// if tempcount is just -1... there is no match in array

			// no match
			if (tempCount == -1)
			{
				//TODO PushWhole();
				PushWhole();
				mMemArray[mPageLimit - 1] = x;
			}
			else if (tempCount != -1)
			{
				// 
				for (int i = tempCount; i < (mPageLimit+1) - tempCount; i++)
				{
					mMemArray[i] = mMemArray[i + 1];
				}
				mMemArray[mPageLimit - 1] = x;

			}

			

			
		}
		

		/*
		if (mCapacity < 4)
		{
			mMemArray[mCapacity] = x;
			mCapacity++;
		}
		// now memory has more than 4

		// same one comes up => one of element is eliminated and input will be in last.
		if (mMemArray[0] == x)
		{
			//same as different... or maybe it's not
			for (int i = 0; i < mCapacity - 1; i++)
			{
				mMemArray[i] = mMemArray[i + 1];
			}
			mMemArray[mCapacity] = x;
		}
		else if (mMemArray[1] == x)
		{
			const int PUSH_COUNT = 2;
			for (int i = 1; i < PUSH_COUNT + 1; i++)
			{
				mMemArray[i] = mMemArray[i + 1];
			}
			mMemArray[mCapacity] = x;

		}
		else if (mMemArray[2] == x)
		{
			// swap
			int temp = mMemArray[2];
			mMemArray[2] = mMemArray[3];
			mMemArray[3] = temp;

		}
		else if (mMemArray[3] == x)
		{
			// do nothing
		}


		// different => first one is eliminated and input will be in last
		if (mMemArray[0] != x && mMemArray[1] != x && mMemArray[2] != x && mMemArray[3] != x)
		{
			for (int i = 0; i < mCapacity - 1; i++)
			{
				mMemArray[i] = mMemArray[i + 1];
			}
			mMemArray[mCapacity] = x;
		}
		*/

	}
	void Vector::GetMemory()
	{
		
		for (int i = 0; i < mPageLimit; i++)
		{
			cout << mMemArray[i] << ", ";
		}
		cout << endl;

		
	}
	void CompareElement()
	{

	}
	void Vector::PushWhole()
	{
		for (int i = 0; i < mPageLimit - 1; i++)
		{
			mMemArray[i] = mMemArray[i + 1];
		}

	}
}