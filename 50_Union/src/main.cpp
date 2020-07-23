#include <iostream>

struct vector2
{
	int x,y;
};

//both data and vec struct will have same memory.
struct vector4
{
	union
	{
		struct
		{
			int x,y,z,w;
		}data;

		struct
		{
			vector2 a;
			vector2 b;
		}vec;
	};
};

void PrintVec2(const vector2& vec)
{
	std::cout<< vec.x <<" , "<< vec.y <<std::endl;
}

int main()
{
	vector4 vec4 = {1, 2, 5, 4};
	PrintVec2(vec4.vec.a);
	PrintVec2(vec4.vec.b); //print vector2 elements

	vec4.data.x = 555; //access data element

	std::cout << "------------------"<<std::endl;
	PrintVec2(vec4.vec.a); 
	PrintVec2(vec4.vec.b);

	return 0;
}
