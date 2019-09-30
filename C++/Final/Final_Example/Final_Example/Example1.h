#pragma once

#include <vector>
#include <map>


namespace final
{
	template<typename T>
	class Example1
	{

	public:
		static std::vector<int> GetKeys(const std::map<int, char>& map);
	};


	template<typename T>
	std::vector<int> Example1<T>::GetKeys(const std::map<int, char>& map)
	{
		std::vector<int> v;

		for (auto iter = map.begin(); iter != map.end(); ++iter)
		{
			v.push_back(iter->first);
		}

		return v;
	}
}
