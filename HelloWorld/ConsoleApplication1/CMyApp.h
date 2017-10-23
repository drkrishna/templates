#include <afxwin.h>
#include "CMyCommandLineInfo.h"


class CMyApp : public CWinApp
{
	// Construction
public:
	CMyApp(void);
	// Attributes
public:
	CMyCommandLineInfo m_cmdInfo;
	
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyApp)
public:
	virtual BOOL InitInstance();
	virtual int Run();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL
	// Implementation
public:
	virtual ~CMyApp(void);
};