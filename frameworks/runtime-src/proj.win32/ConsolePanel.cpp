
#include "ConsolePanel.h"
#include "resource.h"

const static int ConsoleWidth = 640;
const static int ConsoleHeight = 480;
HDC memDC;
HBITMAP hBigBee;

ConsolePanel* ConsolePanel::GetInstance()
{
	static ConsolePanel inst;
	return &inst;
}


void ConsolePanel::Init(HINSTANCE hInstance)
{
	if (bInited)return;
	bInited = true;

	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = ConsolePanel::WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DESKTOPWAR));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = L"";
	wcex.lpszClassName = L"Console";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	RegisterClassEx(&wcex);

	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	
	hWnd = CreateWindowEx(0,
		L"Console", L"ConsolePanel", WS_OVERLAPPEDWINDOW,
		screenWidth - ConsoleWidth - 100, screenHeight - ConsoleHeight - 100, 
		ConsoleWidth, ConsoleHeight, NULL, NULL, hInstance, NULL);

	HDC hdc = GetDC(hWnd);
	memDC = CreateCompatibleDC(hdc);

	hBigBee = (HBITMAP)LoadImage(
		NULL,
		L"1.bmp",
		IMAGE_BITMAP,
		ConsoleWidth,
		ConsoleHeight,
		LR_LOADFROMFILE);

	SetupRegion(RGB(0, 0, 0));
	//HRGN hRgn = BitmapToRegion(hBigBee, RGB(245, 245, 245), RGB(10, 10, 10));
	//SetWindowRgn(hWnd, hRgn, FALSE);

	ShowWindow(hWnd, SW_HIDE);
}


void ConsolePanel::SetVisible(bool visible)
{
	ShowWindow(hWnd, visible ? SW_SHOWNORMAL : SW_HIDE);
}

LRESULT CALLBACK ConsolePanel::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		SelectObject(memDC, hBigBee);
		BitBlt(hdc,0,0,ConsoleWidth,ConsoleHeight,memDC,0,0,SRCCOPY);

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void ConsolePanel::SetupRegion(COLORREF TransColor)
{
	HBITMAP hBitmap = hBigBee;

	HBITMAP  pOldMemBmp = (HBITMAP)SelectObject(memDC, hBitmap);
	HRGN wndRgn = CreateRectRgn(0, 0, 0, 0);
	BITMAP bit;
	GetObject(hBitmap, sizeof(bit), &bit);
	int y;
	for (y = 0; y <= bit.bmHeight; y++)
	{
		HRGN rgnTemp;
		int iX = 0;
		do
		{
			while (iX <= bit.bmWidth && GetPixel(memDC, iX, y) == TransColor)
				iX++;
			int iLeftX = iX;
			while (iX <= bit.bmWidth && GetPixel(memDC, iX, y) != TransColor)
				++iX;
			rgnTemp = CreateRectRgn(iLeftX, y, iX + 1, y + 1);
			CombineRgn(wndRgn, wndRgn, rgnTemp, RGN_OR);
			DeleteObject(rgnTemp);
		} while (iX <= bit.bmWidth);
	}
	SelectObject(memDC, pOldMemBmp);
	SetWindowRgn(hWnd, wndRgn, FALSE);
}
