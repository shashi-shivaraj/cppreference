 #include <iostream>

int main(int argc , char* argv[])
{
	if(argc != 2)
	{
		std::cout<<"cmd line inputs invalid"<<std::endl;		
		return -1;
	}

	int count = std::atoi(argv[1]);

	for(int i = 0; i < count; i++)
	{
		if(i % 2 == 0)
		{
			continue;
		}

		if(i > 10)
		{
			break;
		}

		std::cout << "For loop Count = "<< i <<std::endl;
	}

	if(count > 10)
	{
		return -1;
	}

	std::cout << "Looping complete" << std::endl;

	return 0;
}