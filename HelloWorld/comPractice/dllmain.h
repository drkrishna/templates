// dllmain.h : Declaration of module class.

class CcomPracticeModule : public ATL::CAtlDllModuleT< CcomPracticeModule >
{
public :
	DECLARE_LIBID(LIBID_comPracticeLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_COMPRACTICE, "{D1BC45C3-FB6A-427E-90AC-7A35D306EE8C}")
};

extern class CcomPracticeModule _AtlModule;
