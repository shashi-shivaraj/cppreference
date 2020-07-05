 #include <iostream>

int main(int argc , char* argv[])
{
	if(argc != 2)
	{
		std::cout<<"cmd line inputs invalid"<<std::endl;		
		return -1;
	}

	int value = std::atoi(argv[1]);
	std::cout << "value = " << value <<std::endl;  
	
	int ouput = value++ ;
	std::cout << "ouput = value++ : assign then increment : output = " << ouput <<std::endl;

	std::cout << "value = " << value <<std::endl;  

	ouput = ++value ;
	std::cout << "ouput = ++value : increment then assign : output = " << ouput <<std::endl;

	std::cout << "value = " << value <<std::endl; 

	ouput = value-- ;
	std::cout << "ouput = value-- : assign then decrement : output = " << ouput <<std::endl;

	std::cout << "value = " << value <<std::endl; 

	ouput = --value ;
	std::cout << "ouput = ++value : decrement then assign : output = " << ouput <<std::endl;

	std::cout << "value = " << value <<std::endl; 
	

	return 0;
}