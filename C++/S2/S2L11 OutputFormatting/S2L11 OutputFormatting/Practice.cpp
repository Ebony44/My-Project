#include "pch.h"
#include "Practice.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace SampleOfFormatting
{
	void Formatting()
	{
		cout << "Hello World!\n";

		int number = 10;
		//in C, it's quite hard to read...
		//printf("%#x\n", number);

		cout << showbase << hex << number << endl;
		//showbase -> I'll show next input value
		//hex in Hexadecimal!
		//number next input value...

		cout << showpos << number;
		cout << noshowpos << number;
		//showpos -> show postivie number -> +10
		//noshowpos -> like normal output -> 10
		cout << dec << number;
		cout << hex << number;
		cout << oct << number;
		//10, 16, 8

		//uppercase
		cout << uppercase << hex << number; //7B
		cout << nouppercase << hex << number; //7b
		//Capital or not

		cout << showbase << hex << number << endl; // 0x7b
		cout << noshowbase << hex << number << endl; // 7b
		//showbase -> show the number's base...

		cout << setw(6) << left << number;     // |-123		|
		cout << setw(6) << internal << number; // |-	 123|
		cout << setw(6) << right << number;    // |		-123|
		//setw(columnValue) -> column's count.

		double decimal1 = 100.0;
		double decimal2 = 100.12;

		cout << noshowpoint << decimal1 << " " << decimal2; //100 100.12
		cout << showpoint << decimal1 << " " << decimal2; // 100.000 100.0120

		double number2 = 123.456789;
		cout << fixed << number2;	//123.456789
		cout << scientific << number2;//1.234568E+02

		bool bReady = true;
		cout << boolalpha << bReady;
		cout << noboolalpha << bReady;


		int number3 = 123;
		//#include <iomanip>
		//manipulator which in above!
		// setw() 
		// cout<<setw(5)<<number3 -> |  123|
		// 2 spaces before 123

		// setfill()
		cout << setfill('*') << setw(5) << dec << number3; //**123

		// setprecision()
		double number4 = 123.45678912;
		cout << " " << endl;
		cout << fixed << setprecision(5) << number4;
		//123.45679
		//round up!!!!!!!!!!!!!!
	}
	
}