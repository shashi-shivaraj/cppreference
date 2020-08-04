#include <iostream>
#include <string_view>

void PrintName(const std::string_view& name)
{
	std::cout<< name <<std::endl;
}

int main()
{
	const char* name = "Eden Hazrad";

	std::string_view fname(name, 4);
	std::string_view lname(name+5, 6);

	PrintName(fname);
	PrintName(lname); 
	
	return 0;
}
