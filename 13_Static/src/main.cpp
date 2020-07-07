//static ouside class/struct : static.cpp
//static inside a class/struct : Entity class
//static in local scope : function_i()

#include "header.h"

int s_Variable = 10; //global variable

struct Entity
{
	static int x,y; //only one instance these variables across all instances of this class.
	int x1,y1;

	static void PrintStatic() //static method
	{
		std::cout<<"Static vars x = "<<x<<" , y = "<<y<<std::endl;
	}

	void Print()
	{
		std::cout<<"Non-Static vars x1 = "<<x1<<" , y1 = "<<y1<<std::endl;
	}
};

void function_i()
{
	static int i = 0; //local static varaible
	i++;
	std::cout<<"Printing static i value = "<<i<<std::endl; 
}


//static variables need to be defined
int Entity::x;
int Entity::y;


int main()
{
	std::cout << "Global variable = " << s_Variable << std::endl;
	function();

	Entity e;
	Entity::x = 2;
	Entity::y = 3;
	e.x1 = 4;
	e.y1 = 5;

	std::cout<<"Printing e"<<std::endl;
	e.PrintStatic();
	e.Print();

	Entity e1;
	Entity::x = 6;
	Entity::y = 7;
	e1.x1 = 8;
	e1.y1 = 9;
	

	std::cout<<"Printing e1"<<std::endl;
	Entity::PrintStatic();
	e1.Print();

	std::cout<<"Printing e again"<<std::endl;
	Entity::PrintStatic();
	e.Print();

	function_i();
	function_i();
	function_i();

	return 0;
}