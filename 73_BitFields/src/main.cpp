#include <iostream>

//__attribute__((packed)) works on linux; alternative is #pragma pack(1) 

enum option
{
	OPTION_ONE = 0x1, //0001
	OPTION_TWO = 0x2, //0010
	OPTION_THREE = 0x4,//0100
	OPTION_FOUR = 0x8, //1000
	OPTION_TWOTHREE = OPTION_TWO|OPTION_THREE,
};

struct counters
{
	int low:2; //max 1
	int mid:4; //max 7
	int high:6; //max 31
}__attribute__((packed)); // 2+4+6 = 12 bits + 4 padding = 16 bits = 2 bytes; 

int main()
{
	int op = OPTION_ONE|OPTION_TWO|OPTION_THREE|OPTION_FOUR;

	if(op & OPTION_ONE)
		std::cout<<"OPTION_ONE set"<<std::endl;
	if(op & OPTION_TWO)
		std::cout<<"OPTION_TWO set"<<std::endl;
	if(op & OPTION_THREE)
		std::cout<<"OPTION_THREE set"<<std::endl;
	if(op & OPTION_FOUR)
		std::cout<<"OPTION_FOUR set"<<std::endl;
	if(op & OPTION_TWOTHREE)
		std::cout<<"OPTION_TWOTHREE set"<<std::endl;

	std::cout<<"size of counters = "<<sizeof(counters)<<std::endl;
	counters count = {0,0,0};

	int i =0;
	while(i < 32)
	{
		count.low++;
		count.mid++;
		count.high++;

		//std::cout<<"low = "<<count.low<<"; mid = "<<count.mid<<"; high = "<<count.high<<std::endl;
		i++;	
	}

	unsigned int bitArray = 0;
	//set 2nd bit
	bitArray = bitArray | (0x1<<1);
	std::cout<<"bitArray set 2nd bit = "<<bitArray<<std::endl;
	//reset 2nd bit
	bitArray = bitArray & ~(0x1<<1);
	std::cout<<"bitArray reset 2nd bit = "<<bitArray<<std::endl;

	return 0;
}