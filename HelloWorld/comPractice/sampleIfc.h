// sampleIfc.h : Declaration of the CsampleIfc

#pragma once
#include "resource.h"       // main symbols



#include "comPractice_i.h"
#include "_IsampleIfcEvents_CP.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CsampleIfc

class ATL_NO_VTABLE CsampleIfc :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CsampleIfc, &CLSID_SampleIfc>,
	public IConnectionPointContainerImpl<CsampleIfc>,
	public CProxy_IsampleIfcEvents<CsampleIfc>,
	public IDispatchImpl<IsampleIfc, &IID_IsampleIfc, &LIBID_comPracticeLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CsampleIfc()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SAMPLEIFC)


BEGIN_COM_MAP(CsampleIfc)
	COM_INTERFACE_ENTRY(IsampleIfc)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CsampleIfc)
	CONNECTION_POINT_ENTRY(__uuidof(_IsampleIfcEvents))
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



	STDMETHOD(GetMyName)(BSTR* bstrNameOut);
};

OBJECT_ENTRY_AUTO(__uuidof(SampleIfc), CsampleIfc)
