#include <iostream>
#include <cstring>

//std::move is used to convert an object to be temporary.


class String
{
	public:

	String():data(nullptr),m_size(0)
	{}

	String(const char* str):data(nullptr),m_size(0)
	{
		std::cout<<"created"<<std::endl;
		m_size = strlen(str);
		data = new char[m_size];
		memcpy(data, str, m_size);
	}

	~String()
	{
		if(data)
		{
			std::cout<<"deleted"<<std::endl;
		}

		delete [] data;
	}

	//copy constructor
	String(const String& other):data(nullptr),m_size(0)
	{
		std::cout<<"Copied"<<std::endl;
		m_size = other.m_size;
		data = new char[m_size];
		memcpy(data, other.data, m_size);
	}

	//move constructor
	String(String&& other):data(nullptr),m_size(0)
	{
		std::cout<<"moved"<<std::endl;
		m_size = other.m_size;
		data = other.data;

		other.data = nullptr;
		other.m_size = 0;
	}

	//move assignment
	String& operator = (String&& other)
	{
		std::cout<<"move assign"<<std::endl;

		if(this == &other)
		{
			return *this;
		}

		delete []data;

		m_size = other.m_size;
		data = other.data;

		other.data = nullptr;
		other.m_size = 0;

		return *this;
	}


	void Print()
	{
		for(unsigned int i =0 ; i < m_size; i++ )
		{
			std::cout<<data[i];
		}
		std::cout<<std::endl;
	}

	private :
		char* data;
		unsigned int m_size;
		
		operator=(const String&);
};

class Entity
{
	public:
		Entity(const String& name):m_Name(name)
		{

		}

		//takes temp string
		Entity(String&& name):m_Name(std::move(name))
		{
			
		}

		void PrintName()
		{
			m_Name.Print();
		}

	private:
		String m_Name;

};

int main()
{
	{
		Entity e = Entity("Eden Hazrad");
		e.PrintName();
	}

	std::cout<<"------------------"<<std::endl;
	{
		String string = "Hello";
		String dest = string;
	}
	
	std::cout<<"------------------"<<std::endl;
	{
		String stringMove = "Hello";
		String destMove = std::move(stringMove); // This will call move constructor
	}

	std::cout<<"------------------"<<std::endl;
	{
		String stringMoveAssignment = "Hello";
		String destMoveAssignment;

		destMoveAssignment = std::move(stringMoveAssignment); //this will call move assignment
		destMoveAssignment.Print();

		stringMoveAssignment.Print();
	}

	return 0;
}
