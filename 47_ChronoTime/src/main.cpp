#include <iostream>
#include <chrono>
#include <thread>

struct Timer
{
	Timer():start(std::chrono::high_resolution_clock::now()),end(start),duration(0)
	{
	}

	~Timer()
	{
		auto end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		std::cout<<"Time duration ms = "<<duration.count() * 1000<<std::endl;
	}

	std::chrono::time_point<std::chrono::high_resolution_clock> start , end;
	std::chrono::duration<float> duration;
};

void function()
{
	Timer timer;

	for(int i = 0;i < 100; i++)
	{
		std::cout<<"count = "<< i <<"\n";
	}
}

int main()
{
	using namespace std::literals::chrono_literals; //required for sleep_for

	auto start = std::chrono::high_resolution_clock::now(); //current instant of time
	std::this_thread::sleep_for(2s); //suspend this thread for 2 seconds
	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> duration = end - start;
	std::cout << "duration = "<< duration.count() <<std::endl;

	function();

	return 0;
}