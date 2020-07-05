#include <iostream>

int main(int argc , char* argv[])
{
	if(argc != 2)
	{
		std::cout<<"cmd line inputs invalid"<<std::endl;		
		return -1;
	}

	int x = std::atoi(argv[1]);

	bool compres = x == 5;

	if(compres)
	{
		std::cout<<"X is 5"<<std::endl;
	}
	else if(7 == x)
	{
		std::cout<<"X is 7"<<std::endl;
	}
	else
	{
		std::cout<<"X is not 5 or 7"<<std::endl;
	}

	return 0;
}