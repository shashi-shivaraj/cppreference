#include <iostream>

int multiply(int a, int b = 1)
{
	return a * b;
}

void MultiplyAndLog(int a, int b)
{
	int res = multiply(a, b);
	std::cout<<"Product  = "<< res <<std::endl;
}

int main()
{ 
	MultiplyAndLog(9,3);	
	MultiplyAndLog(7,13);

	std::cout<<multiply(5)<<std::endl;
}
