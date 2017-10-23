#include "stdafx.h"
#include "CMyApp.h"
#include "CMyPallete.h"

#define RED				RGB(1,0,0)
#define GREEN			RGB(0,1,0)
#define BLUE			RGB(0,0,1)
#define YELLOW			RGB(1,1,0)
#define MAGENTA			RGB(1,0,1)
#define CYAN			RGB(0,1,1)


CMyApp::CMyApp(void) : CWinApp()
{
}
CMyApp::~CMyApp(void)
{
}
BOOL CMyApp::InitInstance()
{
	if (!CWinApp::InitInstance())
	{
		return FALSE;
	}

	_tprintf(_T("Init\n"));
	SetRegistryKey(_T("Codeguru samples"));

	return TRUE;
}
int CMyApp::Run()
{
	CMyPallete myPal;
	COLORREF cGreen = GREEN;
	UINT color = RGB(0, 255, 0);
	UINT32 index = myPal.GetColorIndex(cGreen);
	return CWinApp::Run(); // calls ExitInstance and exits right away when m_pMainWnd=NULL
}
int CMyApp::ExitInstance()
{
	_tprintf(_T("Done\n"));
	return CWinApp::ExitInstance();
}