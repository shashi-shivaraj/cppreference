#include <iostream>

template<typename T> 	//Also can use template<class T>
void Print(T value)
{
	std::cout << value << std::endl;
}

template<typename T,int N>
class Array
{
	public:
		 int GetSize() const
		 {
			 return N;
		 }

	private:
		T m_Array[N];
};

int main()
{
	Print("Hazard");
	Print(2);
	Print(2.791);

	Print<float>(5); //can specify the typename

	Array<std::string, 22> array;
	std::cout<<array.GetSize()<<std::endl;

	return 0;
}