// AssignmentPrac1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <cassert>
#include <iostream>
#include <string>

#include "MyString.h"

using namespace std;
using namespace assignment1;

int main()
{
	
	MyString s1("Hello");
	assert(s1.GetLength() == 5);

	
	/* GetCString() Ex */
	MyString s2("Hello");
	cout << s2.GetCString() << endl;
	const char* tempChar1 = new char[s2.GetLength() + 1];
	const char* tempChar2 = new char[s2.GetLength() + 1];
	tempChar1 = s2.GetCString();
	//tempChar2 = MyString("Hello").GetCString();
	//cout << tempChar1 << ", " << tempChar2 << endl;

	assert(s2 == MyString("Hello"));
	//assert(s2.GetCString() == s1.GetCString());

	/* Append() Ex */
	MyString s3("Hello");
	s3.Append(" World");
	assert(s3 == MyString("Hello World"));
	
	s2 = s2 + s1;
	/* operator+ Ex */
	MyString s41("Hello");
	MyString s42(" World");
	MyString s43 = s41 + s42;
	//s2 = s2 + s1;  소멸자 오류(이번 과제에서는 체크하지 않음)
	assert(s43 == MyString("Hello World"));

	/* IndexOf() Ex */
	MyString s5("Hello");
	
	cout << s5.IndexOf("ell") << endl;

	assert(s5.IndexOf("ell") == 1);
	
	cout << s5.IndexOf("l") << endl;

	assert(s5.IndexOf("l") == 2); // after l, stop the next step
	cout << s5.IndexOf("this") << endl;

	assert(s5.IndexOf("This") == -1);
	cout << s5.IndexOf("") << endl;
	
	cout << s5.GetSize("") << endl;

	assert(s5.IndexOf("") == 0);
	cout << s5.IndexOf("lo") << endl;

	assert(s5.IndexOf("lo") == 3);

	/* LastIndexOf() Ex */
	MyString s6("Hello");
	assert(s6.LastIndexOf("ell") == 1);
	assert(s6.LastIndexOf("l") == 3);
	assert(s6.LastIndexOf("This") == -1);
	
	
	assert(s6.LastIndexOf("") == 5);
	assert(s6.LastIndexOf("He") == 0);

	MyString s62("");
	assert(s62.LastIndexOf("") == 0);
	assert(s62.LastIndexOf("A") == -1);

	MyString s63("Hellello");
	MyString s64("Heloo");
	assert(s63.LastIndexOf("ell") == 4);
	assert(s64.LastIndexOf("ell") == -1);

	/*MyString s7("Hello");
	s7.Interleave(" World");
	cout << s7.GetLength() << endl;
	cout << s7.GetCString() << endl;*/

	/* Interleave() Ex */
	MyString s7("Hello");
	s7.Interleave(" World");
	cout << s7.GetCString() << endl;
	assert(s7 == MyString("H eWlolrold"));

	MyString s72("A");
	s72.Interleave("BCDEF");
	assert(s72 == MyString("ABCDEF"));
	cout << s72.GetCString() << endl;

	MyString s73("bcdef");
	s73.Interleave("a");
	assert(s73 == MyString("bacdef"));
	cout << s73.GetCString() << endl;


	
	//assert(s7==MyString)



	cout << s2.GetCString() << endl;
	cout << "stop" << endl;






	








	/* My Code */
	MyString ms = "Hello!";
	cout << "dread" << endl;
	cout << ms.GetCString() << endl;
	ms.Append("   Blight");
	cout << ms.GetCString() << endl;
	
	MyString ms2 = "World!";
	MyString ms3 = "       Blast!";

	cout << ms.GetCString() << endl;
	cout << ms2.GetCString() << endl;
	cout << "hell" << endl;
	MyString ms4 = ms2 + ms3;
	


	cout << ms2.GetLength() << ", " << ms3.GetLength() << endl;
	cout << ms4.GetLength() << endl;
	cout << ms4.GetCString() << endl;

	assert(ms4 == MyString("World!       Blast!"));
	
	//ms = ms2;

	cout << "clicked" << endl;
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
