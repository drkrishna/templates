// policies.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
//#define __STRICT__
#include <iostream>
#include <assert.h>
#include "staticAssert.h"
#include "typecheck.h"
#include "typelist.h"
#include "HierarchyGenerator.h"
#include "functor.h"
using std::cout;
using std::endl;

template <typename T>
class Holder
{
public:
	T _value;
	Holder(){}
protected:
	Holder(const Holder<T>&);
	Holder<T>& operator=(const Holder<T>&);
};

void TestFunction(int i, double d)
{
	cout << "TestFunction(" << i << "," << d << ")" << endl;
}

void TestFunction(int i)
{
	cout << "TestFunction(" << i << ")" << endl;
}

class C
{
public:
	void execute1()
	{
		std::cout << "this is void operator () ()" << std::endl;	
	}
	int execute2 (int, int)
	{
		std::cout << "this is int operator() (int, int)" << std::endl;
		return -1;
	}

	void execute3 (char)
	{
		std::cout << "this is void operator() (char)" << std::endl;
	}

	void execute4 (int, char, float)
	{
		std::cout << "this is void operator(int,char,float)" << std::endl;
	}
	//C* clone() { return new C(*this); }
};


int _tmain(int argc, _TCHAR* argv[])
{
	typedef TL3(int, char, float) tl3;
	typedef TypeUtil<tl3>::GetTypeAtNoStrict<1, int>::Result result;
	std::cout << typeid(result).name() << std::endl;
	C c;
	//Functor<void, NullType> f1(c);
	//Functor<int, TL2(int, int)> f2(c);
	//Functor<void, TL1(char)> f3(c);
	//Functor<void, TL3(int, char, float)> f4(c);
	//f1();
	//f2(10, 20);
	//f3('A');
	//f4(10, 'a', 60.5);

	Functor<void, NullType> f(&c, &C::execute1);
	f();
	return 0;
}


