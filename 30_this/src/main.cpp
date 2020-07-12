#include <iostream>

// "this" is a pointer to the current object instance to which the method belongs to.

class Entity;
void PrintEntity(const Entity& e);

class Entity
{
	public:
		Entity(int x, int y)
		{
			this->x = x;  //this is of the type Entity* const because this cannot be reassigned but value can be changed 
			this->y = y;

			PrintEntity(*this);
		}

		int GetX() const
		{
			return this->x;  //this is of the type const Entity* const because value cannot be changed and this cannot be reassigned
		}

	private:
		int x, y;
};

void PrintEntity(const Entity& e)
{
	std::cout<<"x = " << e.GetX() <<std::endl;
}

int main()
{
	Entity e(2,7);
	PrintEntity(e);
	return 0;
}