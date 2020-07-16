#include "lib.h"
#include <dlfcn.h>

//option 1 : to link the shared lib while building exe using -l
//option 2 : use dlopen and dlsym to read the symbols from shared lib
 
int main()
{
	void (*funcptr)(std::string);
	void *sampleLib = dlopen("libsample.so", RTLD_LAZY);

	if(!sampleLib)
	{
		std::cout<<"dlopen failed"<<std::endl;
		return -1;
	}
	
	funcptr = (void (*)(std::string))dlsym(sampleLib, "_Z8PrintLibNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE");
	
	if(!funcptr)
	{
		std::cout<<"funcptr null"<<std::endl;
		return -1;
	}
	
	(*funcptr)("shared lib");
	
	dlclose(sampleLib);
	
	return 0;
}