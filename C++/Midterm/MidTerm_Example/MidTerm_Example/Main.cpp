// MidTerm_Example.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


#include <bitset>
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

#include "Exam1_VirtualFunction13.h"
#include "Exam1_VirtualFunction_Derived13.h"


#include "Exam1_PointAndRef15.h"

using namespace midterm;
using namespace std;

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

void Question4()
{
	float* x = new float(12.456f);
	int* y = reinterpret_cast<int*>(x);

	float* z = reinterpret_cast<float*>(y);

	cout << *z << endl;
}

void Question8()
{
	Cat8* cat1 = new Cat8("Kitty");
	//Cat8 cat2(*cat1);
	delete cat1;
	//cat2.PrintName();

}





int main()
{
	//baseDerivedTest1();

	Question8();

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


	Class3 c3(6);
	//cout << c3 << endl;



	float a = 3.f;
	//cout << bitset<32>(a) << endl;
	cout << a << endl;
	int b = static_cast<int>(a);
	//cout << bitset<32>(b) << endl;
	cout << b << endl;




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
