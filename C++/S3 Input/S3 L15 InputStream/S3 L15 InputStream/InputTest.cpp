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
		// �����߿� �޸𸮿� �󸶳� �Ҵ�Ǿ��ִ��� �� ���� ����.
		// string ���� �ڿ� Ư���� string.. nullstring�� �־ Ȯ���Ѵ�.
		// ���� �ڵ�� [P] [O] [P] [E] [NULL] �̷��� ����ִµ� firstName[4], 5��°�� �ҷ��� �� �����ϴ�.
		// �ذ����� firstName[5]�� ����ִ� �� �̷��� �� ��� [P][O][P][E][\0] �̷��� �� �������� �ν�Ʈ����
		//�� �� �ִ�.

		// scanf()�� ���˻縦 ���� �ʴ´�!

		char firstName2[4];
		cin >> firstName2;
		// �̰͵� scanf��ŭ �����ϴ�.

		char firstData[512];
		int secondData;

		cin >> firstData >> secondData;
		// ������ ���!

	}
}