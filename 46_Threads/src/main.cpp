#include <iostream>
#include <thread>
#include <chrono>

//std::thread var(funcptr, args)
//var.join()
//std::this_thread

static bool flag = false;

void DoWork(const std::string& str) //thread function
{
	std::cout<<"Worker Thread ID = "<<std::this_thread::get_id()<<std::endl;

	using namespace std::chrono_literals;
	while(!flag)
	{
		std::cout<<"Worker Thread : "<<str<<std::endl;
		std::this_thread::sleep_for(1s);
	}
}

int main()
{
	std::string str = "Hazard";
	std::thread worker(DoWork, str); //create a worker thread

	std::cin.get();
	flag = true;

	worker.join(); //wait for worker theard

	std::cout<<"exiting now"<<std::endl;

	std::cout<<"Main Thread ID = "<<std::this_thread::get_id()<<std::endl;


	return 0;
}