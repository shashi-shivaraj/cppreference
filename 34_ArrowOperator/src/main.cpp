#include <iostream>

class Entity
{
	public:
		void Print() const
		{
			std::cout<<"Hello Print"<<std::endl;
		}
};


class ScopePtr
{
	public:
		ScopePtr(Entity *e):m_obj(e)
		{

		}

		ScopePtr(const ScopePtr&) = delete;

		ScopePtr& operator=(const ScopePtr&) = delete;

		~ScopePtr()
		{
			delete m_obj;
		}

		Entity* operator->() //overload the arrow operator
		{
			return m_obj;
		}

	private:
		Entity* m_obj;
};

struct Vec3
{
	float x, y, z;
};

int main()
{
	Entity* e = new Entity();

	e->Print(); //used to dereference the pointer 

	delete e;

	ScopePtr sptr(new Entity());
	sptr->Print();

	int offsetx = (int)&((Vec3*)nullptr)->x;
	int offsety = (int)&((Vec3*)nullptr)->y;
	int offsetz = (int)&((Vec3*)nullptr)->z;

	std::cout<<"offsetx = "<<offsetx<<std::endl;
	std::cout<<"offsety = "<<offsety<<std::endl;
	std::cout<<"offsetz = "<<offsetz<<std::endl;

	return 0;
}