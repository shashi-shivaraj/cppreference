#include <iostream>

//Make sure that the base class destructor is virtual,
//if that base class is going to be subclassed.

class Base
{
	public:
		Base()
		{
			std::cout<<"Base constructor"<<std::endl;
		}

		virtual ~Base()
		{
			std::cout<<"Base destructor"<<std::endl;
		}
};

class Derieved : public Base
{
	public:
		Derieved()
		{
			std::cout<<"Derieved constructor"<<std::endl;
		}

		void Print()
		{
			std::cout<<"Print"<<std::endl;
		}

		~Derieved()
		{
			std::cout<<"Derieved destructor"<<std::endl;
		}
};

int main()
{
	Base* base = new Base();
	delete base;

	std::cout<<"----------"<<std::endl;

	Derieved* derieved = new Derieved();
	derieved->Print();
	delete derieved;

	std::cout<<"----------"<<std::endl;

	Base* poly = new Derieved(); //needs virtual destructor
	//poly->Print(); not possible 
	delete poly;

	return 0;
}
