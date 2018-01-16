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


/*LRESULT CALLBACK Window::WinProcSetup(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam)
{
	if (msg == WM_NCCREATE)
	{
		CREATESTRUCTW const* pParam = reinterpret_cast<CREATESTRUCTW const*>(lparam);//store param of actual win
		Window* const pWindow = reinterpret_cast<Window*>(pParam->lpCreateParams);//create a new "memory" window with stored param

		SetWindowLongPtr(handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWindow));//store userdata

		Window* const pWnd = reinterpret_cast<Window*>(GetWindowLongPtr(handle, GWLP_USERDATA));//create a new "memory" window with user data
		SetWindowLongPtr(handle, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(pWnd));//store adress of window

		return pWnd->WinProc(handle, msg, wparam, lparam);
	}


	return DefWindowProc(handle, msg, wparam, lparam);
}*/

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


