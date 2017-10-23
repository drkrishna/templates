#pragma once
#include <iostream>
#include <comutil.h>
namespace MIVARUTIL{

	template<typename T>
	struct VT_TYPE;

	template<>
	struct VT_TYPE<char>
	{
		enum{ VT = VT_I1 };
	};

	template<>
	struct VT_TYPE<short>
	{
		enum{ VT = VT_I2 };
	};

	template<>
	struct VT_TYPE<int>
	{
		enum{ VT = VT_INT };
	};

	template<>
	struct VT_TYPE<long>
	{
		enum{ VT = VT_I4 };
	};

	template<>
	struct VT_TYPE<long long>
	{
		enum { VT = VT_I8 };
	};

	template<>
	struct VT_TYPE<float>
	{
		enum{ VT = VT_R4 };
	};

	template<>
	struct VT_TYPE<double>
	{
		enum { VT = VT_R8 };
	};

	template<>
	struct VT_TYPE<unsigned char>
	{
		enum{ VT = VT_UI1 };
	};


	template<>
	struct VT_TYPE<unsigned short>
	{
		enum{ VT = VT_UI2 };
	};

	template<>
	struct VT_TYPE<unsigned int>
	{
		enum{ VT = VT_UINT };
	};

	template<>
	struct VT_TYPE<unsigned long>
	{
		enum{ VT = VT_UI4 };
	};

	template<>
	struct VT_TYPE<unsigned long long>
	{
		enum { VT = VT_UI8 };
	};

	using std::cout;
	using std::endl;
	template<typename T>
	bool packVariantImpl(const T& val, int& out, VARTYPE vt = VT_TYPE<T>::VT)
	{
		cout << "valid Vartype\n";
		return true;
	}

	bool packVariantImpl(const std::string& val, int& out)
	{
		cout << "unknown Vartype\n";
		return true;
	}

	template<typename T>
	bool packVariant(const T& val, int& out)
	{
		return packVariantImpl(val, out);
	}
}

