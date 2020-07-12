#include <iostream>

//The compiler can perform implicit conversion based on the contructor params;
//This implicit conversion can be prevented using explicit keyword

class Entity
{
	public:
		Entity(const std::string& name):m_name(name),m_age(-1)
		{

		}

		explicit Entity(const int& age):m_name("Unknown"),m_age(age) //implicit constructor conversion prevented.
		{ 

		}

		void Print() const
		{
			std::cout << "Name = " << m_name << " Age = " << m_age <<std::endl;
		}

	private: 
		std::string m_name;
		int m_age;
};

void PrintEntity(const Entity& e)
{
	//print something
	std::cout << "PrintEntity " <<std::endl;
	e.Print();
}

int main()
{
	Entity a = Entity("Hazard"); //method 1
	a.Print();

	Entity b(22); //method 1
	b.Print();

	Entity c = std::string("Eden"); //method 2 implicit conversion
	c.Print();

	//Entity d = 29; // not allowed due to explicit
	Entity d = Entity(29);
	d.Print();

	PrintEntity(std::string("Skill")); //method 2 implicit conversion 

	return 0;
}
