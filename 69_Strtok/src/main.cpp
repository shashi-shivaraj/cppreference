#include <cstring>
#include <iostream>

//char* token = std::strtok(inputstr,"list of delimiters");

//strtok is destructive,inputstr gets modified since it 
//adds null termination after each token
 
int main() 
{
    char input[100] = "A bird came:down the walk";

    char *token = std::strtok(input, " :"); //delimiters are " " and :
    while (token) 
	{
        std::cout << token << '\n';
        token = std::strtok(nullptr, " :"); //input is nullptr
    }
}