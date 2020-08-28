#include <iostream>

/*
	 A 
	/\
   B  C
	\/
	 D
*/
class A
{
	public:
	A(int inp):num_A(inp)
	{

	} 
		int num_A;
};
/*Memory : class A{num_A}*/

class B:virtual public A 
{
	public:
	B():A(0),num_B(0)
	{

	} 
	
	int num_B;	
};
/*Memory : class B{num_A,num_B}*/

class C:virtual public A 
{
	public:
		C():A(0),num_C(0)
		{

		} 
		int num_C;	
};
/*Memory : class C{num_A,num_C}*/

class D:public B, public C 
{
	public:
		D():A(0),num_D(0)
		{

		}  
		int num_D;
};
/*Memory : class D{num_A,num_B,num_C,num_D}*/

int main()
{
	class D d;
	d.num_D = 22;

	d.num_B = 10;
	d.num_C = 20;

	// will get error: request for member 'num_A' is ambiguous
	// need to use virtual inheritance for class A
	// the lowest derieved class in heirarchy needs to initialize num A
	// Always prefer pure abstract class during multiple inheritence.
	d.num_A = 2;
	
	return 0;
}
