 #include <iostream>
 #include <cstring>

void increament (int* value)
{
	(*value)++; //dereference and then increment
}

void increament (int& value)
{
	value++;
}


int main(int argc , char* argv[])
{
	if(argc != 2)
	{
		std::cout<<"cmd line inputs invalid"<<std::endl;		
		return -1;
	}

	int value = std::atoi(argv[1]);

	int& ref = value; //reference of value

	std::cout <<"update the value to 2 using reference"<< std::endl;
	ref = 2;

	std::cout<<"value = "<<value<<std::endl;

	increament(&value);
	std::cout<<"incremented value using pointer = "<<value<<std::endl;
	
	increament(value);
	std::cout<<"incremented value using reference = "<<value<<std::endl;

	return 0;
}