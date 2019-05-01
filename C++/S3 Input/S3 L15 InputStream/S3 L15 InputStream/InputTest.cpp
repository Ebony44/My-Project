#include <iostream>
#include "InputTest.h"
#include "pch.h"


using namespace std;

namespace InputSample
{
	void InputSomething()
	{
		char firstName[20];
		cin >> firstName;

		int hours;
		cin >> hours;
		cout << "Today I studied for " << hours << " hours." << endl;

		float price;
		cin >> price;
		cout << "The price of this green tea is $" << price << "." << endl;


		//why scanf() is dangerous????
		//char firstName[4];
		//scanf("%s", firstName);
		// 실행중엔 메모리에 얼마나 할당되어있는지 알 수가 없다.
		// string 제일 뒤에 특수한 string.. nullstring을 넣어서 확인한다.
		// 위의 코드는 [P] [O] [P] [E] [NULL] 이렇게 집어넣는데 firstName[4], 5번째를 불러올 때 위험하다.
		// 해결방법은 firstName[5]로 잡아주는 것 이렇게 될 경우 [P][O][P][E][\0] 이렇게 맨 마지막에 널스트링이
		//들어갈 수 있다.

		// scanf()는 경계검사를 하지 않는다!

		char firstName2[4];
		cin >> firstName2;
		// 이것도 scanf만큼 위험하다.

		char firstData[512];
		int secondData;

		cin >> firstData >> secondData;
		// 안전한 방법!

	}
}