#include <iostream>

/*Classes that have custom destructors, copy/move constructors or copy/move assignment operators
 should deal exclusively with ownership.
 Other classes should not have custom destructors, copy/move constructors or copy/move assignment operators.*/

//Classes without pointers/memory operations should use compiler defaults.

class Entity
{
	public :

	void setData(const int& val)
	{
		data = val;
	}

	const int& getData()
	{
		return data;
	}

	//Uncomment if you want to use the custom definations rather than compiler generated ones
	/*
	Entity():data(0)
	{
		std::cout<<"Default Constructor called"<<std::endl;
	}

	Entity(const Entity& other):data(other.data)
	{
		std::cout<<"Copy constructor called"<<std::endl;
	}

	Entity(const Entity&& other):data(other.data)
	{
		std::cout<<"Move constructor called"<<std::endl;
	}

	const Entity& operator = (const Entity& other)
	{
		std::cout<<"Copy assignment called"<<std::endl;
		data = other.data;
		return *this;
	}

	const Entity& operator = (const Entity&& other)
	{
		std::cout<<"Move assignment called"<<std::endl;
		data = other.data;
		return *this;
	}

	~Entity()
	{
		std::cout<<"Default destructor called"<<std::endl;
	}*/

	private:
		int data;
};

int main()
{
	Entity one;  //compiler generated default constructor
	one.setData(5);
	std::cout<<"one data = "<< one.getData() <<std::endl;

	Entity two(one); //compiler generated copy constructor
	std::cout<<"two data = "<< two.getData() <<std::endl;

	Entity three; 
	three = one; //compiler generated copy assignment
	std::cout<<"three data = "<< three.getData() <<std::endl;

	Entity four(std::move(one)); //compiler generated move constructor
	std::cout<<"four data = "<< four.getData() <<std::endl;

	Entity five; 
	five = std::move(one); //compiler generated move assignment
	std::cout<<"five data = "<< five.getData() <<std::endl;
	
	return 0;
}

/* When a base class is intended for polymorphic use, its destructor may have to be declared public and virtual. 
This blocks implicit moves (and deprecates implicit copies), and so the special member functions have to be declared as defaulted[2]*/
class base_of_five_defaults
{
 public:
    base_of_five_defaults(const base_of_five_defaults&) = default;
    base_of_five_defaults(base_of_five_defaults&&) = default;
    base_of_five_defaults& operator=(const base_of_five_defaults&) = default;
    base_of_five_defaults& operator=(base_of_five_defaults&&) = default;
    virtual ~base_of_five_defaults() = default;
};