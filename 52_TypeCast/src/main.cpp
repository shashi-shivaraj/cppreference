#include <iostream>
#include <climits>

//static_cast<type>
//dynamic_cast<type> -- for cast along inheritence heirarchy
//const_cast<type> -- add/remove const
//reinterpret_cast<type> -- reinterpret into a different type

class Base
{
	public:
		Base()
		{
		}

		virtual ~Base()
		{
		
		}
};

class Derieved : public Base
{
	public:
		Derieved()
		{
		
		}

		void Print()
		{
			std::cout<<"Print"<<std::endl;
		}

		~Derieved()
		{
		
		}
};

class Other : public Base
{
	public:
		Other()
		{
		
		}

		~Other()
		{
		
		}
};


int main()
{
	double value = 5.25;
	double a = (int)value + 5.3; //cstyle cast

	double s = static_cast<int> (value); //c++ style cast

	std::cout<<"cstyle = "<< a <<std::endl;
	std::cout<<"static_cast = "<< s <<std::endl;

	std::cout<<"-------------------------"<<std::endl;

	int i = 3;
	const int& rci = i;
	const_cast<int&>(rci) = 4; //const_cast used to update const values

	std::cout<<"const_cast = "<< i <<std::endl;

	std::cout<<"-------------------------"<<std::endl;

	reinterpret_cast<unsigned int &>(i) = UINT_MAX;
    std::cout << "reinterpret_cast "<< i << '\n';

	std::cout<<"-------------------------"<<std::endl;

	Base* derieved = new Derieved();
	Base* other = new Other();

	//RTTI -Runtime type information is used
	Derieved* SuccessPtr = dynamic_cast<Derieved*>(derieved);
	if(SuccessPtr)
	{
		std::cout<<"Dynamic cast successful"<<std::endl;
		SuccessPtr->Print();
	}

	Derieved* FailurePtr = dynamic_cast<Derieved*>(other);
	if(FailurePtr == nullptr)
	{
		std::cout<<"Dynamic cast failed"<<std::endl;
	}

	delete derieved;
	delete other;
	
	return 0;
}
