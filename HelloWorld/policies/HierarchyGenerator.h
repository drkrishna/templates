#pragma once

#include "typelist.h"

template<int i>
struct Int2Type
{
	enum{tVal = i};
};

template<typename AtomicType, template<typename>class U>
class GenerateScatteredHierarachy : public U<AtomicType>
{
public:
	typedef U<AtomicType> LeftBase;
};

template<typename Head, typename Tail, template<typename> class U>
class GenerateScatteredHierarachy <TypeList<Head, Tail>, U> :public GenerateScatteredHierarachy<Head, U>,  public GenerateScatteredHierarachy<Tail, U>
{
public:
	typedef GenerateScatteredHierarachy<Head, U> LeftBase;
	typedef GenerateScatteredHierarachy<Tail, U> RightBase;
};

template<template<typename> class U>
class GenerateScatteredHierarachy<NullType, U>
{

};

template<typename T, typename U>
struct Rebind;

template<typename U, typename Tlist, template<typename> class Unit>
struct Rebind < U, GenerateScatteredHierarachy<Tlist, Unit> >
{
	typedef Unit<U> Result;
};

template<typename U, typename T>
typename Rebind<U,T>::Result&
Field(T& obj)
{
	return obj;
}

//template<typename T, int i>
//struct RebindAtImpl;
//
//template<typename Tlist, template<typename> class Unit, int i>
//struct RebindAtImpl<GenerateScatteredHierarachy<Tlist, Unit>, i>
//{
//	typedef typename RebindAtImpl<typename GenerateScatteredHierarachy<Tlist, Unit>::RightBase, i - 1>::Result Result;
//};
//
//template<typename Head, typename Tail, template<typename> class Unit>
//struct RebindAtImpl<GenerateScatteredHierarachy<TypeList<Head, Tail> , Unit>, 0>
//{
//	typedef typename GenerateScatteredHierarachy<Head, Unit>::LeftBase Result;
//};
//  
//
//template<int i, typename T>
//struct RebindAt
//{
//	typedef typename RebindAtImpl<T , i>::Result Result;
//};
////


