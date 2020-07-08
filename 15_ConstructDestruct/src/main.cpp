#include <iostream>

//constructor is a method which gets executed every time we instantiate an object.  
//destructor is amethod which gets executed evry time we destroy an object.

class Entity
{
private:	
	float x, y;

public:

	//Default constructor with initialization
	Entity():x(0),y(0)
	{
		std::cout<<"Default construct called"<<std::endl;
	}

	//User defined constructor with initialization
	Entity(const float& x1,const float& y1):x(x1),y(y1)
	{
		std::cout<<"User defined construct called"<<std::endl;

	}

	~Entity()
	{
		std::cout<<"Entity Destructor is called"<<std::endl;
	}

	void print()
	{
		std::cout<<"x = "<<x<<" ,y = "<<y<<std::endl;
	}
};

class Log
{	
	public:
		Log() = delete; //or move the constructor to private to prevent object instantiation

	static void Write()
	{
		std::cout<<"Log Write called"<<std::endl;
	}

	~Log() //will never be called,since it cannot be instanstiated
	{
		std::cout<<"Entity Destructor is called"<<std::endl;
	}
};

int main()
{
	Entity entity1;
	entity1.print();	

	Entity entity2(2, 2);
	entity2.print();

	//Log log; //compilation error due to private default construct
	Log::Write();

	return 0;
}
