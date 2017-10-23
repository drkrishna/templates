
#include <afxwin.h>
// Interface of CMyCommandLineInfo

class CMyCommandLineInfo : public CCommandLineInfo
{
	// Attributes
public:
	BOOL    m_bHelp;        // /H /? /HELP
	CString m_strParameter;
	BOOL    m_bSuccess;     // all switches ok
	// Construction
public:
	CMyCommandLineInfo(void);
	// Overrides
public:
	virtual void ParseParam(LPCTSTR lpszParam, BOOL bFlag, BOOL bLast);
};