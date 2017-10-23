#include "stdafx.h"
#include "CMyCommandLineInfo.h"

/////////////////////////////////////////////////////////////////////////////
// Implementation of CMyCommandLineInfo
CMyCommandLineInfo::CMyCommandLineInfo(void) : CCommandLineInfo(), m_bHelp(FALSE), m_bSuccess(TRUE)
{
}
void CMyCommandLineInfo::ParseParam(LPCTSTR lpszParam, BOOL bSwitch, BOOL /*bLast*/)
{
	if (bSwitch)
	{
		if (0 == lstrcmpi(_T("help"), lpszParam))
		{
			m_bHelp = TRUE;
		}
		else
		{
			// the for loop enables 'compound' switches like "/XYZ"
			BOOL bContinue = TRUE;
			for (int i = 0; (i < lstrlen(lpszParam)) && m_bSuccess && bContinue; i++)
			{
				switch (lpszParam[i])
				{
				case _T('?'):
				case _T('h'):
				case _T('H'):
					m_bHelp = TRUE;
					break;
				default:
					m_bSuccess = bContinue = FALSE;
					break;
				}
			}
		}
	}
	else
	{
		m_strParameter = lpszParam;
	}
}