#include <iostream>

enum Sample : unsigned char
{
	A = 5,
	B, //6
	C //7
};

int main()
{
	Sample sample = B;

	if(sample == 6)
	{
		std::cout<<"Its sample B"<<std::endl;
	}

	return 0;
}
