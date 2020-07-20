#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

//[captures =,&](args){ body}
//use lambda for a disposible function instead of a function

//std::function<ret_type(args)> instead of function pointers

typedef int (*PrintFuncPtr)(std::string, int);

void PrintVector(std::vector<int> &vec,const std::function<int(std::string, int)>& ptr)
{
	for(int i : vec)
	{
		ptr("Print", i);
	}
}

int main()
{
	int a = 5; //pass a by reference in lambda

	std::vector<int> vec = {1,2,3};
	PrintVector(vec,[&](std::string str,int ret){std::cout<<str<<" "<<ret<<" "<<a<<std::endl;return ret;});

	//use of lambda to find the first element greater than 1
	auto it = std::find_if(vec.begin(),vec.end(),[](int val){return val > 2;});

	std::cout<<*it<<std::endl;

	return 0;
}