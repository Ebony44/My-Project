#pragma once
#include <string>
#include <vector>


namespace final
{
	template<typename T, size_t N>
	class SimpleTemplateProgramming1
	{
	public:
		SimpleTemplateProgramming1(size_t n);
		virtual ~SimpleTemplateProgramming1() = default;

		SimpleTemplateProgramming1(const SimpleTemplateProgramming1& other);
		SimpleTemplateProgramming1(SimpleTemplateProgramming1&& other) = default;

		SimpleTemplateProgramming1& operator=(const SimpleTemplateProgramming1& rhs);
		SimpleTemplateProgramming1& operator=(SimpleTemplateProgramming1&& rhs) = default;

		T Add(T t1, T t2);
		T Abstract(T t1, T t2);

	private:
		T mArray[N];



	};

	template<typename T, size_t N>
	SimpleTemplateProgramming1<T, N>::SimpleTemplateProgramming1(size_t n)
	{
	}


	template<typename T, size_t N>
	SimpleTemplateProgramming1<T, N>::SimpleTemplateProgramming1(const SimpleTemplateProgramming1& other)
	{
		mArray = other.mArray;
		//memcpy(mName, other.mName, strlen(other.mName) + 1);
	}


	template<typename T, size_t N>
	T SimpleTemplateProgramming1<T, N>::Add(T t1, T t2)
	{
		return t1 + t2;
	}

	template<typename T, size_t N>
	T SimpleTemplateProgramming1<T, N>::Abstract(T t1, T t2)
	{
		return t1 - t2;
	}


	template<size_t N>
	class SimpleTemplateProgramming1<int, N>
	{
	public:
		SimpleTemplateProgramming1(int interger, size_t n);
		virtual ~SimpleTemplateProgramming1() = default;
		int Add(int interger1, int integer2);
		int Abstract(int interger1, int integer2);
		double Divide(int interger1, int integer2);
	private:
		int mArray[N];
		int mInitialNum;
	};

	template<size_t N>
	SimpleTemplateProgramming1<int, N>::SimpleTemplateProgramming1(int interger, size_t n)
		: mInitialNum(interger)
	{
		for (size_t i = 0; i < N; ++i)
		{
			mArray[i] = 0;
		}
	}

	template<size_t N>
	int SimpleTemplateProgramming1<int, N>::Add(int interger1, int integer2)
	{
		return interger1 + integer2;
	}

	template<size_t N>
	int SimpleTemplateProgramming1<int, N>::Abstract(int interger1, int integer2)
	{
		return interger1 + integer2;
	}

	template<size_t N>
	double SimpleTemplateProgramming1<int, N>::Divide(int interger1, int integer2)
	{
		if (integer2 != 0)
		{
			return interger1 / integer2;
		}

		return 0;

	}


}