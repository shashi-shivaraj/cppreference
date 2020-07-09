#include <iostream>
#include <string>
#include <cstring>

//String is a array of characters

void PrintString(const std::string& str) //pass the object as reference
{
	std::cout <<"Printing "<< str << " with len = "<< str.length()<<std::endl;
}

int main()
{
	const char* name = "name"; //cstyle string stored in read only memory
	std::cout << "name = " << name << std::endl;

	char name_chars[4] = {'n', 'a', 'm', 'e'}; //can print garbage after e
	std::cout << "name_chars = " << name_chars << std::endl;

	char name_nulltermination[5] = {'n', 'a', 'm', 'e', '\0'}; //terminate the string with extra '\0'
	std::cout << "name_nulltermination = " << name_nulltermination << std::endl;

	std::string str = "string";
	str += " sample"; //append string
	PrintString(str);

	const char strng[8] = "sha\0shi"; //length will be 3
	std::cout<<"string length of sha\\0shi = "<<strlen(strng)<<std::endl;

	const char* name1 = u8"om";
	const wchar_t* name2 = L"shiv";
	const char16_t* name3 = u"om";
	const char32_t* name4 = U"shiv";

	std::cout<<name1<<name2<<name3<<name4<<std::endl; //check in memory

	return 0;
}
