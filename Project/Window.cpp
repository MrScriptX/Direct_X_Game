#include "Window.h"




Window::Window(int width, int height)
{
	//Define window style
	WNDCLASSEX wc = { sizeof(WNDCLASSEX),CS_VREDRAW | CS_HREDRAW | CS_CLASSDC, WinProc, 0, 0, 0, nullptr, nullptr, nullptr, nullptr, "DX11", nullptr};//WINDCLASSx use with CreateWindowEx
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	RegisterClassEx(&wc);//RegisterClassEx

	//Create window
	m_handle = CreateWindowEx(0 ,"DX11", "Ma fenetre", WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_VISIBLE, 100, 100, width, height, nullptr, nullptr, nullptr, nullptr);//return HWND
}

HWND Window::getHandle()
{
	return m_handle;
}

LRESULT CALLBACK Window::WinProc(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam)
{
	if (msg == WM_DESTROY || msg == WM_CLOSE)
	{
		PostQuitMessage(0);
	}

	return DefWindowProc(handle, msg, wparam, lparam);
}


