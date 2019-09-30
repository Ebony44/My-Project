// Final_Example.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//



#include <algorithm>
#include <functional>
#include <list>

#include <iostream>
#include<iomanip>


#include <string>
#include <vector>

#include <map>
#include <memory>


#include <unordered_set>
#include <unordered_map>

#include "Score.h"

#include "Example1.h"
#include "Example5.h"
#include "Example6.h"
#include "Example10.h"
#include "Example15.h"
#include "SimpleTemplateProgramming_10_1.h"

#include "FinalResultReview.h"


#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  





#define STR(name) #name
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__ )

// _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


using namespace samples;
using namespace std;
using namespace final;




struct S
{
	std::string first_name;
	std::string last_name;
};

bool operator==(const S& lhs, const S& rhs)
{
	return lhs.first_name == rhs.first_name && lhs.last_name == rhs.last_name;
}

struct MyHash
{
	std::size_t operator() (S const& s) const noexcept
	{
		std::size_t h1 = std::hash<std::string>{}(s.first_name);
		std::size_t h2 = std::hash<std::string>{}(s.last_name);

		return h1 ^ (h2 << 1);
	}
};


namespace std
{
	template<> struct hash<S>
	{
		typedef S argument_type;
		typedef std::size_t result_type;
		result_type operator()(argument_type const& s) const noexcept
		{
			result_type const h1(std::hash<std::string>{}(s.first_name));
			result_type const h2(std::hash<std::string>{}(s.last_name));
			return h1 ^ (h2 << 1); // or use boost::hash_combine (see Discussion)
		}
	};
}

// above is custom hash

int AddingIntVector(const vector<int>& scores)
{
	
	int sum = 0;

	for (size_t i = 0; i < scores.size(); i++)
	{
		sum += scores[i];
	}

	return sum;
}

template<typename T>
T Add(const T& t1, const T& t2)
{
	T tempT = t1 + t2;
	return tempT;
}


void TestExample1()
{
	std::map<int, char> myMap1;
	myMap1.insert(std::pair<int, char>(3, 'b'));
	myMap1.insert(std::pair<int, char>(7, 'a'));
	myMap1.insert(std::pair<int, char>(13, 'd'));
	myMap1.insert(std::pair<int, char>(2, 'c'));

	std::vector<int> myVector1 = Example1<int>::GetKeys(myMap1);

	
	
	
}

void TestExample2()
{
	// 2.a
	std::vector<int> v;

	v.push_back(5);
	v.push_back(6);
	v.push_back(4);
	v.push_back(7);

	v.resize(1);
	for (auto iter = v.begin(); iter != v.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}


	// my answer : 5
	// my 2nd answer : 5, and capacity and size are 1
	// wrong, it's capacity is still 4!!!!!!!!!!!!!!!!!!!


	// 2.b

	std::map<int, int> map;

	map[0] = 1;
	int x = map[1];

	std::cout << map.size() << std::endl;

	// my answer: 1
	// -> wrong, it's 2 maybe int x stored map's 2nd element...

	// 2.c

	std::vector<int> vc1;
	vc1.reserve(7);
	for (size_t i = 0; i < 7; ++i)
	{
		vc1.push_back(i);
	}

	std::vector<int> vc2(6);

	std::copy(vc1.begin() + 2, vc1.end() - 2, vc2.begin());

	for (auto iter = vc2.begin(); iter != vc2.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}

	// 7 elements are 10
	// 6 elemetns are 0
	// 5 elements are 10
	// my answer 10, 10, 10, 10, 10
	// wrong, it will copy vc1's 2nd, 3rd, 4th elements and paste to vc2, 
	// which 0,0,0, 0,0,0 -> 10,10,10, 0,0,0

	// 2.d
	
	std::vector<int> vd1(2);
	vd1.push_back(1);
	vd1.push_back(2);
	vd1.push_back(3);
	vd1.push_back(4);

	for (auto iter = vd1.begin(); iter != vd1.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}

	// 1, 2, 3, 4
	// wrong, 0, 0, 1, 2, 3, 4
	// holy shiit

}

void TestExample3()
{
	std::map<int, char> map;
	map.insert(std::pair<int, char>(10, 'a'));
	map.insert(std::pair<int, char>(2, 'b'));
	map.insert(std::pair<int, char>(5, 'c'));
	map.insert(std::pair<int, char>(11, 'd'));

	for (std::map<int, char>::iterator it = map.begin(); it != map.end(); ++it)
	{
		std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
	}



}

void TestExample4()
{
	char tempChar1 = 'b';
	char tempChar2 = 'a';

	char tempChar3 = Add(tempChar1, static_cast<char> ((tempChar2 - 96)));

}

void TestExample5()
{
	MyClass<bool, int> a(true, 10);
	MyClass<int, char> b(2, 'a');
	MyClass<char, char> c('a', 'b');

	a.DoSomething();
	b.DoSomething();
	c.DoSomething();
	// my answer : Foo, Bar, Foo
	// right!

}

void TestExample6()
{
	// 헤더 내부에 final 선언해놓고 virtual이 있는 건 왜인가 -> 컴파일 오류
	// Example6.h 참조

	Example6Parent parent;
	Example6Child child;
	parent.DoSomething('c');
	child.DoSomething('b');


}

void TestExample7()
{
	auto a = std::make_unique<int>(10);
	//auto b = a;
	auto b = std::move(a);

	std::cout << *b << std::endl;

	// my answer: 컴파일 오류, 이미 할당된 unique 포인터를 다른 곳에 할당하려 해서...

	// 고치기 
	// auto b = std::move(a);
	// 출력되는 값: 10
	
}

void TestExample8()
{
	auto a = std::make_shared<int>(10);
	auto b = a;

	std::weak_ptr<int> w = b;

	std::cout << a.use_count() << std::endl;

	// my answer: 오류 없음, 출력되는 값은 2

}

void TestExample9()
{
	auto a = std::make_shared<int>(10);
	std::weak_ptr<int> w = a;
	//std::cout << *w << std::endl;
	std::cout << *w.lock() << std::endl;

	// my answer : 컴파일 에러, .lock() 해서 써라.. -> 조금 더 세밀하게 말하자면
	// modified : weak_ptr에서 원시포인터나 값을 뽑아낼 수 없다. 그러고 싶다면 .lock()해라.
	// 고친 후 출력되는 값 -> 10

	// -> std::cout << *w.lock() << std::endl;

}

void TestExample10()
{
	Foo f;
	f.BlackMagic(5);

	// my answer: 오류 없음. 출력되는 값은 5
	// wrong -> 집어넣는 값 5는 컴파일 시간에 정해지는 값이 아니라서 식이 상수로 계산되지 않아서 에러가 난다.


}

void TestExample11()
{
	int a = 10;
	//auto magic = [](int x)
	auto magic = [=](int x)
	{
		return a + x;
	};
	
	std::cout << magic(10) << std::endl;
	// my answer : 컴파일 에러, [] 조건에 값으로 인해서 캡쳐해야만 이를 수정은 불가능하되 쓸 수는 있다.
	// 출력되는 값은 20

}

void TestExample12()
{
	int w = 1;
	int x = 10;
	int y = 11;
	int z = 12;

	auto magic = [=, &w, &y]()
	{
		y = 10;
		w = 0;
		return w + x + y + z;
	};
	std::cout << magic() << std::endl;

	
	// my answer: 컴파일 에러, 비록 값 참조라도 수정은 불가능해서
	// 출력되는 값은 32
	// wrong, =에 z까지 포함되어 있어서 겹쳐서 쓰지 말 것
		
}

void TestExample13()
{
	int x = 10;
	//&x = 20;
	std::cout << x << std::endl;

	// my answer : rvalue에 직접 값을 대입할 수는 없다. 컴파일 에러
	// for the detail : 지속되는 값이 아니라서, 만약 
	//const int& x = 20; 이라고 짤막하게 선언하고 값을 집어넣었다면 이는 괜찮다.
	// 

}

void TestExample14()
{
	int* x = new int(10);
	*(x + 1) = 23;

	// my answer: 컴파일이 된다. 만약 앞에 *가 없다면 rvalue가 되어서 안 되었겠지만.
	// 엄밀히 말하면 x의 다음 번에 있는 메모리의 값을 23으로..
}

void TestExample15()
{
	Example15 f('a');
	Example15 f2 = std::move(f);

	std::cout << f2.GetC() << std::endl;
	// myAnswer : 오류 없음, 출력되는 값은 a
	// wrong, std::move는 복사 생성자도 필요로 하는 듯 하다. 
	// for the details
	// 우측값 참조라 정의한 것들도 좌측값 혹은 우측값이 될 수 있다. 이를 판단하는 기준은, 만일 이름이 있다면 좌측값, 없다면 우측값이다.
}

void HashExample()
{
	std::string str = "Meet the new boss...";
	std::size_t str_hash = std::hash<std::string>{} (str);
	std::cout << "hash(" << std::quoted(str) << ") = " << str_hash << '\n';

	S obj = { "Hubert", "Farnsworth" };
	// using the standalone function object

	std::cout << "hash(" << std::quoted(obj.first_name) << ','
		<< std::quoted(obj.last_name) << ") = "
		<< MyHash{} (obj) << " (using MyHash)\n                           or "
		<< std::hash<S>{}(obj) << " (using injected std::hash<S> specialization)\n";


	std::unordered_set<S> names = { obj, {"Bender", "Rodriguez"}, {"Turanga", "Leela"} };
	for (auto& s : names)
		std::cout << std::quoted(s.first_name) << ' ' << std::quoted(s.last_name) << '\n';

}

void SimpleTemplateProgramming()
{
	SimpleTemplateProgramming1<int, 4> s1(1,2);
	SimpleTemplateProgramming1<double, 4> s2(2);

	int simpleInt = s1.Add(2, 3);
	double simpleDouble = s1.Divide(4, 4);
	//double simpleDouble2 = s2.Divide(2, 2);

}

void TestExtra2()
{
	std::vector<int> v1(1);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	std::vector<int> v2(v1.begin(), v1.begin() + 3);

	v1.resize(15);



}

void RangedForLoopExample()
{
	std::vector<int> vector1;
	vector1.push_back(3);
	vector1.push_back(5);
	vector1.push_back(7);
	vector1.push_back(8);

	std::map<std::string, int> map1;
	map1["Draste"] = 4;
	map1["Drasco"] = 7;
	map1["Blithe"] = 0;
	map1["Necra"] = 21;
	std::unordered_map<std::string, int> uMap1;
	uMap1["asdf"] = 15;
	uMap1["qwer"] = 35;
	uMap1["zxcv"] = 45;
	uMap1["fghj"] = 75;

	for (auto& i : uMap1)
	{
		cout << i.first << endl;
		cout << i.second << endl;
	}

}
template<typename ITER, typename T>
const ITER* Myfind(const ITER* begin, const ITER* end, const T& value)
{
	const ITER* p = begin;
	while (p != end)
	{
		if (*p == value)
		{
			break;
		}
		++p;
	}
	return p;
}
void MyfindFunction()
{
	const int ARRAY_SIZE = 10;
	int arr[ARRAY_SIZE] = { 10,20,30,40,50,13,52,80,100,5 };
	const int* ptr = Myfind(arr, arr + ARRAY_SIZE, 80);

}

void MyVectorInsertDeleteAtMiddle()
{
	vector<Score*> scores;
	scores.reserve(5);

	Score* cppScore = new Score(30, "C++");
	Score* algoScore = new Score(59, "Algorithm");
	Score* javaScore = new Score(87, "Java");
	Score* dataCommScore = new Score(74, "Data Comm");
	Score* androidScore = new Score(41, "Android");

	scores.push_back(cppScore);
	scores.push_back(algoScore);
	scores.push_back(javaScore);
	scores.push_back(dataCommScore);
	scores.push_back(androidScore);

	/*
	size_t size = scores.size();
	for (size_t i = 0; i < size; ++i)
	{
		delete scores[i];
	}
	*/

	auto it = scores.begin();
	//vector<Score>::iterator it = scores.begin();
	int findingValue = 30;
	while (it != scores.end())
	{
		Score* score = *it;
		if (score->GetScore() == findingValue)
		{
			it = scores.erase(it);
		}
		else
		{
			it++;
		}
	}

	for (auto iter = scores.begin(); iter != scores.end(); ++iter)
	{
		delete *iter;
	}
	/*
	delete cppScore;
	delete algoScore;
	delete javaScore;
	delete dataCommScore;
	delete androidScore;
	*/

}

void MySmartPointerTest()
{
	std::unique_ptr<int> myPtr(new int(15));
	std::unique_ptr<int> myPtr2 = std::make_unique<int>(10);
	std::shared_ptr<vector<int>> mySharedPtr = make_shared<vector<int>>(15);
	std::shared_ptr<map<std::string, int>> mySaredPtr2 = make_shared<map<std::string, int>>();

}

void MyLambdaTest()
{
	int a = 23;
	int b = 34;
	int myInt2 = 0;
	auto myInt = [&]() { return a + b; };
	auto myLambda = [=, &myInt2]()
	{ 
		myInt2 = a + b; 
		++myInt2;
	};
	myLambda();
	cout << myInt2 << endl;

}

void StringAddWithTemplateTest()
{
	string s1 = "Hello";
	string s2 = "World";

	string s3 = Add(s1, s2);

}

int main()
{
	 _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	 for (int i = 0; i >= 0; i--)
	 {
		 cout << i << endl;
	 }

	 int aX = 16;

	 if ((aX & (aX - 1) ) == 0)
	 {
		 cout << "true" << endl;
		 
	 }
	 else
	 {
		 cout << "false" << endl;
	 }
	 auto bX = aX & (aX - 1);

	 

	 //FinalResultReview();
	 StringAddWithTemplateTest();
	 

	//TestExample1();
	//TestExample2(); // i really review this example.... it seems easy but actually tricky.
	//TestExample3();
	//TestExample4();
	//TestExample5();
	//TestExample6();
	//TestExample7();
	//TestExample8();
	//TestExample9();
	//TestExample10();
	//TestExample11();
	//TestExample12();
	//TestExample13();
	//TestExample14();
	//TestExample15();

	 

	//HashExample();
	//SimpleTemplateProgramming();
	//TestExtra2();

	//RangedForLoopExample();
	//MyfindFunction();
	//MyVectorInsertDeleteAtMiddle();
	 MySmartPointerTest();
	 //MyLambdaTest();



	/*
	std::map<std::string, int> myMap;
	myMap.insert(std::pair<std::string, int>("asdf", 12));
	myMap.insert(std::pair<std::string, int>("qwer", 212));
	myMap.insert(std::pair<std::string, int>("zxcv", 412));
	myMap.insert(std::pair<std::string, int>("ghjk", 512));
	myMap.insert(std::pair<std::string, int>("bnml", 412));

	auto iter = myMap.find("ghjk");
	*/
	 /*
	 int A;
	 int B;
	 std::string str;
	 cin >> A;
	 cin >> B;
	 
	 while (!cin.eof())
	 {
		 cin >> A;

		 if (cin.fail())
		 {
			 cin.clear();
			 cin >> str;
		 }
	 }
	 */
	 


	std::list<int> myList;
	myList.assign(1, 2);
	
	

	//auto* aAuto = new std::vector<int>(5, 25);

	//char char1 = '\'

	/*
	std::string simpleString = "\\    /\\";
	cout << simpleString << endl;

	cout << "|\\_/|" << endl;
	cout << "|q p|   /}" << endl;
	cout << "( 0 )\"\"\"\\" << endl;
	cout << "|\" ^ \"`    |" << endl;
	cout << "||_/=\\\\__|" << endl;





	int SimpleArray[10];
	for (size_t i = 0; i < 10; ++i)
	{
		SimpleArray[i] = i;
	}

	cout << (sizeof(SimpleArray) / sizeof(SimpleArray[0])) << endl;
	memset(SimpleArray, 0, sizeof(SimpleArray));
	cout << (sizeof(SimpleArray) / sizeof(SimpleArray[0])) << endl;




	//int8_t someInt;
	//uint8_t someUInt;
	//int32_t someInt2;


	std::vector<int> scores(10);
	std::vector<int> scores2;
	
	scores2.reserve(10);

	std::vector<int> scores3;

	scores3.reserve(5);
	scores3.push_back(15);
	scores3.push_back(16);
	scores3.push_back(17);
	scores3.push_back(18);
	scores3.push_back(19);

	scores3.reserve(3);
	scores.pop_back();
	scores.resize(4);
	scores.reserve(2);
	scores.shrink_to_fit();

    std::cout << "Hello World!\n";
	*/

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
