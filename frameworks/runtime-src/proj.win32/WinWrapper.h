
#pragma once

#ifndef _WINSOCK2API_
#define _WINSOCK2API_
//#define _WINSOCKAPI_ 
#endif

#include <windows.h>
#include <thread>
#include <mutex>

#define WM_NOTIFY_ICON WM_USER + 1

class WinWrapper
{
public:
	bool Init(HWND hWnd);
	void Draw();
	void Destroy();

	void ShowTrayMenu();
	bool ProcessCommand(int wmId, int wmEvent);
	void OpenConsole();

private:
	void InitNotify(HWND hWnd);
	void DrawGLBuffer();

private:
	HWND					m_hWnd;
	HDC						m_hDcSrc;
	HBITMAP				m_hBitmap;
	// gl buffer
	unsigned int*		m_pBitsFromGL;
	unsigned int*		m_pBitsFromGLFlipY;

};

