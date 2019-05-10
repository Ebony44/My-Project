#include <iostream>
#include <cassert>

#include "MyString.h"


using namespace std;

namespace assignment1
{
	
	char* mBuffer;
	int mSize;
	MyString::MyString(const char* s)
	{
		cout << "constructor called" << endl;
		mSize = GetSize(s);
		mBuffer = new char[mSize + 1];

		mBuffer = GetCopiedString(s, mSize);
		mBuffer[mSize] = 0;
		

		//memcpy(mBuffer, s, mSize+1);

		//mBuffer = s;
	}

	MyString::MyString(const MyString& other)
	{
		cout << "copy call" << endl;
		mSize = other.mSize;
		mBuffer = new char[mSize + 1];

		//memcpy(mBuffer,other.mBuffer,mSize+1);
		mBuffer = GetCopiedString(other.mBuffer, mSize);

		

		//mBuffer = other.mBuffer;

	}

	MyString::~MyString()
	{
		cout << "Destroying old memory" << endl;
		delete[] mBuffer;
		
	}

	unsigned int MyString::GetLength() const
	{

		return mSize;
	}

	const char* MyString::GetCString() const
	{
		return mBuffer;
	}

	void MyString::Append(const char* s)
	{
		assert(s != NULL);
		//mSize = GetSize(s);
		int mFirstSize = GetSize(mBuffer);
		int mSecondSize = GetSize(s);
		mSize = mFirstSize + mSecondSize;
		// "Hel" -> 3
		// "lo" -> 2
		// "Hello" -> 5

		char* tempBuffer = new char[mSize + 1];

		for (int i = 0; i < mFirstSize; i++)
		{
			tempBuffer[i] = mBuffer[i];
			if (mBuffer[i] == NULL)
			{
				tempBuffer[i] = ' ';
			}
		}
		
		int j = 0;
		for (int i = mFirstSize; i < mSize; i++)
		{

			tempBuffer[i] = s[j];
			if (s[j] == NULL)
			{
				cout << "append null detected" << endl;
				tempBuffer[i] = ' ';
			}
			j++;
		}
		cout << "Appended" << endl;
		tempBuffer[mSize] = 0;
		//mBuffer = new char[mSize + 1];
		mBuffer = tempBuffer;

	}
	char* MyString::CharAppend(char* first, char* second, const int firstSize, const int secondSize)
	{
		int mFirstSize = firstSize;
		int mSecondSize = secondSize;
		int mTotalSize = mFirstSize + mSecondSize;
		// "Hel" -> 3
		// "lo" -> 2
		// "Hello" -> 5

		char* tempBuffer = new char[mTotalSize + 1];
		for (int i = 0; i < mFirstSize; i++)
		{
			tempBuffer[i] = first[i];
		}
		int j = 0;
		for (int i = mFirstSize; i < mTotalSize; i++)
		{

			tempBuffer[i] = second[j];
			j++;
		}
		return tempBuffer;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		// s3.mBuffer = s1.mBuffer +s2.mBuffer
		// check those s2= s1+s2?????? 

		int mNewSize = mSize + other.mSize;
		char* mNewBuffer = new char[mNewSize + 1];
		for (int i = 0; i < mSize; i++)
		{
			mNewBuffer[i] = mBuffer[i];
			if (mBuffer[i] == NULL)
			{
				mNewBuffer[i] = ' ';
			}
		}
		cout << "+ ope " << other.mBuffer << endl;
		int j = 0;
		for (int i = mSize; i < mNewSize; i++) // i = 
		{
			mNewBuffer[i] = other.mBuffer[j];
			if (other.mBuffer[j] == NULL)
			{
				cout << "null detected" << endl;
				mNewBuffer[i] = ' ';
			}
			j++;
		}
		mNewBuffer[mNewSize] = 0;
		cout << "+ operate " << mNewBuffer << endl;

		return MyString(mNewBuffer);
	}

	int MyString::IndexOf(const char* s)
	{
		int tempSize = GetSize(s);
		int indexOfString = 0;
		bool bEqual = false;
		bool bFirst = false;
		int stepCount = 0;

		int sCount = 0;
		int sCorrectCount = 0;
		
		for (int i = 0; i < mSize; i++)
		{
			if (tempSize == 0)
			{
				cout << "tempsize 0" << endl;
				indexOfString = 0;
				break;
			}


			if (mBuffer[i] == s[sCount] && bFirst == false)
			{
				cout << "called"<< mBuffer[i] << endl;
				for (int j = 0; j < tempSize; j++)
				{
					if (mBuffer[i + j] == s[sCount + j])
					{
						
						sCorrectCount++;
						cout << "correctcount " << sCorrectCount << endl;
					}
					if (sCorrectCount == tempSize)
					{
						
						bEqual = true;
						bFirst = true;
					}
				}
				
				if (bEqual == true)
				{
					cout << mBuffer[i] << endl;
					indexOfString = i;
				}
			}
			sCorrectCount = 0;
			
		}
		if (bEqual == false && tempSize != 0)
		{
			indexOfString = -1;
		}

		/*
		for (int i = 0; i < mSize; i++)
		{
			if (mBuffer[i] == s[0] && mSize - i - tempSize +1 >0 && stepCount < tempSize)
			{
				for (int j = 0; j < tempSize; j++)
				{
					if (mBuffer[i + j] != s[j])
					{
						cout << mBuffer[i+j] << ", "<< s[j] << endl;
						bEqual = false;
					}
					if (j == tempSize-1)
					{
						stepCount++;
					}
				}
				if (bEqual == true)
				{
					indexOfString = i;
				}
				
			}
			if (i == mSize - 1 && indexOfString == 0)
			{
				indexOfString = -1;
			}
		}
		if (tempSize == 0)
		{
			indexOfString = 0;
		}
		//Hello 5
		//ell 3
		// l
		// this
		// ""
		// lo 2
		// i = 3, j =0, i =4, j =1 , i=5,j=2
		*/
		
		return indexOfString;
	}

	int MyString::LastIndexOf(const char* s)
	{
		int tempSize = GetSize(s);
		int indexOfString = 0;
		bool bEqual = false;
		//bool bFirst = false;
		int stepCount = 0;

		int sCount = 0;
		int sCorrectCount = 0;

		for (int i = 0; i < mSize; i++)
		{
			if (tempSize == 0)
			{
				cout << "tempsize 0" << endl;
				indexOfString = mSize;
				break;
			}


			if (mBuffer[i] == s[sCount])
			{
				cout << "called" << mBuffer[i] << endl;
				for (int j = 0; j < tempSize; j++)
				{
					if (mBuffer[i + j] == s[sCount + j])
					{

						sCorrectCount++;
						cout << "correctcount " << sCorrectCount << endl;
					}
					if (sCorrectCount == tempSize)
					{

						bEqual = true;
						//bFirst = true;
					}
				}

				if (bEqual == true)
				{
					cout << mBuffer[i] << endl;
					indexOfString = i;
				}
			}
			sCorrectCount = 0;

		}
		if (bEqual == false && tempSize != 0)
		{
			indexOfString = -1;
		}
		
		return indexOfString;
	}

	void MyString::Interleave(const char* s)
	{
		// 1. this.mBuffer[i*2] -> 0, 2, 4, 6
		// 2. s.mBuffer[i*2 +1] ->1, 3, 5, 7
		// 3. mSize + s.mSize + 1
		// 

		int mTotalSize = mSize + GetSize(s);
		char* mNewBuffer = new char[mTotalSize];

		for (int i = 0; i < mTotalSize; i++)
		{
			bool bFirstDone = false;
			bool bSecondDone = false;

			if (mBuffer[i] != NULL && i*2 <= mTotalSize)
			{
				mNewBuffer[i * 2] = mBuffer[i];
			}
			else if(mBuffer[i] == NULL)
			{
				//cout << "first string is done" << endl;
				bFirstDone = true;
			}
			if (s[i] != NULL && i * 2 +1 <= mTotalSize)
			{
				mNewBuffer[i * 2 + 1] = s[i];
			}
			else if(s[i] == NULL)
			{
				//cout << "second string is done" << endl;
				bSecondDone = true;
			}
			if (bFirstDone == true && i * 2 <= mTotalSize && s[i] != NULL)
			{
				mNewBuffer[i * 2] = s[i];
			}
			if (bSecondDone == true && i * 2 + 1 <= mTotalSize && mBuffer[i] != NULL)
			{
				mNewBuffer[i * 2 + 1] = mBuffer[i];
			}
			
			// Hello 5
			//  world 6
			// H eWlolrold
			// 10...
			// 12
		}

		//delete[] mBuffer;
		mSize = mTotalSize;
		mNewBuffer[mSize+1] = 0;
		mBuffer = mNewBuffer;
		

		//for(int i=0;)
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		return false;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
	}

	void MyString::PadRight(unsigned int totalLength)
	{
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
	}

	void MyString::Reverse()
	{
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		bool bEqualString=false;
		if (mSize == rhs.mSize)
		{
			bEqualString = true;
		}
		cout << "operator == overloaded called " << endl;
		cout << mBuffer << endl;
		cout << rhs.mBuffer << endl;
		
		return bEqualString;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		// 0. check that is it same or not.
		// 1. allocate new
		// 2. deallocate old
		// 3. 
		// 4. return this!
		if (this != &rhs)
		{
			mSize = rhs.mSize;

			mBuffer = new char[mSize + 1];
			delete[] mBuffer;
			mBuffer = GetCopiedString(rhs.mBuffer, mSize);

			//mBuffer = rhs.mBuffer;
		}


		return *this;
	}

	void MyString::ToLower()
	{
	}

	void MyString::ToUpper()
	{
	}
	unsigned int MyString::GetSize(const char* s)
	{
		unsigned int temp = 0;
		while (true)
		{
			if (s[temp] == 0)
			{
				cout << "loop breaking in " << temp << endl;
				break;
			}
			temp++;
			assert(temp < 50);

		}
		return temp;
	}
	char* MyString::GetCopiedString(const char* s, const int size)
	{
		char* tempChar = new char[size + 1];
		for (int i = 0; i < size + 1; i++)
		{
			tempChar[i] = s[i];
		}

		return tempChar;

	}
	char MyString::FillBlank(char* s)
	{

		if (s == NULL)
		{
			return ' ';
		}
		return ' ';
	}
}