#include "Renderer.h"



Renderer::Renderer(Window &window)
{
	createDevice(window);
	createRenderTarget();
}

void Renderer::beginFrame()
{
	float clearColor[] = { 0.0f, 0.0f, 0.0f, 1 };
	m_deviceContext->ClearRenderTargetView(m_renderTargetView, clearColor);
}

void Renderer::endFrame()
{
	m_swapChain->Present(1, 0);
}

void Renderer::createDevice(Window & window)
{
	DXGI_SWAP_CHAIN_DESC swapChainDesc = { 0 };
	swapChainDesc.BufferCount = 1;//number of back buffer
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = window.getHandle();
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.Windowed = true;

	D3D11CreateDeviceAndSwapChain(
		nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0,
		D3D11_SDK_VERSION, &swapChainDesc, &m_swapChain, &m_device,
		nullptr, &m_deviceContext);
}

void Renderer::createRenderTarget()
{
	ID3D11Texture2D* backBuffer;
	m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);
	m_device->CreateRenderTargetView(backBuffer, nullptr, &m_renderTargetView);
	backBuffer->Release();
}
