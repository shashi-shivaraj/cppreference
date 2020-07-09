#include <iostream>

//public : access both inside and outside the class
//private: access only inside the class and friend class
//protected : access only inside the class and all other subclasses

class Entity
{
	public:
		Entity():x(0),y(0),z(0) 
		{
		}

		void PrintEntity()
		{
			std::cout<<"This is entity class with z = "<<z<<std::endl;
		}

	private: //it can be accessed only inside this class and by friend class
		int x, y;

	protected: //it can be accessed also in subclasses
		int z; 

};

class Player : public Entity
{
	public : 
		Player()
		{	
			z = 3; //accessing protected variable
		}

		void PrintPlayer()
		{
			std::cout<<"This is Player class with z = "<<z<<std::endl;
			std::cout<<"Calling base entity class print from player class"<<std::endl;
			PrintEntity();
		}
};

int main()
{
	Entity* e = new Entity();
	e->PrintEntity(); //public method

	Player* eP = new Player();
	eP->PrintPlayer(); // protected variable z is shared between base and subclass

	return 0;
}
