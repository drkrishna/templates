// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "CMyApp.h"
#if !defined(_CONSOLE)
#error Make it a console application project
#endif


/////////////////////////////////////////////////////////////////////////////
// DECLARE_CONSOLEAPP - enables MFC-like console app
#ifdef _CONSOLE
#define DECLARE_CONSOLEAPP \
      extern int AFXAPI AfxWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow);\
      extern "C" int _tmain( int /*argc*/, TCHAR** /*argv*/, TCHAR** /*envp*/)\
	        {\
				  return AfxWinMain(GetModuleHandle(NULL), NULL, GetCommandLine(), SW_SHOW);\
	        }
// remember to instantiate app class
#endif // _CONSOLE
/////////////////////////////////////////////////////////////////////////////
DECLARE_CONSOLEAPP
CMyApp theApp;


/////////////////////////////////////////////////////////////////////////////
// Interface of some application class

/////////////////////////////////////////////////////////////////////////////
// Instatiate the application class
/////////////////////////////////////////////////////////////////////////////
// Implementation of the application class
