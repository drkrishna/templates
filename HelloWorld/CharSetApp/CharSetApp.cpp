// CharSetApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif



using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	WCHAR wc;
	cout << "sizeof(wc) = " << sizeof(wc) << endl;
	TCHAR tc;
	cout << "sizeof(tc) = " << sizeof(tc) << endl;
	return 0;
}
