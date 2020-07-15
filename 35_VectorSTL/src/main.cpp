#include <iostream>
#include <vector>

//std::vector - STL for dynamic array implementation.
//push_back() to add element, erase() to delete ,clear() deletes all elements but capacity remains
//pop_back() to remove last element 
//use reserve() to allocate the memory to prevent resize and copy
//use emplace_back() by passing args of the constructor.
//front() access first element, back() access last element

struct vertex
{
	float x, y, z;
	
	vertex(float x1, float y1, float z1):x(x1),y(y1),z(z1)
	{

	}

	vertex(const vertex& ver):x(ver.x),y(ver.y),z(ver.z)
	{
		std::cout<<"copy called"<<std::endl;
	}
};

std::ostream& operator<<(std::ostream& stream, const vertex& ver)
{
	stream << "x = " << ver.x << ", y = " << ver.y << ", z = " << ver.z;
	return stream;
}

void Func(const std::vector<vertex>& ver) //pass by reference
{
	for(unsigned int i = 0;i <ver.size(); i++)
	{
		std::cout << ver[i] <<std::endl;
	}
}

int main()
{
	std::vector<vertex> vertices;
	vertices.reserve(3); //reserve memory for 3 prevents unwanted resize and copy

	vertices.push_back({1,2,3}); //add to vector using copy
	vertices.emplace_back(4, 5, 6); //construct theelement in-place,with construct arguments
	vertices.emplace_back(7, 8, 9);

	Func(vertices); //pass by ref

	vertices.erase(vertices.begin() + 1); //erase 2nd element

	for(const vertex& v : vertices) //ranged for loop
	{
		std::cout << v <<std::endl;
	}

	vertices.clear(); //removes all the elements and size becomes 0
	std::cout << "size = "<<vertices.size()<<std::endl;
	
	return 0;
}