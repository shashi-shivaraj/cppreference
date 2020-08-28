#include <iostream>
#include <climits>

int main()
{	
	std::cout << "Number of bits in a byte = "<<CHAR_BIT<<std::endl;
	std::cout<<std::endl;

	std::cout << "size of char in bytes = "<<sizeof(char)<<std::endl;
	std::cout << "Range of char is  "<<SCHAR_MIN << " to "<<SCHAR_MAX<<std::endl;
	std::cout<<std::endl;

	std::cout << "size of unsigned char in bytes = "<<sizeof(char)<<std::endl;
	std::cout << "Range of char is  0 to "<<UCHAR_MAX<<std::endl;
	std::cout<<std::endl;

	std::cout << "size of short in bytes = "<<sizeof(short)<<std::endl;
	std::cout << "Range of short is  "<<SHRT_MIN << " to "<<SHRT_MAX<<std::endl;
	std::cout<<std::endl;
	
	std::cout << "size of unsigned short in bytes = "<<sizeof(unsigned short)<<std::endl;
	std::cout << "Range of unsigned short is 0 to "<<USHRT_MAX<<std::endl;
	std::cout<<std::endl;

	//refer <cstdint> to specify the size of int like uint8_t , int64_t for better portability.
	std::cout << "size of int in bytes = "<<sizeof(int)<<std::endl;
	std::cout << "Range of int is  "<<INT_MIN << " to "<<INT_MAX<<std::endl;
	std::cout<<std::endl;
	
	std::cout << "size of unsigned int in bytes = "<<sizeof(unsigned int)<<std::endl;
	std::cout << "Range of unsigned int is 0 to "<<UINT_MAX<<std::endl;
	std::cout<<std::endl;

	std::cout << "size of long in bytes = "<<sizeof(long)<<std::endl;
	std::cout << "Range of long is  "<<LONG_MIN << " to "<<LONG_MAX<<std::endl;
	std::cout<<std::endl;
	
	std::cout << "size of unsigned long in bytes = "<<sizeof(unsigned int)<<std::endl;
	std::cout << "Range of unsigned long is 0 to "<<ULONG_MAX<<std::endl;
	std::cout<<std::endl;

	std::cout << "size of long long in bytes = "<<sizeof(long long)<<std::endl;
	std::cout << "Range of long is  "<<LLONG_MIN << " to "<<LLONG_MAX<<std::endl;
	std::cout<<std::endl;
	
	std::cout << "size of unsigned long long in bytes = "<<sizeof(unsigned long long)<<std::endl;
	std::cout << "Range of unsigned long long is 0 to "<<ULLONG_MAX<<std::endl;
	std::cout<<std::endl;


	std::cout << "size of float in bytes = "<<sizeof(float)<<std::endl;
	std::cout<<std::endl;

	std::cout << "size of double in bytes = "<<sizeof(double)<<std::endl;
	std::cout<<std::endl;

	std::cout << "size of boolean in bytes = "<<sizeof(bool)<<std::endl;
	std::cout<<std::endl;

	std::cout << "size of pointer in bytes = "<<sizeof(nullptr)<<std::endl;
	std::cout<<std::endl;

	char var = 'a';
	std::cout<<"printing char var = 'a' :  "<<var<<std::endl;
	
	var = 66;
	std::cout<<"printing char var = '66' : "<<var<<std::endl;

	return 0;
}