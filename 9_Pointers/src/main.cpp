 #include <iostream>
 #include <cstring>

/*Pointer is just a memory address*/

int main(int argc , char* argv[])
{
	if(argc != 2)
	{
		std::cout<<"cmd line inputs invalid"<<std::endl;		
		return -1;
	}

	int *ptr = nullptr;
	int **doubleptr = nullptr;
	int value = std::atoi(argv[1]);
	int input =  value;
	ptr = &value;//memory address of the value

	std::cout<<"Pointer(memory address of the value : ptr = &value) = "<<ptr<<std::endl;
    std::cout<<"Value (*ptr) = "<<*ptr<<std::endl;

	std::cout<<"Changing the value to 10 (*ptr = 10) "<<std::endl;
	*ptr = 10;

	std::cout<<"Pointer(memory address of the value : &value) = "<<&value<<std::endl;
    std::cout<<"Value = "<<value<<std::endl;

	doubleptr = &ptr;
	std::cout<<"Double Pointer(memory address of the ptr) = "<<doubleptr<<std::endl;
	std::cout<<"Changing the value to input using double ptr (**doubleptr = input) "<<std::endl;
	**doubleptr = input;

	 std::cout<<"Value = "<<value<<std::endl;

	 char* buffer = new char[8];
	 strncpy(buffer, "AAAAAAAA", 8);

	 std::cout<<"char buffer = "<<buffer<<std::endl;

	 char**dptr = &buffer; 

	  strncpy(*dptr, "Abcdefgh", 8);

	  std::cout<<"mofified char buffer using *dptr = "<<buffer<<std::endl;

	  **dptr = 'a';

	   std::cout<<"mofified first char using **dptr = "<<buffer<<std::endl;

	   delete[] buffer; //clean up heap memory

	return 0;
}