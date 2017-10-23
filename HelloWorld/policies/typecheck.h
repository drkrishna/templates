#pragma once
#include <iostream>
template<typename T, typename U>
struct Conversion
{
	typedef char small;
	struct big{ small x[2]; };
	static small Test(U);
	static big Test(...);
	static T MakeT();
	enum { sametype = false, exists = (sizeof(Test(MakeT())) == sizeof(small)) };
};

template<typename T>
struct Conversion<T, T>
{
	enum{sametype = true, exists = true};
};

#define ISCONVERTIBLE(T,U) \
	((Conversion<T,U>::exists && !Conversion<T,U>::sametype && !Conversion<const U, const void*>::sametype))


//concept
//array type

typedef char big[3];
//big GetBig(big b)        <------ returning array is not allowed
big& GetBig(big b)       //<------ b has been dacayed to pointer to char
{
/* big b = b is not allowed as b is char* and big is big(actually char[3] but let's treat 
	it as type and also array initialization need 
	initializer list. so to make a copy we have to call memcopy functions*/
	big& blr = *((big*)(&*b));  // b points to first element of the array hence get the address of first element using &*b
	b++;                        //b is char* hence b++ points to next element  
	std::cout << typeid(b).name() << std::endl; //char*
	std::cout << blr << std:: endl;
	std::cout << b << std::endl;
	return blr;
}