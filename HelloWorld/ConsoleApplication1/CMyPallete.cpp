#include "stdafx.h"
#include "CMyPallete.h"

CMyPallete::CMyPallete()
{
	eAnnotColor.Add((UINT)RGB(255, 0, 0));		// NMCD_RED
	eAnnotColor.Add((UINT)RGB(0, 255, 0));		// NMCD_GREEN
	eAnnotColor.Add((UINT)RGB(0, 0, 255));		// NMCD_BLUE
	eAnnotColor.Add((UINT)RGB(255, 255, 0));		// NMCD_YELLOW
	eAnnotColor.Add((UINT)RGB(255, 0, 255));		// NMCD_MAGENTA
	eAnnotColor.Add((UINT)RGB(0, 255, 255));		// NMCD_CYAN
	eAnnotColor.Add((UINT)RGB(128, 0, 0));		// NMCD_DARK_RED
	eAnnotColor.Add((UINT)RGB(0, 128, 0));		// NMCD_DARK_GREEN
	eAnnotColor.Add((UINT)RGB(0, 0, 128));		// NMCD_DARK_BLUE
	eAnnotColor.Add((UINT)RGB(128, 128, 0));		// NMCD_DARK_YELLOW
	eAnnotColor.Add((UINT)RGB(128, 0, 128));		// NMCD_DARK_MAGENTA
	eAnnotColor.Add((UINT)RGB(0, 128, 128));		// NMCD_DARK_CYAN
	eAnnotColor.Add((UINT)RGB(255, 128, 0));		// NMCD_ORANGE
	eAnnotColor.Add((UINT)RGB(192, 192, 192));	// NMCD_GRAY
	eAnnotColor.Add((UINT)RGB(128, 128, 128));	// NMCD_DARK_GRAY
	eAnnotColor.Add((UINT)RGB(255, 255, 255));	// NMCD_WHITE

	// add supplementary colors
	eAnnotColor.Add((UINT)RGB(255, 128, 0));		// NMCD_BEIGE
	eAnnotColor.Add((UINT)RGB(128, 0, 255));		// NMCD_VIOLET
	eAnnotColor.Add((UINT)RGB(230, 230, 230));	// NMCD_GRAY10
	eAnnotColor.Add((UINT)RGB(205, 205, 205));	// NMCD_GRAY20
	eAnnotColor.Add((UINT)RGB(179, 179, 179));	// NMCD_GRAY30
	eAnnotColor.Add((UINT)RGB(152, 152, 152));	// NMCD_GRAY40
	eAnnotColor.Add((UINT)RGB(102, 102, 102));	// NMCD_GRAY60
	eAnnotColor.Add((UINT)RGB(76, 76, 76));		// NMCD_GRAY70
	eAnnotColor.Add((UINT)RGB(0, 0, 0));			// NMCD_BLACK
	eAnnotColor.Add((UINT)RGB(128, 255, 0));		// NMCD_LTGREEN
	eAnnotColor.Add((UINT)RGB(0, 128, 255));		// NMCD_SKY
}

UINT32 CMyPallete::GetColorIndex(COLORREF color)
{
	NPLOGPALETTE pPal; // Local palette

	UINT32 numColors = eAnnotColor.GetSize();

	//Allocates space for QcQp Palette 'pPal'
	pPal = (NPLOGPALETTE)LocalAlloc(LPTR, (sizeof(LOGPALETTE) + (sizeof(PALETTEENTRY) * numColors)));
	if (!pPal)
		return color;

	//Initialize 'pPal' fields
	COLORREF annotColor;
	for (int i = 0; i<numColors; i++)
	{
		annotColor = eAnnotColor[i];
		pPal->palPalEntry[i].peRed = GetRValue(annotColor);
		pPal->palPalEntry[i].peGreen = GetGValue(annotColor);
		pPal->palPalEntry[i].peBlue = GetBValue(annotColor);
		pPal->palPalEntry[i].peFlags = NULL;
	}

	pPal->palNumEntries = numColors;
	pPal->palVersion = 0x300;
	int ret = m_cPalette.CreatePalette(pPal);

	//int n = m_cPalette.SetPaletteEntries(0, numColors, &pPal->palPalEntry[0]);

	// construct a color palette

	int nColorIndex = m_cPalette.GetNearestPaletteIndex(color);

	//NPLOGPALETTE tmpPpal = (NPLOGPALETTE)LocalAlloc(LPTR, (sizeof(LOGPALETTE) + (sizeof(PALETTEENTRY) * numColors)));

	//if (tmpPpal)
	//{
	//	int n = m_cPalette.GetPaletteEntries(0, 27, &tmpPpal->palPalEntry[0]);
	//	for (int i = 0; i < 27; i++)
	//	{
	//		BYTE red = tmpPpal->palPalEntry[i].peRed;
	//		BYTE green = tmpPpal->palPalEntry[i].peGreen;
	//		BYTE blue = tmpPpal->palPalEntry[i].peBlue;
	//	}
	//}
	//Free allocated memory
	VERIFY(LocalFree((HLOCAL)pPal) == NULL);

	return nColorIndex;
}