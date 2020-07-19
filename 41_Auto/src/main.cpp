#include <iostream>
#include <vector>
#include <unordered_map>

class Device{};

class DeviceManager
{
	public:

		DeviceManager(): m_Device()
		{

		}

		const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const
		{
			return m_Device;
		}

	private:
		std::unordered_map<std::string, std::vector<Device*>> m_Device;
};

int main()
{
	int a = 5;
	auto b = a;

	std::cout << b <<std::endl;

	std::vector<std::string> strs;
	strs.push_back("Apple");
	strs.push_back("Banana");

	for(auto it = strs.begin(); it != strs.end(); it++)
	{
		std::cout << *it <<std::endl;
	}

	DeviceManager dm = DeviceManager();
	const auto& devices = dm.GetDevices(); 

	std::cout<<devices.size()<<std::endl;

	return 0;
}