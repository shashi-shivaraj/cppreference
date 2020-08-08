#include <iostream>
#include <cstring>

/*Rule of Three : If a class requires a user-defined destructor,
a user-defined copy constructor, or a user-defined copy assignment operator,
it almost certainly requires all three.*/

//If the class contains any data pointer apply rule of three; (To prevent shallow copy)

//The class which allocates the memory should free the memory

class String
{
	public:
	
	String(const char* str):data(new char[std::strlen(str)]),data_len(std::strlen(str)) 
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

	private:
		char* data;
		int data_len;
};

int main()
{
	String str("Eden Hazrad"); //user defined constructor called

	String copyStr(str); //copy constructor called

	String copyAssignStr("default");
	copyAssignStr = str;	//copy assignment is called

	return 0;
}