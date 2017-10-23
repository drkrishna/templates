#pragma once
#include <map>

template<typename T1, typename T2>
class Data
{
public:
	typedef std::map<T1, T2> t1t2Map;
	static bool InitData();
private:
	static bool IsInit;
	static t1t2Map map;
};

template<typename T1, typename T2>
bool Data<T1, T2>::IsInit = false;

template<typename T1, typename T2>
typename Data<T1, T2>::t1t2Map  Data<T1, T2>::map;