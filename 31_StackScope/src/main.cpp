#include <iostream>

class Entity
{
	public:
		Entity(const std::string &scope):m_scope(scope)
		{
			std::cout<<"Entity constructor called with "<<m_scope<<std::endl;
		}

		~Entity()
		{
			std::cout<<"Entity destructor called with "<<m_scope<<std::endl;
		}

	private:
		std::string m_scope;
};

//unique pointer implementation
class scopePointer
{
	public:
		scopePointer(Entity *ptr):m_ptr(ptr)
		{

		}

		~scopePointer()
		{
			delete m_ptr;
		}

	private:
		Entity* m_ptr;
};

int main()
{
	{
		Entity e("stack");

		Entity* eH = new Entity("heap"); 

		delete eH; //have to manually deallocate
	}

	{
		scopePointer SP = new Entity("scope pointer");
	}
	
	return 0;
}