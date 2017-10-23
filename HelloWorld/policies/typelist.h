#pragma once
#include "staticAssert.h"


class NullType{};

struct EmptyType{};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//TypeList definition
template<typename T, typename U>
struct TypeList
{
	typedef T Head;
	typedef U Tail;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////

template<bool exp, typename T, typename U>
struct Select
{
	typedef T Result;
};

template<typename T, typename U>
struct Select<false, T, U>
{
	typedef U Result;
};


////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calculate TypeList Length 
// Lenth<TLIST>::value
template <class TList> struct Length;
template <> struct Length<NullType>
{
	enum { value = 0 };
};
template <class T, class U>
struct Length< TypeList<T, U> >
{
	enum { value = 1 + Length<U>::value };
};
////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////
// Checks if a type is member or not 
// typeinfoImpl<TLIST>::isMemeber
template<typename TL, typename B> struct typeinfoImpl
{
	enum { isMember = false };
};

template<typename H, typename T, typename B> struct typeinfoImpl<TypeList<H, T>, B>
{
	enum{ isMember = typeinfoImpl<H, B>::isMember | typeinfoImpl<T, B>::isMember };
};

template<typename B> struct typeinfoImpl<B, B>
{
	enum { isMember = true };
};
///////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
// Returns TypeList::Head at Index 
// TypeAt<TLIST, index>::Result
template<typename TL, int index>
struct TypeAt;

template<typename H, typename T, int index>
struct TypeAt<TypeList<H, T>, index>
{
	typedef typename TypeAt<T, index - 1>::Result Result;
};

template<typename H, typename T>
struct TypeAt<TypeList<H, T>, 0>
{
	typedef H Result;
};

template<typename TL, int index, typename RT>
struct TypeAtNoStrict;

template<typename H, typename T, int index, typename RT>
struct TypeAtNoStrict<TypeList<H, T>, index, RT>
{
	typedef typename TypeAtNoStrict<T, index - 1, RT>::Result Result;
};

template<int index, typename RT>
struct TypeAtNoStrict<NullType, index, RT>
{
	typedef RT Result;
};

template<typename H, typename T, typename RT>
struct TypeAtNoStrict<TypeList<H, T>, 0, RT>
{
	typedef H Result;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Returns index of a Type, returns -1 if type is not present in the List
// IndexOf<TList, Type>
template<typename TL, typename T>
struct IndexOf;

template<typename H, typename T, typename B>
struct IndexOf<TypeList<H,T>,B>
{
	enum{isMember = typeinfoImpl<TypeList<H,T>, B>::isMember};
	enum{ index = isMember ? (1 + IndexOf<T, B>::index) : -1 };
};

template<typename H, typename T>
struct IndexOf<TypeList<H, T>, H>
{
	enum{index = 0};
};

template<typename T>
struct IndexOf<NullType, T>
{
	enum{index = -1};
};

//////////////////////////////////////////////////////////////////////////////////////////////////
// Appends two typelist and returns new TypeList
// Append<TListO, TListA>
template<typename TLorg, typename TLta>
struct Append;

template<typename H, typename T>
struct Append<TypeList<H, T>, NullType>
{
	typedef TypeList<H, T> Result;
};
template<typename H, typename T, typename Ti>
struct Append<TypeList<H, T>, Ti>
{
	typedef TypeList<H, typename Append<T, Ti>::Result> Result;
};

template<typename H, typename Ti>
struct Append < TypeList<H, NullType>, Ti>
{
	typedef TypeList<H, TypeList<Ti, NullType> > Result;
};

template<typename Hi, typename Ha, typename Ta>
struct Append<TypeList<Hi, NullType>, TypeList<Ha, Ta> >
{
	typedef TypeList<Hi, TypeList<Ha, Ta> > Result;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Erase

template<typename TL, typename T, bool member>
struct EraseImpl;

template<typename H, typename T, typename N>
struct EraseImpl<TypeList<H, T>, N, true>
{
	enum{ index = IndexOf<TypeList<H,T>,N>::index };
	//typedef typename (index == -1) ? TypeList<H, T> : Append<TypeList<H, NullType>, typename EraseImpl<T, N>::Result>::Result Result; 
	typedef TypeList<H, 
		typename EraseImpl<T, N, index != -1>::Result>
		Result;
};

template<typename H, typename T, typename N>
struct EraseImpl<TypeList<H, T>, N, false>
{
	typedef TypeList<H, T> Result;
};
template<typename H, typename T>
struct EraseImpl<TypeList<H, T>, H, true>
{
	typedef T Result;
};


template<typename TL, typename T, bool member>
struct EraseAllImpl;

template<typename H, typename T, typename N>
struct EraseAllImpl<TypeList<H, T>, N, true>
{
	enum{ index = IndexOf<TypeList<H, T>, N>::index };
	typedef TypeList<H,
		typename EraseAllImpl<T, N, index != -1>::Result>
		Result;
};

template<typename H, typename T, typename N>
struct EraseAllImpl<TypeList<H, T>, N, false>
{
	typedef TypeList<H, T> Result;
};
template<typename H, typename T>
struct EraseAllImpl<TypeList<H, T>, H, true>
{
	enum{index = IndexOf<T,H>::index };
	typedef typename EraseAllImpl<T,H, index != -1> :: Result Result;
};


template<typename TList, typename TOLD, typename TNEW>
struct ReplaceImpl;


template<typename Head, typename Tail, typename TOLD, typename TNEW>
struct ReplaceImpl<TypeList<Head,Tail>, TOLD, TNEW>
{
	typedef TypeList<Head, typename ReplaceImpl<Tail, TOLD, TNEW>::Result> Result;
};

template<typename TOLD, typename TAIL, typename TNEW>
struct ReplaceImpl<TypeList<TOLD, TAIL> ,TOLD, TNEW>
{
	typedef TypeList<TNEW, TAIL> Result;
};

template<typename TOLD, typename TNEW>
struct ReplaceImpl<NullType, TOLD, TNEW>
{
	typedef NullType Result;
};


template<typename TLIST, typename T, typename U>
struct ReplaceAllImpl;

template<typename HEAD, typename TAIL, typename TOLD, typename TNEW>
struct ReplaceAllImpl<TypeList<HEAD, TAIL>, TOLD, TNEW>
{
	typedef TypeList<HEAD, typename ReplaceAllImpl<TAIL, TOLD, TNEW>::Result > Result;
};

template<typename TOLD, typename TAIL, typename TNEW>
struct ReplaceAllImpl<TypeList<TOLD, TAIL>, TOLD, TNEW>
{
	typedef TypeList<TNEW, typename ReplaceAllImpl<TAIL, TOLD, TNEW>::Result> Result;
};

template<typename TOLD, typename TNEW>
struct ReplaceAllImpl<NullType, TOLD, TNEW>
{
	typedef NullType Result;
};
 

//////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Wrapper of TypeList and forward the Typelist to indexof, typeAt and typeInfo
// TypeUtil<Tlist>::TypeInfo<type>::isMember
// TypeUtil<TList>::GetTypeAT<index>::Resutl
// TypeUtil<TList>::GetIndexOf<type>::index

template<typename TList>
struct TypeUtil;


template<typename Head, typename Tail> struct TypeUtil<TypeList<Head, Tail> >
{
	template<typename T> struct TypeInfo
	{
		enum{ isMember = typeinfoImpl<TypeList<Head, Tail>, T>::isMember };
	};
	template<int index>
	struct GetTypeAt
	{
		typedef typename TypeAt<TypeList<Head, Tail>, index>::Result Result;
	};
	template<int index, typename RT>
	struct GetTypeAtNoStrict
	{
		typedef typename TypeAtNoStrict<TypeList<Head, Tail>, index, RT>::Result Result;
	};
	template<typename T>
	struct GetIndexOf
	{ 
		enum {index = IndexOf<TypeList<Head,Tail>, T>::index};
	};

	template<typename T>
	struct Erase
	{
#ifdef __STRICT__
		template<bool> struct IsInTList;
		template<> struct IsInTList<true>{};
		enum{ TListHastType = sizeof(IsInTList<IndexOf<TypeList<Head, Tail>, T>::index != -1>) };
#endif
		typedef typename EraseImpl<TypeList<Head, Tail>, T, true>::Result Result;
	};
	template<typename T>
	struct EraseAll
	{

#ifdef __STRICT__
		template<bool> struct IsInTList;
		template<> struct IsInTList<true>{};
		enum{ TListHastType = sizeof(IsInTList<IndexOf<TypeList<Head, Tail>, T>::index != -1>) };
#endif
		typedef typename EraseAllImpl<TypeList<Head, Tail>, T, true>::Result Result;
	};

	template<typename TOLD, typename TNEW>
	struct Replace{
		typedef typename ReplaceImpl<TypeList<Head, Tail>, TOLD, TNEW>::Result Result;
	};

	template<typename TOLD, typename TNEW>
	struct ReplaceAll
	{
		typedef typename ReplaceAllImpl<TypeList<Head, Tail>, TOLD, TNEW>::Result Result;
	};
};
//////////////////////////////////////////////////////////////////////////////////////////////////


#define TL1(T)   TypeList<T, NullType>
#define TL2(T, U) TypeList<T, TL1(U) >
#define TL3(T,U,V) TypeList<T, TL2(U,V) >
#define TL4(T,U,V,W) TypeList<T, TL3(U,V,W) >
#define TL5(T,U,V,W,N) TypeList<T, TL4(U,V,W,N) >

