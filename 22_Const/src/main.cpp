#include <iostream>

//const Before the * sign - value cannot change.
//const After the * sign - pointer cannot be reassigned.
//const Before and After * sign -value cannot change and pointer cannot be reassigned.

class Entity
{
	public:

		int GetY()
		{
			m_y = 3;
			std::cout<<"GetY() called"<<std::endl;
			return m_y;
		}

		int GetY() const //read only method will not modify the class variables
		{
			// m_y = 3; //invalid
			std::cout<<"GetY() const called"<<std::endl;
			return m_y;
		}

		const int* const GetX() const //method will not modify the class variables
		{
			return m_x; //returned pointer cannot be reassigned and its contents cannot be changed.
		}

	private: 
		int* m_x, m_y; //m_x is a pointer and m_y is an int 
		int* m_z, *m_w;  //both pointers
};

void PrintEntityConst(const Entity& e) //cannot call non-const methods
{
	std::cout << e.GetY() << std::endl; //this will call the readonly const method
}

void PrintEntity(Entity& e)
{
	std::cout << e.GetY() << std::endl; //this will call non-const method
}


int main()
{
	const int a  = 90; //read only constant value
	int b = 100;

	std::cout << "const int a = " << a <<std::endl;
	std::cout << "int b = " << b <<std::endl;

	int* ptr = (int*) &a;
	std::cout <<"*ptr = (int*) &a = " << *ptr <<std::endl;

	int* ptr2 = &b;
	
	*ptr = 99;
	*ptr2 = 110;

	std::cout <<"*ptr = 99 = " << *ptr <<std::endl;
	std::cout << "const int a = " << a <<std::endl; //a value remains 90

	std::cout <<"*ptr2 = 110 = " << *ptr2 <<std::endl;
	std::cout << "int b = " << b <<std::endl; //b value changes to 110


	//Before the * sign - value cannot change.

	const int* temp = new int; //cannot change the contents of the pointer but can reassign to other address
	temp = ptr;
	//*temp = 2;

	std::cout <<*temp<<std::endl;

	int const* temp2 = new int; //cannot change the contents of the pointer but can reassign to other address  	
	temp2 = ptr2;
	//*temp2 = 2;

	std::cout <<*temp2<<std::endl;

	//After the * sign - pointer cannot be reassigned.

	int* const temp3 = new int; //cannot reassign the pointer but can change the contents of the pointer 
	*temp3 = 3;
	//temp3 = nullptr;

	std::cout <<*temp3<<std::endl;

	//Before and After * sign -value cannot change and pointer cannot be reassigned.

	const int* const temp4 = new int; //cannot reassign the pointer and cannot change the contents of the pointer.
	//*temp4 = 4;
	//temp4 = ptr;

	std::cout <<*temp4<<std::endl;

	Entity* e = new Entity;
	PrintEntityConst(*e);
	PrintEntity(*e);
	
	return 0;
}
