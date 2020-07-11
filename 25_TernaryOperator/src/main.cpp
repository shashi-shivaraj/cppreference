#include <iostream>

int main(int argc, char* argv[])
{
	if(2 != argc)
	{
		std::cout<<"invalid arags : use ./run.exe int"<<std::endl;
		return -1;
	}

	std::string output = std::atoi(argv[1]) % 2 ? "Number is Odd": "Number is Even";

	std::cout << output << std::endl;

	//can be used for nested if condition checks but not recommended due to readability
	std::string output1 =  std::atoi(argv[1]) % 2 ? std::atoi(argv[1]) > 0 ? "Number is Positive odd" : "Number is negative odd " : std::atoi(argv[1]) > 0 ? "Number is positive even" : "Number is negative even";

	std::cout << output1 << std::endl;

	return 0;
}
