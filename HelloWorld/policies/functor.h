#pragma once
#include <iostream>
#include "typelist.h"

template<typename T>
struct WARN_FOR_TYPE
{
	WARN_FOR_TYPE()
	{
		T t;
	}
};


template<typename RT, typename TLIST>
class FunctorImpl;

template<typename RT>
class FunctorImpl<RT, NullType>
{
public:
	virtual RT operator() () = 0;
	virtual FunctorImpl* clone() = 0;
	virtual ~FunctorImpl(){}
};


template<typename RT, typename p1>
class FunctorImpl<RT, TL1(p1)>
{
public:
	virtual RT operator() (p1) = 0;
	virtual FunctorImpl* clone() = 0;
	virtual ~FunctorImpl(){}
};

template<typename RT, typename p1, typename p2>
class FunctorImpl<RT, TL2(p1, p2)>
{
public:
	virtual RT operator() (p1, p2) = 0;
	virtual FunctorImpl* clone() = 0;
	virtual ~FunctorImpl(){}
};
template<typename RT, typename p1,  typename p2, typename p3>
class FunctorImpl<RT, TL3(p1,p2,p3)>
{
public:
	virtual RT operator() (p1,p2,p3) = 0;
	virtual FunctorImpl* clone() = 0;
	virtual ~FunctorImpl(){}
};

template<typename PARFUNC, typename CLASS>
class FunctorHandler : public FunctorImpl<typename PARFUNC::RetType, typename PARFUNC::ParmList>
{
public:
	FunctorHandler(const CLASS& s) : Obj_(s){
		(void)WARN_FOR_TYPE<CLASS>();
	}
	typedef typename PARFUNC::RetType result;
	result operator () ()
	{
		return Obj_();
	}
	typedef typename PARFUNC::_p1 _p1;
	result operator () (_p1 p1)
	{
		return Obj_(p1);
	}
	typedef typename PARFUNC::_p2 _p2;
	result operator () (_p1 p1, _p2 p2)
	{
		return Obj_(p1, p2);
	}
	typedef typename PARFUNC::_p3 _p3;
	result operator() (_p1 p1, _p2 p2, _p3 p3)
	{
		return Obj_(p1, p2, p3);
	}
	FunctorHandler* clone() { return new FunctorHandler(*this); }
private:
	CLASS Obj_;

};


template <typename PARFUNC, typename PtrtoObj, typename MemFnPtr>
class MemFunHandler : public FunctorImpl<typename PARFUNC::RetType, typename PARFUNC::ParmList>
{
public:
	MemFunHandler(const PtrtoObj& s, const MemFnPtr& fn) : Obj_(s), fn_(fn) 
	{
		(void)WARN_FOR_TYPE<PtrtoObj>();
		(void)WARN_FOR_TYPE<MemFnPtr>();
	}
	typedef typename PARFUNC::RetType result;
	result operator () ()
	{
		return (Obj_->*fn_)();
	}
	typedef typename PARFUNC::_p1 _p1;
	result operator () (_p1 p1)
	{
		return (Obj_->*fn_)(p1);
	}
	typedef typename PARFUNC::_p2 _p2;
	result operator () (_p1 p1, _p2 p2)
	{
		return (Obj_->*fn_)(p1, p2);
	}
	typedef typename PARFUNC::_p3 _p3;
	result operator() (_p1 p1, _p2 p2, _p3 p3)
	{
		return (Obj_->*fn_)(p1, p2, p3);
	}
	MemFunHandler* clone() { return new MemFunHandler(*this); }
private:
	PtrtoObj Obj_;
	MemFnPtr fn_;

};


template<typename RT, typename TLIST>
class Functor
{
public:
	typedef FunctorImpl<RT, TLIST> fImpl;

	explicit Functor() {}
	explicit Functor(std::auto_ptr<fImpl>& spImpl) : spImpl_(spImpl) {}
	Functor(const Functor& ){}
	Functor& operator= (const Functor& ) {}
	
	template<class T>
	explicit Functor(const T& t) : spImpl_(new FunctorHandler<Functor, T>(t))
	{	
	}

	template<typename PtrtoObj, typename PtrToMem>
	explicit Functor(const PtrtoObj& obj, const PtrToMem& fnPtr) :
		spImpl_(new MemFunHandler <Functor, PtrtoObj, PtrToMem>(obj, fnPtr))
	{
	}
	
	typedef RT RetType;
	typedef TLIST ParmList;

	typedef typename TypeAtNoStrict<TLIST, 0,  EmptyType>::Result _p1;
	typedef typename TypeAtNoStrict<TLIST, 1,  EmptyType>::Result _p2;
	typedef typename TypeAtNoStrict<TLIST, 2,  EmptyType>::Result _p3;
	typedef typename TypeAtNoStrict<TLIST, 3,  EmptyType>::Result _p4;
	typedef typename TypeAtNoStrict<TLIST, 4,  EmptyType>::Result _p5;
	typedef typename TypeAtNoStrict<TLIST, 5,  EmptyType>::Result _p6;
	typedef typename TypeAtNoStrict<TLIST, 6,  EmptyType>::Result _p7;
	typedef typename TypeAtNoStrict<TLIST, 7,  EmptyType>::Result _p8;
	typedef typename TypeAtNoStrict<TLIST, 8,  EmptyType>::Result _p9;
	typedef typename TypeAtNoStrict<TLIST, 9,  EmptyType>::Result _p10;
	typedef typename TypeAtNoStrict<TLIST, 10, EmptyType>::Result _p11;

	RT operator () ()
	{
		return (*spImpl_)();
	}

	RT operator () (_p1 p1)
	{
		return (*spImpl_)(p1);
	}

	RT operator () (_p1 p1, _p2 p2)
	{
		return (*spImpl_)(p1, p2);
	}

	RT operator () (_p1 p1, _p2 p2, _p3 p3)
	{
		return (*spImpl_)(p1, p2, p3);
	}

	
private:
	
	std::auto_ptr<fImpl> spImpl_;
};

template<typename Functor2Bind>
class BindArgAt : public FunctorImpl<typename Functor2Bind::RetType, typename Functor2Bind::ParmList::Tail>
{
public:
	typedef typename Functor2Bind::_p1 Bound;
	typedef typename Functor2Bind::RetType RetType;
typedef typename Functor2Bind::ParmList::Tail ParmList;
typedef FunctorImpl<RetType, ParmList> fImpl;
	BindArgAt(const Functor2Bind& fun, const Bound& b) : fun_(fun), b_(b){}

	RetType operator() ()
	{
		return fun_(b_);
	}
	typedef typename Functor2Bind::_p2 _p1;
	RetType operator() (_p1 p1)
	{
		return fun_(b_, p1);
	}
	typedef typename Functor2Bind::_p3 _p2;
	RetType operator() (_p1 p1, _p2 p2)
	{
		return fun_(b_, p1, p2);
	}
	typedef typename Functor2Bind::_p4 _p3;
	RetType operator() (_p1 p1, _p2 p2, _p3 p3)
	{
		return fun_(b_, p1, p2, p3);
	}
	BindArgAt* clone() { return new BindArgAt(*this); }
private:
	Functor2Bind fun_;
	Bound b_;
};

template<typename Functor2Bind>
std::auto_ptr<typename BindArgAt<Functor2Bind>::fImpl> BindFirst(const Functor2Bind& fn, const typename BindArgAt<Functor2Bind>::Bound& b)
{
	typedef typename BindArgAt<Functor2Bind>::fImpl fImpl;
 std::auto_ptr<fImpl>(new BindArgAt<Functor2Bind>(fn, b));
}