#include "stdafx.h"
#include "DerM.h"
#include <iostream>
template<>
bool Data<char, int>::InitData()
{
	std::cout << "<int, char>::InitData\n";
	if (!IsInit)
	{
		map.clear();
		map['a'] = 26;
	}
	IsInit = true;
	return IsInit;
}


template<>
bool Data<int, char*>::InitData()
{
	std::cout << "<int, char*>::InitData\n";
	if (!IsInit)
	{
		map.clear();
		map[10] = "hello";
	}
	IsInit = true;
	return IsInit;
}
