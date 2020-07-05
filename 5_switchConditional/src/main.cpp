#include <iostream>

int main(int argc , char* argv[])
{
	if(argc != 2)
	{
		std::cout<<"cmd line inputs invalid"<<std::endl;		
		return -1;
	}

	int x = std::atoi(argv[1]);

	switch(x)
	{
		case 5:
		{
			std::cout<<"X is 5"<<std::endl;
		}
		break;
		case 7:
		{
			std::cout<<"X is 7"<<std::endl;
		}
		break;
		case 8:
		case 9:
		{
			std::cout<<"X is 8 or 9"<<std::endl;
		}
		break;
		default:
		{
			std::cout<<"X is not 5,7,8, or 9"<<std::endl;	
		}
	}

	return 0;
}