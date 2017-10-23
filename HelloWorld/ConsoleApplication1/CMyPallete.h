#include <afxwin.h>

class CMyPallete
{
public:
	UINT32 GetColorIndex(COLORREF color);
	CMyPallete();
private:
	CPalette m_cPalette;
	CUIntArray eAnnotColor;
};