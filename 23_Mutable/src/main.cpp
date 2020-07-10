#include <iostream>

class Entity
{
	public:
		const std::string& GetName() const
		{
			std::cout<<"count = "<<++count<<std::endl; //const methods can modify mutable variables
			return m_Name;
		}

		const int& getCount()
		{
			return count;
		}

		Entity():m_Name("name")
		{

		}

	private: 
	 	std::string m_Name;
		mutable int  count = 0; //const methods can change this member variable.
};

int main()
{
	const Entity e;
	e.GetName();
	e.GetName();

	int x = 8;

	std::cout<<"X  = "<<x<<std::endl;

	//lambda (pass by value =, pass by ref &)
	auto f = [=]() mutable
	{
		x++; //read only varaible if not used mutable
		std::cout<<"X inside lambda = "<<x<<std::endl;
	};

	f();

	std::cout<<"X outside lambda = "<<x<<std::endl;

	return 0;
}
