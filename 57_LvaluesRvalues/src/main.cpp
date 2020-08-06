#include <iostream>

//If an object can appear on the left side of the assignment ,then its an l-value
//otherwise its an r-value: ref type&&

//l-value - any object for whom you can access its address.
//If not its r-value : ref type&&

int& GetRefval()
{
	static int val = 10;
	return val;
}

int Getval()
{
	int val = 10;
	return val;
}

int Setval(int val)
{
	val  = 10;
	return val;
}

//lval ref
void SetRefVal(int& val)
{
	val = 10;
}

//const val ref
int SetConstRefVal(const int& val)
{
	//val = 10;
	return val;
}

//rval reference
int SetRVal(int&& val) //will only accepts rval
{
	val = 10;
	return val;
}

int f()
{
	return 7;
}

void f(int& a)
{
	std::cout<<"l-value ref = "<< a <<std::endl;
}

void f(int&& a)
{
	std::cout<<"r-value ref = "<< a <<std::endl;
}

int main()
{
	int i = 10; //i:lvalue = 10:rvalue
	int a = i; //a:lvalue = i:lvalue

	//invalid : error: lvalue required as left operand of assignment
	//10 = i; //10:rvalue = i:lvalue

	GetRefval() = a; //Getval returns reference:lvalue = 5:rvalue

	//invalid : error: lvalue required as left operand of assignment
	//Getval() = 5;

	Setval(i); //set lval
	Setval(10); //set rval

	SetRefVal(i); //set lval
	
	//invalid : error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
	//SetRefVal(10); //set rval

	//invalid : error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
	//int& ref = 10;

	const int& ref = 10;
	Setval(ref);

	SetConstRefVal(10); //rval

	SetRVal(10); //rval

	int xf = 8;
	
	f(xf); //lvalue
	f(xf+1); //rvalue
	f(std::move(xf)); //rvalue
	f(f()); //rval - compiler generated temporary
	
	return 0;
}
