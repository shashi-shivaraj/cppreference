#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> values = {3,5,1,4,2};

	std::sort(values.begin(),values.end()); //will sort in ascending order
	std::cout<<"Ascending order"<<std::endl;
	for(int val : values)
	{
		std::cout<<val<<std::endl;
	}

	
	std::sort(values.begin(),values.end(),std::greater<int>()); //will sort in descending order
	std::cout<<"Decending order"<<std::endl;
	for(int val : values)
	{
		std::cout<<val<<std::endl;
	}

	std::sort(values.begin(),values.end(),[](int a, int b){
		if(a == 1)
		{
			return false; //move b to front
		}

		if(b == 1)
		{
			return true; //move a to front
		}

		return a < b; //return true to move to front

	}); //will sort in Ascending order
	std::cout<<"Ascending order with 1 moved to end using lambda"<<std::endl;
	for(int val : values)
	{
		std::cout<<val<<std::endl;
	}

	return 0;
}