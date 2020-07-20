#include <iostream>

namespace eden{ namespace func{

	void print (std::string str)
	{
		std::cout << str << std::endl;
	}
}}

namespace hazard{

	void print (std::string str)
	{
		std::cout << str <<" version2 "<< std::endl;
	}
}

int main()
{
	namespace e = eden::func;
	e::print("Eden Hazrad");
	hazard::print("Eden Hazrad");

	using namespace hazard;
	print("eden");

	using eden::func::print;
	print("eden");

	return 0;
}