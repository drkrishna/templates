// sampleIfc.cpp : Implementation of CsampleIfc

#include "stdafx.h"
#include "sampleIfc.h"


// CsampleIfc
struct StaticInt
{
	static int a;
};

int StaticInt::a = 0;

STDMETHODIMP CsampleIfc::GetMyName(BSTR* bstrNameOut)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (StaticInt::a == 0)
	{
		StaticInt::a++;
		return E_FAIL;
	}
		
	*bstrNameOut = ::SysAllocString(_T(""));
	// TODO: Add your implementation code here
	
	return S_OK;
}
