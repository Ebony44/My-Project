// MidTerm_Example.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


#include <bitset>
#include <cmath>
#include <string>



#include <iomanip>
#include <iostream>

#include <stack>
#include <queue>



#include "Exam1_base.h"
#include "Exam1_derived1.h"
#include "Exam1_derived2.h"
#include "Exam1_Class3.h"

#include "Exam1_Animal8.h"
#include "Exam1_Cat8.h"

#include "Exam1_StaticVariables10.h"

#include "Exam1_VirtualFunction13.h"
#include "Exam1_VirtualFunction_Derived13.h"


#include "Exam1_PointAndRef15.h"

#include "Ass3_QueueStackMemory.h"

using namespace midterm;
using namespace std;
using namespace assignment3;

//std::cout 

//friend ostream& std::ostream::operator<<(std::ostream& os, const Class3& rhs)

/*
std::ostream& operator<<(std::ostream& stream, const Class3& other)
{
	
	stream << other.GetX() << endl;
	return stream;
}
*/



//friend void std::cout operator<<()
/*
void TestofTestofTest()
{
	//cstyle
	char* mBuffer;
	int p = 0;
	int q = strlen(mBuffer) - 1;

	while (p > q)
	{
		char temp = mBuffer[p];
		mBuffer[p] = mBuffer[q];
		mBuffer[q] = temp;
		++p;
		--q;
	}


	//string


}
std::string stringMirroring(const std::string& str)
{
	std::string temp;
	for (int i = str.length() - 1; i >= 0; --i)
	{
		temp += str[i];
	}
	return temp;
}
*/
void baseDerivedTest1()
{

	examBase1* e1 = new examDerived1(4);
	examBase1* e2 = new examDerived2(4);


	cout << e1->GetX() + e2->GetX() << endl;

	cout << setw(15) << setfill('-') << internal << "Hello World!" << endl;

	cout << showbase << hex << 16 << endl;

	cout << dec << endl;

	delete e1;
	delete e2;
}

void CallbyTestSwap(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

void CallbyTest()
{
	int a = 14;
	int b = 3;
	CallbyTestSwap(a, b);
	cout << a << endl;
}
string MirrorString(const string& str)
{
	string mirrorStr;

	for (int i = str.length() - 1; i >= 0; --i)
	{
		mirrorStr += str[i];
	}
	return mirrorStr;

}
void MirrorStringTest()
{
	string line = "What";
	line += "up";
	line += MirrorString(line) + "bro";
	cout << line << endl;
}
void SumViaClass()
{
	Class3 c1(2);
	Class3 c2(4);

	Class3 sum = c1 + c2;

}

void VirtualDestructorTest()
{
	Cat8* cat1 = new Cat8("Kitty");
	Cat8 cat2(*cat1);
	delete cat1;
	cat2.PrintName();

	// 1. copy constructor missing
	// 2. base class' destructor isn't virtual
	// 3. well....

}

void PointAndRefTest()
{
	PointAndRef15 p(10, 20);
	int *arr = (int*)&p;
	cout << arr[2] << endl;

}

void VirtualFunctionTest()
{
	VirtualFunction13* VirtualBase = new VirtualFunction_Derived13;
	VirtualBase->baseMethod();
	//VirtualBase->
	delete VirtualBase;

}

void Question1()
{
	
}
void Question2()
{
	std::cout << std::setw(15) << std::setfill('-') << std::internal << "Hello World";
}

void Question3()
{
	Class3 c1(2);
	Class3 c2(3);
	Class3 sum = c1 + c2;

	cout << sum.GetX() << endl;
}

void Question4()
{
	float* x = new float(12.456f);
	int* y = reinterpret_cast<int*>(x);

	float* z = reinterpret_cast<float*>(y);

	cout << *z << endl;

	float i = 12.456f;
	int j = static_cast<int>(i);

	float k = static_cast<float>(j);

	cout << k << endl;



}
void Question7()
{
	string line = "What";
	line += "up";
	line += MirrorString(line) + "bro";
	cout << line << endl;
}

void Question8()
{
	//Cat8* cat1 = new Cat8("Kitty");
	//Cat8 cat2(*cat1);
	//delete cat1;
	//cat2.PrintName();

	Cat8 cat("kitty");
	std::cout << cat << std::endl;


}

void Question9()
{
	float a = 3.f;
	int b = static_cast<int>(a);
	int c = 1;
	float d = *reinterpret_cast<float*>(&c);

}

void Question10()
{
	Static10* s1 = new Static10();
	Static10* s2 = new Static10();
	std::cout << s1->GetCount() << endl;
	delete s1;
	delete s2;
}

void Question11()
{
	std::string str1("Java");
	std::string str2("Java");

	bool bEqual = (str1 == str2);

	bEqual = (str1.c_str() == str2.c_str());

}

class Vector
{
public:
	int mX;
	int mY;

};
Vector operator*(Vector&v, int x)
{
	Vector a;
	a.mX = v.mX * x;
	a.mY = v.mY * x;
	return a;
}
Vector operator/(Vector& v, float x)
{
	Vector a;
	a.mX = v.mX / x;
	a.mY = v.mY / x;
	return a;
}

void Question12()
{
	Vector v1;
	v1.mX = 1;
	v1.mY = 2;

	Vector v2 = v1 * 2;

	std::cout << v2.mX << std::endl;

	v2 = v1 / 2.f;
	std::cout << v2.mY << std::endl;


}

void Question14()
{
	VirtualFunction13* VirtualBase = new VirtualFunction_Derived13;
	VirtualBase->baseMethod();
	//VirtualBase->
	delete VirtualBase;

}
void Question14_ex()
{
	VirtualFunction13_2* virtualBase2 = new VirtualFunction_Derived13_2();

}

void Ass3MemoryTest()
{
	QueueStack<int>* qs1 = new QueueStack<int>(1);
	QueueStackMinimalized<int>* qsm1 = new QueueStackMinimalized<int>(1);
	size_t qsSize = sizeof(*qs1);
	size_t qsmSize = sizeof(*qsm1);

	

	size_t qsQueueStackSize = sizeof(qs1->mQueueStack);
	size_t qsmStackSize = sizeof(qsm1->mStandbyStack);
	size_t qsmQueueSize = sizeof(qsm1->mCompleteQueue);


	stack<int> ss1;

	size_t ssSize = sizeof(ss1);

}
struct bsArray
{
	bool firstBool : 1;
	bool secondBool : 1;
	bool thirdBool : 1;
	bool fourthBool : 1;
	bool fifthBool : 1;
	bool sixthBool : 1;
	bool seventhBool : 1;
	bool eighthBool : 1;
} BoolStructArray[12];

struct bsBit
{
	bool firstBool : 1;
	bool secondBool : 1;
	bool thirdBool : 1;
	bool fourthBool : 1;
	bool fifthBool : 1;
	bool sixthBool : 1;
	bool seventhBool : 1;
	bool eighthBool : 1;
	//bool ninethBool : 1;
	//bool tenthBool : 1;
	//bool eleventhBool : 1;
	//bool twelvethBool : 1;
};


void Lab81BitTest()
{
	
	__int32 testInt;
	bool turnOn = true;
	bool turnOff = false;
	__int32 testInt2 = 17;
	__int32 testInt3 = 16;
	bool testint2Bool = testInt2 & 1;
	bool testint3Bool = testInt3 & 1;

	testInt = pow(2, 2) * turnOn;
	testInt += pow(2, 3) * turnOff;
	testInt += pow(2, 4) * turnOn;
	testInt += pow(2, 5) * turnOff;
	testInt += pow(2, 6) * turnOn;

	cout << testInt << endl;

	int bits = 0x0030;
	bool third_bit = bits & 0x0004;
	bool fifth_bit = bits & 0x0010;

	bitset<512> b(std::string("001"));
	b.set(2, true);
	cout << bits << endl;
	cout << third_bit << endl;
	cout << fifth_bit << endl;
	cout << b[1] << ' ' << b[2] << endl;
	cout << boolalpha << " test int 2 is : " << testint2Bool << " and 3 is : " << testint3Bool << endl;

	bool boolArray[3];
	__int32 oneBitData = 0;

	boolArray[0] = oneBitData;
	boolArray[1] = ~oneBitData;
	oneBitData = 1;
	boolArray[2] = oneBitData;

	cout << boolalpha << boolArray[0] << endl;
	cout << boolalpha << boolArray[1] << endl;
	cout << boolalpha << boolArray[2] << endl;

	
	//typedef struct Bool { unsigned value : 1; } Bool;
	struct 
	{
		
		unsigned int firstBool : 1;
		unsigned int secondBool : 1;
		unsigned int thirdBool : 1;
		unsigned int fourthBool : 1;
		unsigned int fifthBool : 1;
		unsigned int sixthBool : 1;
		unsigned int seventhBool : 1;
		unsigned int eighthBool : 1;
		

	} BoolStruct;
	class TestStructAndClass
	{
		enum { MAX = 9};

	public:
		TestStructAndClass()
			: mSize(0)
		{

		}
		size_t GetSize()
		{
			return 0;
		}
		unsigned int GetFirstBool()
		{
			return 0;
		}


	private:
		size_t mSize;
		bsBit mArray[MAX];
	};
	
	
	
	/*
	struct
	{

		//__int32 firstBool[8] : 1;

	} BoolStructArray;
	*/
	
	TestStructAndClass tsClass;
	cout << "boxprops size :" << sizeof(BoolStruct) << endl;
	cout << "boolArray size :" << sizeof(BoolStructArray) << endl;
	cout << "65 size :" << (sizeof(int32_t) * 3) << endl;
	std::bitset<65> asdf;
	cout << "bitset 65 size : " << sizeof(asdf) << endl;
	std::bitset<64> zxcv;
	cout << "bitset 64 size : " << sizeof(zxcv) << endl;
	__int32 testArray[1];
	__int32 testArray2[2];
	__int32 testArray3[3];
	cout << "int32[1] size : " << sizeof(testArray) << endl;
	cout << "int32[2] size : " << sizeof(testArray2) << endl;
	cout << "int32[3] size : " << sizeof(testArray3) << endl;

	cout << "65/32 size : " << ceil(static_cast <float> (65) / 32) << endl;
	cout << "StructClss size : " << sizeof(tsClass) << endl;

	BoolStructArray[2].firstBool = 1;
	BoolStructArray[2].secondBool = 0;

	cout << boolalpha << BoolStructArray[2].firstBool << endl;
	cout << boolalpha << BoolStructArray[2].secondBool << endl;


	//unsigned int tempUInt = BoolStruct firstbool;
	//unsigned int tempInt = BoolStruct[1];

	BoolStruct.firstBool = 0;
	BoolStruct.secondBool = 1;


	__int32 reversedBoolArray[5];
	bool boolData = true;
	cout << "test of reversed" << endl;
	reversedBoolArray[0] = BoolStruct.firstBool;
	reversedBoolArray[1] = BoolStruct.secondBool;
	boolData = false;
	reversedBoolArray[2] = boolData;
	reversedBoolArray[3] = oneBitData;
	reversedBoolArray[4] = boolArray[0];



	cout << boolalpha << reversedBoolArray[0] << endl;
	cout << boolalpha << reversedBoolArray[1] << endl;
	cout << boolalpha << reversedBoolArray[2] << endl;
	cout << " [3] is oneBitdata (value is 1), [4] is boolArray[0] (value is 0)" << endl;
	cout << boolalpha << static_cast<bool> (reversedBoolArray[3]) << endl;
	cout << boolalpha << static_cast<bool> (reversedBoolArray[4]) << endl;

	cout << "test of struct and class" << endl;

	/*
	TestStructAndClass testStructClass;
	testStructClass.mStruct.firstBool = 1;
	testStructClass.mStruct.secondBool = 1;

	cout << boolalpha << static_cast<bool>(testStructClass.GetFirstBool()) << endl;
	testStructClass.mStruct.firstBool = 0;
	cout << boolalpha << static_cast<bool>(testStructClass.GetFirstBool()) << endl;
	*/


}




int main()
{

	Lab81BitTest();

	//Ass3MemoryTest();

	/*
	int* singedNumber = new int(-10);
	unsigned int* unsignedNumber = reinterpret_cast<unsigned int*>(singedNumber);
	//cout << dec << internal << setw(15)  << setfill('*') << 14 << endl;
	//cout << setw(25) << setfill('&') << internal <<  "  white  space " << endl;

	//baseDerivedTest1();

	Question2();
	//Question3();
	//Question4();
	//Question7();
	Question8();
	//Question9();
	Question10();
	//Question11();

	//Question12();
	Question14();
	Question14_ex();
	



	//Question1();
	//CallbyTest();
	//MirrorStringTest();
	//SumViaClass();
	//VirtualDestructorTest();
	//PointAndRefTest();
	//VirtualFunctionTest();


	int* numberTest = new int(5);
	//delete numberTest;



	const char* text = "Hello, world";
	std::cout.operator<<(text) << endl;
	std::cout.operator<<(text);
	//std::operator<<(text) 
	cout << text << endl;
	//delete text;

	char* anotherText = new char('a');


	Class3 c3(6);
	//cout << c3 << endl;



	float a = 3.f;
	//cout << bitset<32>(a) << endl;
	cout << a << endl;
	int b = static_cast<int>(a);
	//cout << bitset<32>(b) << endl;
	cout << b << endl;
	*/



	/*
	queue<std::string> studentNameQueue;
	studentNameQueue.push("Coco");
	studentNameQueue.push("Mocha");

	while (!studentNameQueue.empty())
	{
		cout << "Waitimg Student: " << studentNameQueue.front() << endl;
		studentNameQueue.pop();
	}

	stack<std::string> studentNameStack;
	studentNameStack.push("Draco");
	studentNameStack.push("Doncho");

	while (!studentNameStack.empty())
	{
		cout << "Waiting Student: " << studentNameStack.top() << endl;
		studentNameStack.pop();
		
	}
	*/



	/*
	size_t sz = 4;

	while (sz-- >= 0)
	{
		cout << sz << endl;
	}
	*/

	// 1. cout formatting
	// 2. Pointer and Reference
	// 3. 



}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
