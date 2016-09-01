
#include "WinWrapper.h"
#include "ConsolePanel.h"
#include "gfx/gfx.h"
#include "glfw3native.h"
#include "app/GameDefine.h"
#include "Resource.h"



const int		cfg_TaskBarHeight = 40;

#define IDM_CONSOLE 10001


bool WinWrapper::Init(HWND hWnd)
{
	do
	{
		m_hWnd = hWnd;
		InitNotify(hWnd);

		GameDefine::viewWidth = GetSystemMetrics(SM_CXSCREEN);
		GameDefine::viewHeight = GetSystemMetrics(SM_CYSCREEN) - cfg_TaskBarHeight;

		int glWidth = GameDefine::viewWidth;
		int glHeight = GameDefine::viewHeight;
		m_pBitsFromGL = new unsigned int[glWidth * glHeight];
		m_pBitsFromGLFlipY = new unsigned int[glWidth * glHeight];

		HDC hdcDest = GetDC(m_hWnd);
		m_hDcSrc = CreateCompatibleDC(hdcDest);
		m_hBitmap = CreateCompatibleBitmap(hdcDest, glWidth, glHeight);
		SelectObject(m_hDcSrc, m_hBitmap);

	} while (false);

	return false;
}


void WinWrapper::Draw()
{
	// Copy GL buffer.
	// 不要幻想优化这里的效率，因为罪魁祸首gl操作无法优化！！记住！
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
	AppendMenu(hMenu, MF_STRING, IDM_CONSOLE, TEXT("console"));
	AppendMenu(hMenu, MF_SEPARATOR, 0, NULL);
	AppendMenu(hMenu, MF_STRING, IDM_ABOUT, TEXT("about"));
	AppendMenu(hMenu, MF_SEPARATOR, 0, NULL);
	AppendMenu(hMenu, MF_STRING, IDM_EXIT, TEXT("exit"));
	AppendMenu(hMenu, MF_SEPARATOR, 0, NULL);
	TrackPopupMenu(hMenu, TPM_RIGHTBUTTON, pt.x, pt.y, NULL, m_hWnd, NULL);
}

bool WinWrapper::ProcessCommand(int wmId, int wmEvent)
{
	switch (wmId)
	{
	case IDM_CONSOLE:
		OpenConsole(true);
		break;
	default:
		return false;
		break;
	}
	return true;
}

void WinWrapper::OpenConsole(bool open)
{
	ConsolePanel::GetInstance()->SetVisible(open);
}


static POINT g_pntMouse = { 0, 0 };

// 保存指针移动时, 组合键的标识,   
// 组合键有  
//  
// MK_CONTROL(Ctrl键)   
// MK_SHIFT(Shift键),  
// MK_LBUTTON(鼠标左键),  
// MB_RBUTTON(鼠标右键)  
static int g_nMark = 0;

// 保存在操作鼠标按键时, 鼠标指针的位置  
static POINT g_pntL = { 0, 0 };

// 保存操作鼠标按键时, 组合键的标识  
// 组合键有  
//  
// MK_CONTROL(Ctrl键)  
// MK_SHIFT(Shift键)  
static int g_nMarkL = 0;


void WinWrapper::OnMouseMove(HWND hWnd, int x, int y, int nMark)
{
	g_pntMouse.x = x;
	g_pntMouse.y = y;
	g_nMark = nMark;
	//printf("move %d,%d",x,y);
}


void WinWrapper::OnMouseLButtonDown(HWND hWnd, int x, int y, int nMark)
{
	g_pntL.x = x;
	g_pntL.y = y;
	g_nMarkL = nMark;
	printf("ld %d,%d", x, y);
}


void WinWrapper::OnMouseLButtonUp(HWND hWnd, int x, int y, int nMark)
{
	g_pntL.x = x;
	g_pntL.y = y;
	g_nMarkL = nMark;
	printf("lu %d,%d", x, y);
}


void WinWrapper::OnMouseLButtonDoubleClick(HWND hWnd, int x, int y, int nMark)
{
	g_pntL.x = x;
	g_pntL.y = y;
	g_nMarkL = nMark;
	printf("db %d,%d", x, y);
}
/*
static void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int modify)
{
if (_view)
_view->onGLFWMouseCallBack(window, button, action, modify);
}

static void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y)
{
if (_view)
_view->onGLFWMouseMoveCallBack(window, x, y);
}

static void onGLFWMouseScrollCallback(GLFWwindow* window, double x, double y)
{
if (_view)
_view->onGLFWMouseScrollCallback(window, x, y);
}
*/




