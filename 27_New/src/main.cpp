#include <iostream>

//new allocates memeory at heap and needs to be manually deallocated using delete
 
 class Entity
 {	
	 public:

	 Entity():m_name("Unknown")
	 {}

	 Entity(const std::string& name):m_name(name)
	 {}

	 const std::string& GetName() const
	 {
		 return m_name;
	 }

	 private:
	 	std::string m_name;
 };


int main()
{
	int* a = new int; //4 bytes of memory
	int* b = new int[50]; //4*50 bytes

	Entity* entity = new Entity("Hazrad");
	std::cout<<entity->GetName()<<std::endl;

	//placement new - decide the memory location where the allocation occurs
	Entity* p = new(b) Entity();

	//clean up the memory allocation
	delete a;
	delete[] b; //for arrays
	delete entity;
	delete p;
	
	return 0;
}
