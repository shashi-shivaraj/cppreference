#include <iostream>
#include <cstdlib>

//new : delete is similar to malloc(sizetotalbytes) : free
//calloc(nums, size of one in bytes) similar to malloc bit will init memeory to 0
//realloc(*origptr,sizetotalbytes) 

int main()
{
	int *x = new int; //memory to store 1 int
	int *xMalloc = static_cast<int*> (std::malloc(sizeof(int)));

	delete x;
	free(xMalloc);

	int *arr = new int[100]; //memeory to store 100 ints
	int *arrMalloc = (int*)std::malloc(sizeof(int) * 100);

	delete [] arr;
	free(arrMalloc);

	//calloc initializes all the elements to zero
	double *darr = (double*) std::calloc(100 ,sizeof(int)); //(num of elements, size of element)

	//realloc - resize allocation
	double *relocArr;
	relocArr = (double*) std::realloc(darr,sizeof(int)*500);
	if(!relocArr)
	{
		//original pointer still valid
		std::cout<<"realloc unsuccessful free original ptr"<<std::endl;
		std::free(darr);
		darr = nullptr;
	}
	else
	{
		std::cout<<"realloc successful"<<std::endl;
		free(relocArr);
		relocArr = nullptr;
	}	

	return 0;
}
