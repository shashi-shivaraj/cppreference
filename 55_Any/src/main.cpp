#include <iostream>
#include <any>

int main()
{
	std::any data;
	data = 2;
	data = "str";
	data = std::string("string");

	std::string& string = std::any_cast<std::string&>(data);
	std::cout<<string<<std::endl;

	try
	{
		int num = std::any_cast<int>(data);
		std::cout<<num<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout<<"any_cast threw = "<< e.what() <<std::endl;
	}
	

	return 0;
}
