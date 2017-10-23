#pragma once

template<typename T>
class SomeClass
{
public:
	bool fun1_call(unsigned short* row, unsigned short* column)
	{
		return (static_cast<T*>(this))->fun1();
	}

	bool fun2(){

	}
};