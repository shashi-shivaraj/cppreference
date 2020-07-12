#include <iostream>
#include <string>

//class member variables should be initialized at the constructor

class Example
{
	public:

		Example() : m_number(0)
		{
			std::cout<<"Created Example "<<std::endl;
		}

		Example(const int& num) : m_number(num)
		{
			std::cout<<"Created Example with "<< m_number <<std::endl;
		}

	private:
		int m_number;
};

class Entity
{
	public :

		Entity() : m_name("unknown"), m_score(0)  //initialize in the same order of declaration
		{
			// -Weffc++ will give warning, so its beeter to initialize in the list above
			m_example = Example(0); //Both default and user defined Example constructors will be called.  
		}

		Entity(const std::string& name) : m_name(name), m_score(1),m_example(m_score) //only user defined constructor of Example will be called.
		{
		}

		const std::string& GetName() const
		{
			return m_name;
		} 

		const int& GetScore() const
		{
			return m_score;
		}

	private :
		std::string m_name;
		int m_score;
		Example m_example; 

};


int main()
{
	Entity* E = new Entity();
	std::cout <<" E name = "<< E->GetName() << " score = "<< E->GetScore() << std::endl;

	Entity* F = new Entity("Hazard");
	std::cout <<" F name = "<< F->GetName() << " score = "<< F->GetScore() << std::endl;

	delete E;
	delete F;
	
	return 0;
}
