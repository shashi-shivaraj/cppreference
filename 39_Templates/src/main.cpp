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

template<typename T>   // primary template
struct is_void : std::false_type
{
};

template<>  // explicit specialization for T = void
struct is_void<void> : std::true_type
{
};

int main()
{
	Print("Hazard");
	Print(2);
	Print(2.791);

	Print<float>(5); //can specify the typename

	Array<std::string, 22> array;
	std::cout<<array.GetSize()<<std::endl;

	// for any type T other than void, the 
    // class is derived from false_type
    std::cout << is_void<char>::value << '\n'; 
    // but when T is void, the class is derived
    // from true_type
    std::cout << is_void<void>::value << '\n';

	return 0;
}