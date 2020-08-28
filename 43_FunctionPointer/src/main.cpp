#include <iostream>
#include <vector>

//typedef return_type (*funcptr_name)(arg_types)
//Function pointer assigns a function to a variable  
//can be used to pass an function as argument

//Example 1:
typedef int (*PrintFuncPtr)(std::string, int);

int Print(std::string str, int ret)
{
	std::cout<<str<<" "<<ret<<std::endl;
	return ret;
}

void PrintVector(std::vector<int> &vec,PrintFuncPtr ptr)
{
	for(int i : vec)
	{
		ptr("Print", i);
	}
}

//Example 2
typedef int (*OperationFuncPtr)(int, int);

int sum(int x, int y)
{
	return x + y;
}

int mul(int x, int y)
{
	return x * y;
}

int doOperation(OperationFuncPtr fptr,int x, int y)
{
	return fptr(x,y);
}

int main()
{
	PrintFuncPtr funcptr = Print;

	funcptr("Eden",1);
	int ret = funcptr("Hazrad",7);

	std::cout<< ret <<std::endl;

	std::vector<int> vec = {1,2,3};
	PrintVector(vec,funcptr);

	std::cout<<"Adding 2 + 7 = " <<doOperation(sum,2,7)<<std::endl;
	std::cout<<"Multiply 2 * 7 = " <<doOperation(mul,2,7)<<std::endl;

	return 0;
}
