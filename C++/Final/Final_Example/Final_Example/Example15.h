#pragma once

#include <memory>
#include <iostream>


namespace final
{

}
class Example15
{
public:
	Example15(char c) : mC(c) {};
	//Example15(const Example15& other) = delete;
	Example15(const Example15& other) = default;
	~Example15() = default;
	char GetC() const { return mC; }


private:
	char mC;
};