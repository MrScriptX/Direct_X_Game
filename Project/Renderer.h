#pragma once

#include <d3d11.h>
#include "Window.h"


class Renderer
{
public:
	Renderer(Window &window);
	void beginFrame();
	void endFrame();

	ID3D11Device * getDevice();
	ID3D11DeviceContext * getDeviceContext();

private:
	void createDevice(Window& window);
	void createRenderTarget();

	ID3D11Device * m_device					= nullptr;
	ID3D11DeviceContext * m_deviceContext	= nullptr;
	IDXGISwapChain * m_swapChain			= nullptr;

	ID3D11RenderTargetView* m_renderTargetView = nullptr;
};