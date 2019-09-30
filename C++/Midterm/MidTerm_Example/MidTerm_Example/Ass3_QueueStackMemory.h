#pragma once

#include <cmath>
#include <limits>
//#include <iostream>
#include <stack>
#include <queue>

#include "CustomMath.h"

using std::stack;
using std::queue;

namespace assignment3
{
	template <typename T>
	class QueueStack
	{
	public:

		QueueStack(unsigned int maxStackSize);
		/*
		virtual ~QueueStack();
		QueueStack(const QueueStack& other);
		QueueStack& operator=(const QueueStack& other);


		void Enqueue(T number);
		T Peek() const;
		T Dequeue();

		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();

		unsigned int GetCount();
		unsigned int GetStackCount();
		*/

		queue<stack<T>> mQueueStack;
	private:



		//queue<T> mCompleteQueue;

		//stack<T> mStandbyStack;

		


		// 2 ways
		// 1. grab last stack in member variable
		// 2. make new queue every Enqueue()

		//stack<T> mLastStack;

		// right now: push it after full stack
		// change to: push first and save it

		unsigned int mMaxStackSize;

		// guess mCurrentStackSize is removable

		//size_t mCurrentStackSize;

		// actually stackCount is removable too
		//size_t mStackCount;
		//size_t mDequeuedCount;

	};


	template <typename T> QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
	{
		stack<T> tempStack;
		tempStack.push(maxStackSize);
		mQueueStack.push(tempStack);
	}

	template <typename T>
	class QueueStackMinimalized
	{
	public:

		QueueStackMinimalized(unsigned int maxStackSize);
		/*
		virtual ~QueueStackMinimalized();
		QueueStackMinimalized(const QueueStackMinimalized& other);
		QueueStackMinimalized& operator=(const QueueStackMinimalized& other);


		void Enqueue(T number);
		T Peek() const;
		T Dequeue();

		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();

		unsigned int GetCount();
		unsigned int GetStackCount();
		*/

		queue<T> mCompleteQueue;

		stack<T> mStandbyStack;
	private:



		

		//queue<stack<T>> mQueueStack;


		// 2 ways
		// 1. grab last stack in member variable
		// 2. make new queue every Enqueue()

		//stack<T> mLastStack;

		// right now: push it after full stack
		// change to: push first and save it

		unsigned int mMaxStackSize;

		// guess mCurrentStackSize is removable

		//size_t mCurrentStackSize;

		// actually stackCount is removable too
		//size_t mStackCount;
		//size_t mDequeuedCount;

	};

	template <typename T> QueueStackMinimalized<T>::QueueStackMinimalized(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
	{
		mStandbyStack.push(maxStackSize);
	}

}