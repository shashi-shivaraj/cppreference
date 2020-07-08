#include <iostream>

//Pure virtual function is same as abstract method or interface.
//Pure virtual function doesnot have an implementation in the base class but 
//enforces the subclasses to implement the function.

class Printable //base class
{
	public:
	 virtual std::string GetClassName() = 0; //pure virtual function
	 virtual ~Printable() //need to define virtual destructor 
		{}
};

class Entity : public Printable
{
	public:

		std::string GetClassName() override //implement the pure virtual function
		{
			return "Entity";
		}
};

class Person : public Entity
{
	public: 
		Person(const std::string& name):m_name(name)
		{}

		std::string GetClassName() override //implement the pure virtual function
		{
			return "Person";
		}

	private:
		std::string m_name;
};

class A : public Printable
{
	public:
		std::string GetClassName() override //implement the pure virtual function
		{
			return "A class";
		}

};

void PrintClassName(Printable* P)
{
	std::cout << P->GetClassName() << std::endl;
}

int main()
{
	Printable *pPerson = new Person("Person");
	Printable *pEntity = new Entity();
	Printable *aclass = new A();

	PrintClassName(pPerson);
	PrintClassName(pEntity);
	PrintClassName(aclass);
	
	return 0;
}