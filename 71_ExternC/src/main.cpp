#include <iostream>
#include "log.h"

//C++ compilers use name mangling
//[ 32](sec  1)(fl 0x00)(ty  20)(scl   2) (nx 1) 0x00000410 __Z4logCi
//C compilers donot 
//[ 64](sec  1)(fl 0x00)(ty  20)(scl   2) (nx 1) 0x000004d4 _logC

//So when some modules are compiled using C and others using C++,
//the C++ linker will not be able to find the symbols for C code.
//Using extern C in header specifies the C++ linker to generate c-style symbol
// because the module was compiled using C compiler.      

void logC(int i)
{
    std::cout << i <<std::endl;
}

int main()
{
	logC("Init logging ++");
	logC(2791);
	logC("Deinit logging --");
}
