#include <iostream>

//Virtual functions introduce dynamic dispatch via v-table
//v-table contains the mapping for all the virtual function in the base class
//to the correct overridden function to perform dynamic dispatch/mapping at runtime.

class Entity
{
	public:
		virtual std::string GetName()  //vitual method
		{
			return "Entity";
		}

		virtual ~Entity() //need to define virtual destructor in base class
		{}
};

class Player: public Entity
{
	private:
		std::string m_Name;

	public:
		Player(const std::string& name):m_Name(name)
		{}

		std::string GetName() override //override the the virtual method
		{
			return m_Name;
		}
};

void PrintName(Entity * e)
{
	std::cout << e->GetName() << std::endl;
}

int main()
{
	Entity* e = new Entity();
	PrintName(e); //will print entity

	Player* p = new Player("Player");
	PrintName(p);  //will print Player ; will print entity if GetName() is not virtual.
	return 0;
}
