#include "pch.h"
#include "PrintMenu.h"

#include <iostream>
#include <iomanip>


using namespace std;

namespace samples
{
	void PrintMenuExample()
	{
		cout << "+-----------------------------------------+" << endl;

		cout << "|---------Print Menu Example--------------|" << endl;

		cout << "+-----------------------------------------+" << endl;

		const float coffeePrice = 1.25f;
		const float latterPrice = 4.75f;
		const float breakfastComboPrice = 12.104f;

		const size_t nameColumnLength = 20;
		const size_t priceColumnLength = 10;

		cout << left << fixed << showpoint << setprecision(2);
		//left든 fixed 들어가는 순간 계속 영향을 미친다!!
		// whenever 'left' or 'fixed' inserted, it will affect til the end
		// or user manipulated that.

		cout << setfill('-') << setw(nameColumnLength + priceColumnLength) << "" << endl << setfill(' ');
		// the last setfill(' ') is for reset the output settings
		//
		cout << setw(nameColumnLength) << "Name"
			<< setw(priceColumnLength) << "Price" << endl;
		cout << setfill('-') << setw(nameColumnLength + priceColumnLength) << "" << endl << setfill(' ');

		cout << setw(nameColumnLength) << "Coffee"
			<< "$" << coffeePrice << endl;
		cout<<setw(nameColumnLength) << "Latte"
			<< "$" << coffeePrice << endl;
		cout << setw(nameColumnLength) << "Breakfast Combo"
			<< "$" << breakfastComboPrice << endl;
			
	}
}