#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

//custom exception class
class BadLengthException : public std::exception
{
    public: 
        BadLengthException(const int& n):msg(std::string("BadLengthException with len = ") + std::to_string(n))
        {
        }
        
        const char* what() const throw() override
        {
            return msg.c_str();
        }

    private:
        std::string msg;
};

int divideByN(int n) 
{
    if (n == 0) {
        throw std::invalid_argument("division is not defined for n=0");
    }
    if (n == 1) {
        throw 0;
    }
	if (n == -1)
	{
		throw BadLengthException(n);
	}

    return 0;
}

void process_input(int n) 
{
    try 
    {
        int d = divideByN(n);
        std::cout << "result=" << d << std::endl;
    } 
	catch (std::exception& e) //catch an exception of partiular type can be std::invalid_argument instead of std::exception
    {
        std::cout<<e.what()<<std::endl;
    }
	catch(...) //to catch generic exception
    {
        std::cout<<"Other Exception"<<std::endl;   
    }
}

int main()
{
	int n = 0;
    std::cin >> n;

    process_input(n);

    return 0;
}