#pragma once

#include <Windows.h>

//ÓÎÏ·²Ù×÷´°¿Ú

class ConsolePanel
{
public:
	static ConsolePanel* GetInstance();

	void Init(HINSTANCE hInstance);
	void SetVisible(bool visible);

	static LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

private:
	ConsolePanel() :
		bInited(false)
	{}

	void SetupRegion(COLORREF TransColor);

private:
	HWND hWnd;
	bool bInited;
};

