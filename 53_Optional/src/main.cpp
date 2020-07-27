#include <iostream>
#include <fstream>
#include <optional>

std::optional<std::string> ReadFile(const std::string& filepath)
{
	std::ifstream stream(filepath);
	if(stream)
	{
		std::string result, line;
		//read file
		while (getline (stream, line))
		 {	
			 result += line;
		 }

		stream.close();
		return result;
	}

	return {}; //empty std::optional
}

int main()
{
	std::optional<std::string> data = ReadFile("data.txt");
	if(data)
	{
		std::cout<<"File opened"<<std::endl;
	}
	else
	{
		std::cout<<"File cannot be opened"<<std::endl;
	}

	std::string value = data.value_or("empty data"); //data or alternative
	std::cout<<value<<std::endl;

	return 0;
}
