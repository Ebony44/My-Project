#pragma once

class TestStructAndClass
{
	
	struct
	{
		bool firstBool : 1;
		bool secondBool : 1;
		bool thirdBool : 1;
		bool fourthBool : 1;
		bool fifthBool : 1;
		bool sixthBool : 1;
		bool seventhBool : 1;
		bool eighthBool : 1;
	} BoolStructArray2[6];
public:
	TestStructAndClass();

	size_t GetSize();

	unsigned int GetFirstBool();


private:
	size_t mSize;
	//BoolStructArray2 mArray;
};