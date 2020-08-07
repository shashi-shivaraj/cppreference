#include <iostream>

class String
{
	public: 
		String()
		{
			std::cout<<"Default Construct"<<std::endl;

		}

		String(const String& )
		{
			std::cout<<"Copy Construct"<<std::endl;
		}

		~String()
		{
			std::cout<<"Destruct"<<std::endl;

		}

		String& operator=(const String& )
		{
			std::cout<<"Copy assign"<<std::endl;
			return *this;
		}

		String(String&& )
		{
			std::cout<<"Move Construct"<<std::endl;
		}

		String& operator=(String&& )
		{
			std::cout<<"Move assign"<<std::endl;
			return *this;
		}
};

String rvo()
{
	return String();
}

int main()
{
	rvo(); 
	// With -fno-elide-constructors in make and no move semantics :: default-copy-destruct-destruct
	// With -fno-elide-constructors in make and with move semantics :: default-move-destruct-destruct
	// Without -fno-elide-constructors in make we get default-destruct

	return 0;
}
