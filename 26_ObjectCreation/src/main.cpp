#include <iostream>

//Create at Stack or Create at Heap

using String = std::string;

class Entity
{
	public:

	Entity():m_name("Unknown")
	{

	}

	Entity(const String& name):m_name(name)
	{

	}

	const String&  GetName() const
	{
		return m_name;
	}

	private:
		String m_name;
};

void Function()
{
	//at stack
	Entity  entityS = Entity("Hazard"); //scope of entityS is within this function
}


//allocation at heap takes longer and needsto be freed manually when compared to stach allocation

int main()
{
	Entity  entityS1; //allocated at stack 
	Entity  entityS2 = Entity("Hazard"); //allocated at stack 
	std::cout << entityS1.GetName() <<std::endl;
	std::cout << entityS2.GetName() <<std::endl;

	Entity* entityH = new Entity("HarzardHeap"); //allocated at Heap 
	std::cout << entityH->GetName() <<std::endl;

	delete entityH; //clean the heap allocation

	return 0;
}
