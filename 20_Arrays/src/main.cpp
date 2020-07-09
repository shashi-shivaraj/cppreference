#include <iostream>
#include <array> //required for standard array in c++ 11

//array index starts at 0;
//array data is contigious in memory

int main()
{
	int arr [5]; //allocated at stack

	std::cout<< "count of arr = "<<sizeof(arr)/sizeof(int)<<std::endl;

	for(int i = 0 ; i < 5 ; i++)
	{
		arr[i] = i;
		std::cout <<" arr at "<< i <<" = "<< arr[i] <<std::endl;
	}  

	int* ptr  = arr; //arrays are basically pointers

	*(ptr + 4) = 22; //update last value
	std::cout << " arr[4] = "<< arr[4] <<std::endl;

	int* newarr = new int[3]; //allocated at heap

	for(int i = 0 ; i < 3 ; i++)
	{
		newarr[i] = i+10;
		std::cout <<" newarr at "<< i <<" = "<< newarr[i] <<std::endl;
	}

	delete[] newarr; //clean up the heap memory

	std::array<int, 5> stdarr; //inbuilt array type

	for(unsigned int i = 0 ;i < stdarr.size() ; i++)
	{
		stdarr[i] = i * -1;	
		std::cout <<" stdarr at "<< i <<" = "<< stdarr[i] <<std::endl;
	}

	return 0;
}
