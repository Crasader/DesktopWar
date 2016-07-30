
#include "WinWrapper.h"
#include "gfx/gfx.h"

#include "app/GameDefine.h"
#include "Resource.h"


const int		cfg_TaskBarHeight = 40;

bool WinWrapper::Init(HWND hWnd)
{
	do
	{
		m_hWnd = hWnd;
		InitNotify(hWnd);

		GameDefine::viewWidth = GetSystemMetrics(SM_CXSCREEN);
		GameDefine::viewHeight = /*cfg_MapHeight;*/GetSystemMetrics(SM_CYSCREEN) - cfg_TaskBarHeight;

		int glWidth = GameDefine::viewWidth;
		int glHeight = GameDefine::viewHeight;
		HDC hdcDest = GetDC(m_hWnd);
		m_hDcSrc = CreateCompatibleDC(hdcDest);
		m_hBitmap = CreateCompatibleBitmap(hdcDest, glWidth, glHeight);
		SelectObject(m_hDcSrc, m_hBitmap);

		m_pBitsFromGL = new unsigned int[glWidth * glHeight];
		m_pBitsFromGLFlipY = new unsigned int[glWidth * glHeight];

	} while (false);

	return false;
}

void WinWrapper::Draw()
{
	// Copy GL buffer.
	int glWidth = GameDefine::viewWidth;
	int glHeight = GameDefine::viewHeight;
	memset(m_pBitsFromGL, 0, glWidth * glHeight * sizeof(unsigned int));
	memset(m_pBitsFromGLFlipY, 0, glWidth * glHeight * sizeof(unsigned int));
	glReadBuffer(GL_BACK);
	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	glReadPixels(0, 0, glWidth, glHeight, GL_BGRA, GL_UNSIGNED_BYTE, m_pBitsFromGL);
	
	for (int i = 0; i < glHeight; ++i)
		memcpy(&m_pBitsFromGLFlipY[(glHeight - i - 1)*glWidth], &m_pBitsFromGL[i*glWidth], glWidth * sizeof(unsigned int));
	
	SetBitmapBits(m_hBitmap, glWidth * glHeight * sizeof(unsigned int), m_pBitsFromGLFlipY);
	
	// Update layered window
	BLENDFUNCTION _Blend;
	_Blend.BlendOp = AC_SRC_OVER;
	_Blend.BlendFlags = 0;
	_Blend.AlphaFormat = AC_SRC_ALPHA;
	_Blend.SourceConstantAlpha = 255;
	POINT posSrc;
	posSrc.x = 0;
	posSrc.y = 0;
	POINT posDest;
	posDest.x = 0;
	posDest.y = GetSystemMetrics(SM_CYSCREEN) - glHeight - cfg_TaskBarHeight;
	SIZE sizeDest;
	sizeDest.cx = glWidth;
	sizeDest.cy = glHeight;
	HDC hdcDest = GetDC(m_hWnd);
	UpdateLayeredWindow(m_hWnd, hdcDest, &posDest, &sizeDest, m_hDcSrc, &posSrc, RGB(0, 0, 0), &_Blend, ULW_ALPHA);
	ReleaseDC(m_hWnd, hdcDest);

}

void WinWrapper::Destroy()
{
	delete[] m_pBitsFromGL;
	delete[] m_pBitsFromGLFlipY;
}


void WinWrapper::InitNotify(HWND hWnd)
{
	NOTIFYICONDATA nID = {};
	nID.hIcon = (HICON)LoadImage(NULL, TEXT("res/notify.ico"), IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
	wcscpy(nID.szTip, L"Welcome to Desktop War !");
	nID.hWnd = m_hWnd;
	nID.uID = 1;
	nID.uFlags = NIF_GUID | NIF_ICON | NIF_MESSAGE | NIF_TIP;
	nID.uCallbackMessage = WM_NOTIFY_ICON;
	Shell_NotifyIcon(NIM_ADD, &nID);
}

void WinWrapper::ShowTrayMenu()
{
	POINT pt;
	GetCursorPos(&pt);
	HMENU hMenu;
	hMenu = CreatePopupMenu();
	AppendMenu(hMenu, MF_STRING, IDM_EXIT, TEXT("傻么"));
	AppendMenu(hMenu, MF_SEPARATOR, 0, NULL);
	AppendMenu(hMenu, MF_STRING, IDM_ABOUT, TEXT("关于"));
	AppendMenu(hMenu, MF_SEPARATOR, 0, NULL);
	AppendMenu(hMenu, MF_STRING, IDM_EXIT, TEXT("退出"));
	AppendMenu(hMenu, MF_SEPARATOR, 0, NULL);
	TrackPopupMenu(hMenu, TPM_RIGHTBUTTON, pt.x, pt.y, NULL, m_hWnd, NULL);
}









