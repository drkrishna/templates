#pragma once

template<typename T>
struct SmartPointerTrait
{
	typedef T p_;
	typedef T& returnType;
};

template<typename T>
struct SmartPointerTrait<T*>
{
	typedef T* p_;
	typedef p_ returnType;
};


template<typename T>
class SmartPtr
{
public:
	explicit SmartPtr(SmartPointerTrait<T>::_p pointeeType) : _pointeeType(pointeeType){}
	SmartPtr& operator=(const SmartPtr& other);
	SmartPointerTrait<T>::returnType operator->()
	{
		return _pointeeType;
	}
	SmartPointerTrait<T>::returnType operator*()
	{

	}
};