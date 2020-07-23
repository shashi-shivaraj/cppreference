#include <iostream>

int main()
{
	//1D array
	int* array = new int[5]; //1D array of int

	//access
	array[0] = 2;

	//delete
	delete [] array;

	//2D array
	int** array2D = new int*[5]; //1D array of pointers
	for(int i = 0;i< 5;i ++)
	{
		array2D[i] = new int[5]; 
	}

	//access
	array2D[0][0] = 2;

	//delete 2D
	for(int i = 0;i< 5;i ++)
	{
		delete[] array2D[i]; 
	}
	delete[] array2D;

	//3D array
	int*** array3D = new int**[5]; //1D array of pointers
	for(int i = 0;i< 5;i ++)
	{
		array3D[i] = new int*[5];
		for(int j = 0; j < 5; j++)
		{
			array3D[i][j] = new int[5];

			//or 
			//int** ptr = array3D[i];
			//ptr[j] = new int[5];
		} 
	}

	//access
	array3D[0][0][0] = 2;

	//delete 2D
	for(int i = 0;i< 5;i ++)
	{
		for(int j = 0; j < 5; j++)
		{
			delete[] array3D[i][j];
		} 
		
		delete[] array3D[i];
	}
	delete[] array3D;

	// above methods cause memory fragmentation 

	//2D array
	int** Opti2DArray = new int*[5]; //1D array of pointers
	Opti2DArray[0] = new int [5*5]; //allocate all the memory to first index
	for(int i = 1;i< 5;i ++)
	{
		Opti2DArray[i] = &Opti2DArray[0][i*5]; //upate the pointers address from index 0
	}

	int count = 0;
	for(int i = 0;i< 5;i ++)
	{
		for(int j = 0;j< 5;j ++)
		{
			Opti2DArray[i][j] = count++;
			std::cout<< Opti2DArray[i][j] <<"\t";
		}
		std::cout<<std::endl;
	}

	std::cout<<Opti2DArray[4][2]<<std::endl; //access using reference pointers
	std::cout<<Opti2DArray[0][22]<<std::endl; //acess using pointer at index 0

	//delete 2D

	delete[] Opti2DArray[0]; 
	delete[] Opti2DArray;

	return 0;
}
