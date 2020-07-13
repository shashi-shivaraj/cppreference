#include <iostream>
#include <memory>

// std::unique_ptr
// std::shared_ptr
// std::weak_ptr

class Entity
{
	public:
		Entity(const std::string& msg ):m_msg(msg)
		{
			std::cout<<"Entity created with "<<m_msg<<std::endl;
		}

		~Entity()
		{
			std::cout<<"Entity destroyed with "<<m_msg<<std::endl;
		}

		void Print()
		{
			std::cout<<"Printing Entity with "<<m_msg<<std::endl;
		}

	private:
		std::string m_msg;

};

int main()
{
	//unique pointer
	{	
		std::cout<<"unique_ptr"<<std::endl;
		std::unique_ptr<Entity> entity = std::make_unique<Entity>("unique");
		//std::unique_ptr<Entity> e0 = entity;//unique pointer : cannot be shared because copy construct/assign are deleted
		entity->Print();
	}

	//shared pointer - reference counting
	{
		std::cout<<"shared_ptr"<<std::endl;
		std::shared_ptr<Entity> temp;
		std::cout<<"shared pointer use count = "<< temp.use_count() <<std::endl;
		{
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>("shared"); //refcount = 1
			sharedEntity->Print();
			temp = sharedEntity; //refcount = 2
			std::cout<<"shared pointer use count = "<< temp.use_count() <<std::endl;
		}
		//ref count = 1
		temp->Print();
		std::cout<<"shared pointer use count = "<< temp.use_count() <<std::endl;
	}//ref count = 0, destructor is called

	//weak pointer - reference count doesnot increase
	{
		std::cout<<"weak_ptr"<<std::endl;
		std::weak_ptr<Entity> temp;
		std::cout<<"weak pointer use count = "<< temp.use_count() <<std::endl;
		{
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>("shared"); //refcount = 1
			sharedEntity->Print();
			temp = sharedEntity; //refcount still = 1
			std::cout<<"weak pointer use count = "<< temp.use_count() <<std::endl;

			auto spt = temp.lock(); //creates a shared _ptr before usage
			spt->Print();

			std::cout<<"weak pointer use count = "<< temp.use_count() <<std::endl;

		}//ref count = 0, destructor is called
		std::cout<<"weak pointer use count = "<< temp.use_count() <<std::endl;
	}

	return 0;
}
 