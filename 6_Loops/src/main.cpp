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
		std::cout << "For loop Count = "<< i <<std::endl;
	}

	int j = 0; 

	while(j < count)
	{
		std::cout << "While loop Count = "<< j <<std::endl;
		j++;
	}

	do
	{
		std::cout << "Do While loop Count = "<< j <<std::endl;
		j++;

	}while(j<count);

	return 0;
}