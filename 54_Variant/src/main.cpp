#include <iostream>
#include <variant>

int main()
{
	std::variant<std::string, int> data;

	std::cout<<"Size of data = "<<sizeof(data)<<std::endl; //stores it as struct or class
	
	data = "string";
	if(auto value = std::get_if<std::string>(&data))
	{
		std::cout<<*value<<std::endl;
	}

	data = 2;
	if(std::get_if<int>(&data))
	{
		std::cout<<std::get<int>(data)<<std::endl;
	}

	if(data.index() == 1)
	{
		std::cout<<std::get<int>(data)<<std::endl;
	}

	return 0;
}
