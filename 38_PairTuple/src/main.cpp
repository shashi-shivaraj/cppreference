#include <iostream>
#include <tuple>
#include <utility>
#include <string>

//Multiple return types

//pass by refernce and get the return values
void getStrings(std::string& one, std::string& two)
{
	one = "oneM1";
	two = "twoM1";
}

//use tuple, a list with multiple datatypes
std::tuple<std::string, std::string, int> getTupleData()
{
	return std::make_tuple("oneM2", "twoM2", 2);
}

//use pair, if there are two return values
std::pair<std::string, int> getPairData()
{
	return std::make_pair("oneM3", 2);
}

//use struct
struct returnData
{
	std::string firstStr;
	std::string secondStr;
	int count;
	int digit;
};

returnData getStructData()
{
	return {"oneM4", "twoM4", 2, 7};
}


int main()
{
	std::string one, two;
	getStrings(one, two);

	std::cout<<"Reference : "<<one<<" , "<<two<<std::endl;

	auto tupleData =  getTupleData();
	std::cout<<"Tuple : "<<std::get<0>(tupleData)<<" , "<<std::get<1>(tupleData)<<" , "<<std::get<2>(tupleData)<<std::endl;

	auto [str1,str2,num] =  getTupleData();
	std::cout<<"Tuple using stuctured binding : "<<str1<<" , "<<str2<<" , "<<num<<std::endl;


	std::string outstr;
	int digit;
	std::tie(outstr, digit ) = getPairData();	
	std::cout<<"Pair using tie : "<<outstr<<" , "<<digit<<std::endl;

	auto data = getPairData();
	std::cout<<"Pair : "<<data.first<<" , "<<data.second<<std::endl;

	auto [strP1,numP] =  getPairData();
	std::cout<<"Pair using stuctured binding : "<<strP1<<" , "<<numP<<std::endl;

	returnData ret = getStructData();
	std::cout<<"Struct : "<<ret.firstStr<<" , "<<ret.secondStr<<" , "<<ret.count<<" , "<<ret.digit<<std::endl;
	
	auto [str11,str22,count11,digit22] = getStructData();
	std::cout<<"Struct data using structured binding : "<<str11<<" , "<<str22<<" , "<<count11<<" , "<<digit22<<std::endl;

	return 0;
}