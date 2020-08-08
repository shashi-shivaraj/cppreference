#include <iostream>
#include <cstring>
#include <utility>

/*Rule of Five : If a class requires a user-defined destructor,
a user-defined copy constructor, or a user-defined copy assignment operator,
it prevents implicit definition of the move constructor and the move assignment operator.
Any class for which move semantics are desirable, has to declare all five special member functions.*/

//If the class contains any data pointer apply rule of three; (To prevent shallow copy);
//The compiler will not automatically generate the move constructor and move assignment
//If move semantics is required then apply rule of five;

//The class which allocates the memory should free the memory

class String
{
	public:
	
	String(const char* str):data(new char[std::strlen(str)+1]),data_len(std::strlen(str)+1) 
	{
		std::cout<<"User defined constructor called"<<std::endl;
		std::strncpy(data,str,data_len);
	}

	~String()
	{
		std::cout<<"Destructor called"<<std::endl;
		delete [] data;
		data_len = 0;
 	}

	String(const String& other):data(new char[other.data_len]),data_len(other.data_len) 
	{
		std::cout<<"Copy constructor called"<<std::endl;
		std::strncpy(data,other.data,data_len);
	}

	String(String&& other):data(std::exchange(other.data,nullptr)),data_len(other.data_len) 
	{
		std::cout<<"move constructor called"<<std::endl;
	}

	const String& operator=(const String& other)
	{
		std::cout<<"Copy assignment called"<<std::endl;
		if(this == &other)
		{
			return *this;
		}

		if(data)
		{
			std::cout<<"freeing memory"<<std::endl;
			delete [] data;
			data_len = 0;
		}

		data_len = other.data_len;
		data = new char[data_len];
		std::strncpy(data,other.data,data_len);
		
		return *this;
	}

	const String& operator=(String&& other)
	{
		std::cout<<"move assignment"<<std::endl;
		std::swap(data,other.data);

		return *this;
	}

	const char* getData()
	{
		return data;
	}

	private:
		char* data;
		int data_len;
};

int main()
{
	{
		String str("Eden Hazrad"); //user defined constructor called
		std::cout<<str.getData()<<std::endl;
	}

	std::cout<<"----------------------------------"<<std::endl;

	{
		String str("Eden Hazrad"); //user defined constructor called
		String copyStr(str); //copy constructor called
		std::cout<<copyStr.getData()<<std::endl;
	}

	std::cout<<"----------------------------------"<<std::endl;

	{
		String str("Eden Hazrad"); //user defined constructor called
		String copyAssignStr("default"); //user defined constructor called
		copyAssignStr = str;	//copy assignment is called
		std::cout<<copyAssignStr.getData()<<std::endl;
	}

	std::cout<<"----------------------------------"<<std::endl;
	
	{
		String str("Eden Hazrad"); //user defined constructor called
		String moveStr(std::move(str)); //move constructor is called
		std::cout<<moveStr.getData()<<std::endl;
	}

	std::cout<<"----------------------------------"<<std::endl;
	
	{
		String moveAssignStr("default"); //user defined constructor called
		moveAssignStr = "Hazard";	//user defined constructor + move assignment is called
		std::cout<<moveAssignStr.getData()<<std::endl;
	}

	std::cout<<"----------------------------------"<<std::endl;

	return 0;
}