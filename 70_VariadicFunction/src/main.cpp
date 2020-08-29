#include <iostream>
#include <cstdarg>

void print_ints(int nums, ...) //first arg used to parse the args
{
	va_list args; //list of args

	va_start(args, nums); //init with the number of args

	for(int i = 0; i < nums; i++)
	{
		int val = va_arg(args,int); //get the argument
		std::cout<<val<<std::endl;
	}

	va_end(args); //end
}


void simple_printf(const char* fmt...) // C-style "const char* fmt, ..." is also valid
{
    va_list args;
    va_start(args, fmt);
 
    while (*fmt != '\0') {
        if (*fmt == 'd') {
            int i = va_arg(args, int);
            std::cout << i << '\n';
        } else if (*fmt == 'c') {
            // note automatic conversion to integral type
            int c = va_arg(args, int);
            std::cout << static_cast<char>(c) << '\n';
        } else if (*fmt == 'f') {
            double d = va_arg(args, double);
            std::cout << d << '\n';
        }
        ++fmt;
    }
 
    va_end(args);
}

int main()
{
	print_ints(4,2,7,9,1);
	print_ints(3,02,07,91);

	simple_printf("dcff", 3, 'a', 1.999, 42.5); 

	return 0;
}
