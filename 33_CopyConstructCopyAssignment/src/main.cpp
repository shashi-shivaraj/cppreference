#include <iostream>
#include <cstring>

//copy constructor
//String(const String& other)

//copy assignment
//String& operator=(const String& other)

class String
{
	public:
		String(const char* str):m_buffer(nullptr),m_size(0)
		{
			std::cout<<"Constructor called"<<std::endl;
			m_size = strlen(str);
			m_buffer = new char[m_size+1];
			memcpy(m_buffer,str,m_size);
			m_buffer[m_size] = 0;		
		}

		//String(const String& other) = delete; //prevent copy

		//copy constructor
		String(const String& other):m_buffer(nullptr),m_size(other.m_size)
		{
			std::cout << "copy construct called" << std::endl;
			m_buffer = new char[m_size +1];
			memcpy(m_buffer, other.m_buffer, m_size+1);
		}

		//String& operator=(const String& other) = delete; //prevent copy assignment

		//copy assignment
		String& operator=(const String& other)
		{
			std::cout << "copy assignment called" << std::endl;

			if(&other == this)
			{
				return *this;
			}

			if(m_buffer)
			{
				delete[] m_buffer;
			}

			m_buffer = new char[m_size +1];
			memcpy(m_buffer, other.m_buffer, m_size+1);

			return *this;
		}

		~String()
		{
			std::cout<<"Destructor called with m_buffer = "<< static_cast <const void *> (m_buffer) <<std::endl;
			delete[] m_buffer;
		}

	friend std::ostream& operator<<(std::ostream& stream, const String& str); //friend can access pirvate members

	char& operator[](unsigned int index)
	{
		return m_buffer[index];
	}

	private:
		char* m_buffer;
		unsigned int m_size;
};

std::ostream& operator<<(std::ostream& stream, const String& str) 
{
	stream << str.m_buffer;
	return stream;
}

void PrintString(const String& str)
{
	std::cout<<str<<std::endl;
}

int main()
{
	{
		String str("Hazard");
		String temp = str;
		String temp2 = str;

		temp2[0] = 'E'; //temp2 will change due to deep copy

		temp = temp2; //temp will change due to deep copy
	
		PrintString(str);
		PrintString(temp);
		PrintString(temp2);
	}

	return 0;
}
