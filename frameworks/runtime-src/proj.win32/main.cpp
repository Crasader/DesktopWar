// DesktopWar.cpp : 定义应用程序的入口点。
//

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
// Windows 头文件: 
#include <windows.h>

// C 运行时头文件
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include "resource.h"

#define MAX_LOADSTRING 100

//#include<vld.h>
#include "WinWrapper.h"
#include "ConsolePanel.h"
#include "app/WarApp.h"

#pragma warning(disable:4251)

unsigned int g_FPS = 30;
WinWrapper g_winWrapper;
WarApp g_warApp;


// 全局变量: 
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名

// 此代码模块中包含的函数的前向声明: 
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	MSG msg;
	HACCEL hAccelTable;

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DESKTOPWAR, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化: 
	if (!InitInstance (hInstance, nCmdShow))
		return FALSE;

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DESKTOPWAR));

	// LOOP
	float interval = 1.0f / g_FPS;
	LARGE_INTEGER loopInterval;
	LARGE_INTEGER nFreq;
	QueryPerformanceFrequency(&nFreq);
	loopInterval.QuadPart = (LONGLONG)(interval * nFreq.QuadPart);

	LARGE_INTEGER nLast;
	LARGE_INTEGER nNow;
	QueryPerformanceCounter(&nLast);
	while (true)
	{
		QueryPerformanceCounter(&nNow);
		if (nNow.QuadPart - nLast.QuadPart > loopInterval.QuadPart)
		{
			nLast.QuadPart = nNow.QuadPart - (nNow.QuadPart % loopInterval.QuadPart);

			// game logic
			g_warApp.Tick(interval);
			g_winWrapper.Draw();

			// msg
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				if (msg.message == WM_QUIT)
					break;
				else
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}

		}
		else
		{
			Sleep(1);
		}
	}

	return (int) msg.wParam;
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   DWORD dwExStyle = WS_EX_TOOLWINDOW | WS_EX_TOPMOST | WS_EX_LAYERED /*| WS_EX_TRANSPARENT*/;
   DWORD dwStyle = WS_POPUP | WS_VISIBLE/* | WS_SYSMENU*/;
   //DWORD dwStyle = WS_OVERLAPPEDWINDOW;

   int screenWidth = GetSystemMetrics(SM_CXSCREEN);
   int screenHeight = GetSystemMetrics(SM_CYSCREEN);

   HWND hWnd = CreateWindowEx(dwExStyle, szWindowClass, szTitle, dwStyle,
	   0, 0, 128, 128, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   ////////////
   g_winWrapper.Init(hWnd);
   g_warApp.Init();
   ConsolePanel::GetInstance()->Init(hInstance);
   ////////////

   return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	//PAINTSTRUCT ps;
	//HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 分析菜单选择: 
		if (!g_winWrapper.ProcessCommand(wmId, wmEvent))
		{
			switch (wmId)
			{
			case IDM_ABOUT:
				DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
				break;
			case IDM_EXIT:
				DestroyWindow(hWnd);
				break;
			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
			}
		}
		break;
	case WM_MOUSEMOVE:
		// wParam为鼠标事件发生时的组合键状态  
		g_winWrapper.OnMouseMove(hWnd, LOWORD(lParam), HIWORD(lParam), (int)wParam);
		break;
	case WM_LBUTTONDOWN:
		g_winWrapper.OnMouseLButtonDown(hWnd, LOWORD(lParam), HIWORD(lParam), (int)wParam);
		break;
	case WM_LBUTTONUP:
		g_winWrapper.OnMouseLButtonUp(hWnd, LOWORD(lParam), HIWORD(lParam), (int)wParam);
		break;
	case WM_LBUTTONDBLCLK:
		g_winWrapper.OnMouseLButtonDoubleClick(hWnd, LOWORD(lParam), HIWORD(lParam), (int)wParam);
		break;
	case WM_TIMER:
		//ValidateRect(hWnd, NULL);
		break;
	case WM_PAINT:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		g_winWrapper.Destroy();
		g_warApp.Destroy();
		break;
	case WM_NOTIFY_ICON:
		switch (lParam)
		{
		case WM_RBUTTONDOWN:
			g_winWrapper.ShowTrayMenu();
			break;
		case WM_LBUTTONDBLCLK:
			g_winWrapper.OpenConsole(true);
			break;
		}
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}



ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DESKTOPWAR));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_DESKTOPWAR);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}