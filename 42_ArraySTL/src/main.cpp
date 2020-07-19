#include <iostream>
#include <array>

template <typename T, unsigned int N>
void printArray(const std::array<T, N>& data)
{
	for(int i : data)
	{
		std::cout<<i<<std::endl;
	}
}

int main()
{
	int count = 0;

	//static array
	std::array<int, 5> data;

	data[0] = 2791;
	std::cout<<data[0]<<std::endl;

	for(int& i : data)
	{
		i = count++;
	}

	printArray(data);
	
 	return 0;
}
