#pragma once
#include <functional>
#include <string>
#include <unordered_set>
#include <unordered_map>


namespace final
{

	struct S
	{
		std::string first_name;
		std::string last_name;
	};

	bool operator==(const S& lhs, const S& rhs)
	{
		return lhs.first_name == rhs.first_name && lhs.last_name == rhs.last_name;
	}

	struct MyHash
	{
		std::size_t operator() (S const& s) const noexcept
		{
			std::size_t h1 = std::hash<std::string>{}(s.first_name);
			std::size_t h2 = std::hash<std::string>{}(s.last_name);

			return h1 ^ (h2 << 1);
		}
	};


}

