#include <iostream>
#include <vector>

//typedef return_type (*funcptr_name)(arg_types)
//Function pointer assigns a function to a variable  
//can be used to pass an function as argument

int Print(std::string str, int ret)
{
	std::cout<<str<<" "<<ret<<std::endl;
	return ret;
}

typedef int (*PrintFuncPtr)(std::string, int);

void PrintVector(std::vector<int> &vec,PrintFuncPtr ptr)
{
	for(int i : vec)
	{
		ptr("Print", i);
	}
}

int main()
{
	PrintFuncPtr funcptr = Print;

	funcptr("Eden",1);
	int ret = funcptr("Hazrad",7);

	std::cout<< ret <<std::endl;

	std::vector<int> vec = {1,2,3};
	PrintVector(vec,funcptr);

	return 0;
}
