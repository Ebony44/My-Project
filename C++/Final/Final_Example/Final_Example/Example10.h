#pragma once
#include <iostream>

// static_assert���� assert�� �ٲٱ� ���Ͽ�.
#include <cassert>

namespace final
{
	class Foo
	{
	public:
		Foo() = default;
		~Foo() = default;

		void BlackMagic(int x)
		{
			//static_assert(x < BLACK_MAGIC_CONST, "OMG");
			assert(x > BLACK_MAGIC_CONST);
			std::cout << x << std::endl;
		};
	private:
		static constexpr int BLACK_MAGIC_CONST = 3;

	};
}
