// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "comPractice_i.h"
#include "dllmain.h"

CcomPracticeModule _AtlModule;

class CcomPracticeApp : public CWinApp
{
public:

// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CcomPracticeApp, CWinApp)
END_MESSAGE_MAP()

CcomPracticeApp theApp;

BOOL CcomPracticeApp::InitInstance()
{
	return CWinApp::InitInstance();
}

int CcomPracticeApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
