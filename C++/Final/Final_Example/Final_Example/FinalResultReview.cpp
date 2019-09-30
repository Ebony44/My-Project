
#include <algorithm>


#include <iostream>
#include <map>
#include <memory>
#include <vector>


using namespace std;

namespace final
{

	void Question1()
	{


		vector<int> v1;
		for (size_t i = 0; i < 10; ++i)
		{
			v1.push_back(i);
		}
		int x = 10;

		std::sort(v1.begin(), v1.end(), [=](int a, int b) { return x - a > x - b; });



	}

	void Question2()
	{
		// 3 8
		// 4 7
		// 5 6
	}

	void FinalResultReview()
	{

		Question1();


	}

	
}
