#include <iostream>

//macro preprocessor
 
#define DEBUG 0

#define MSG "Hello Hazard" 

#if DEBUG == 1
#define LOG(x) std::cout<<x<<std::endl;
#else
#define LOG(x)
#endif

int main()
{
	LOG(MSG);

//disable the code 
#if 0
	return 0;
#endif

}
