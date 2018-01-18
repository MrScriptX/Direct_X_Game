#include "Renderer.h"



Renderer::Renderer(Window &window)
{
	createDevice(window);
	createRenderTarget();
}

void Renderer::beginFrame()
{
	//Bind render target
	m_deviceContext->OMSetRenderTargets(1, &m_renderTargetView, nullptr);

	//set viewport
	CD3D11_VIEWPORT viewport = CD3D11_VIEWPORT(0.0f, 0.0f, 800.0f, 600.0f);
	m_deviceContext->RSSetViewports(1, &viewport);

	float clearColor[] = { 0.0f, 0.0f, 0.0f, 1 };
	m_deviceContext->ClearRenderTargetView(m_renderTargetView, clearColor);
}

void Renderer::endFrame()
{
	m_swapChain->Present(1, 0);
}

ID3D11Device * Renderer::getDevice()
{
	return m_device;
}

ID3D11DeviceContext * Renderer::getDeviceContext()
{
	return m_deviceContext;
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
