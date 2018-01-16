#pragma once

#include <Windows.h>



class Window
{
public:
	Window(int width, int height);
	//~Window();

	HWND getHandle();
	
	
private:
	static LRESULT  CALLBACK WinProc(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam);
	//static LRESULT  CALLBACK WinProcSetup(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam);

	HWND m_handle;
};