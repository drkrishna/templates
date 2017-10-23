#pragma once

template<typename T>
class NewCreator
{
public:
	static T* Create()
	{
		return new T;
	}
};

template<typename T>
class MallocCreator
{
public:
	static T* Create()
	{
		void* buff = malloc(sizeof(T));
		if (buff)
		{
			return new(buff)T;
		}
		return 0;
	}
};

template<typename T>
class PrototypeCreator
{
	const T* pTypeT_;
public:
	PrototypeCreator(T* Tobj = 0) : pTypeT_(Tobj)
	{

	}
	T* Create()
	{
		return pTypeT_ ? pTypeT_->Clone() : 0;
	}
	void SetProtoType(const T* tObj)
	{
		pTypeT_ = tObj;
	}
};

class Widget;

template<template<typename> class CreationPolicy>
class WidgetManager
{
public:
	Widget* Create(const Widget& oldWidget)
	{

		CreationPolicy<Widget> creator;
		creator.SetProtoType(&oldWidget);
		return creator.Create();
	}

	Widget* Create()
	{
		CreationPolicy<Widget> creator;
		return creator.Create();
	}
};
