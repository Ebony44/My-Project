#pragma once

#include <cmath>


namespace assignment3
{
	double RoundMath(double paramDouble)
	{
		double tempDouble = 0;
		if (paramDouble >= 0)
		{
			// 12.666666666 
			// ->
			// 12.667

			// 12666.666
			tempDouble = floor((paramDouble * 1000) + 0.5) / 1000;
			return tempDouble;
		}
		else
		{
			// -12.666666
			// -12.444444
			//
			tempDouble = floor((paramDouble * -1) * 1000 + 0.5) / 1000;
			tempDouble *= -1;
			return tempDouble;
		}
	}
}

