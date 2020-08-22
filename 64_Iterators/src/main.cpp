#include <iostream>
#include <vector>

#include <unordered_map>

int main()
{
	std::vector<int> values = {1,2,3,4,5};

	for(int i: values) //range based for loop
	{
		std::cout<<i;
	}

	std::cout<<std::endl;

	for(std::vector<int>::iterator it = values.begin();it != values.end();it++) //iterators for vector
	{
		std::cout<<*it;
	}

	std::cout<<std::endl;

	using ScoreMap = std::unordered_map<std::string, int>;
	ScoreMap map;
	map["eden"] = 2;
	map["hazard"] = 7;

	for(ScoreMap::const_iterator it = map.begin();it != map.end();it ++)//iterators for map
	{
		std::cout<<it->first<<" = "<<it->second<<std::endl;
	}

	for(auto [key,val] : map)//structured bindings c++ 17
	{
		std::cout<<key<<" = "<<val<<std::endl;
	}
}