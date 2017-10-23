// TMPPractice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DerM.h"
#include "variantutil.h"
#include <cstring>
#include <vector>
class A
{
public:
	A(int i, char c) : a_(i), c_(c){}
	A(){}
	void someFunc();
protected:
	int a_;
	char c_;
};

class B : public A
{
public:
	B(double d, int i, char c) : d_(d), A(i, c){}
	B(){  }
protected:
	double d_;
};


void A::someFunc()
{
	B b;
	static_cast<A&>(b) = *this;
	
	std::cout << "Hahaha" << std::endl;
}
//template<typename T>
//void Fun(T at)
//{
//	std::cout << "T at" << std::endl;
//}
//template<typename T>
//void Fun(T* ptr)
//{
//	std::cout << "T* ptr" << std::endl;
//}
//template<typename T>
//void Fun(T& ref)
//{
//	std::cout << "T& ptr" << std::endl;
//}

template<typename T> 
void Fun(const T* cPtr)
{
	T ptr = cPtr;
	*ptr = 20;
	std::cout << "const T* ptr" << std::endl;
}

#include <iostream>

class Money
{
public:
	Money() : amount{ 0.0 } {};
	Money(double _amount) : amount{ _amount } {};
	Money(const Money&) { std::cout << "copy\n"; }
	double amount;
};

void display_balance(const Money balance)
{
	std::cout << "The balance is: " << balance.amount << std::endl;
}

Money ReturnMoney()
{
	return 30.5f;
}

int main(int argc, char* argv[])
{
	Money payable{ 79.99 };
	Money payable1{ 80.5 };
	display_balance(payable);
	display_balance(49.95);
	display_balance(9.99f);
	Money m = ReturnMoney();
	return 0;
}
