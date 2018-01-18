#include "Triangle.h"
#include <fstream>
#include <vector>

struct Vertex
{
	float x, y;
	float r, g, b;
};

Triangle::Triangle(Renderer& renderer)
{
	createMesh(renderer);
	createShader(renderer);
	createRenderStates(renderer);
}


Triangle::~Triangle()
{
	m_vertexBuffer->Release();
	m_vertexShader->Release();
	m_pixelShader->Release();
	m_inputLayout->Release();
	m_rasterizerState->Release();
	m_depthState->Release();
	m_blendState->Release();
}

void Triangle::draw(Renderer & renderer)
{
	renderer.getDeviceContext()->RSSetState(m_rasterizerState);
	renderer.getDeviceContext()->OMSetBlendState(m_blendState, NULL, 0xffffffff);
	renderer.getDeviceContext()->OMSetDepthStencilState(m_depthState, 1);

	//Bind Triangle shader
	renderer.getDeviceContext()->IASetInputLayout(m_inputLayout);
	renderer.getDeviceContext()->VSSetShader(m_vertexShader, nullptr, 0);
	renderer.getDeviceContext()->PSSetShader(m_pixelShader, nullptr, 0);

	//Bind our vertex buffer
	UINT stride = sizeof(Vertex);//size between each vertex
	UINT offset = 0;

	renderer.getDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_POINTLIST);
	renderer.getDeviceContext()->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);
	renderer.getDeviceContext()->Draw(3, 0);
}

void Triangle::createMesh(Renderer & renderer)
{
	Vertex vertices[] = { { -1, -1, 1, 0, 0 },{ 0, 1, 0, 1, 0 } ,{ 1, -1, 0, 0, 1 } }; //triangle
																			   //Create our vertex buffer
	CD3D11_BUFFER_DESC vertexBufferDesc = CD3D11_BUFFER_DESC(sizeof(vertices), D3D11_BIND_VERTEX_BUFFER);
	D3D11_SUBRESOURCE_DATA vertexData = { 0 };
	vertexData.pSysMem = vertices;

	renderer.getDevice()->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
}

void Triangle::createShader(Renderer & renderer)
{
	std::ifstream vsFile("VertexShader.cso", std::ios::binary);
	std::vector<char> vsData = { std::istreambuf_iterator<char>(vsFile), std::istreambuf_iterator<char>() };

	std::ifstream psFile("PixelShader.cso", std::ios::binary);
	std::vector<char> psData = { std::istreambuf_iterator<char>(psFile), std::istreambuf_iterator<char>() };

	renderer.getDevice()->CreateVertexShader(vsData.data(), vsData.size(), nullptr, &m_vertexShader);
	renderer.getDevice()->CreatePixelShader(psData.data(), psData.size(), nullptr, &m_pixelShader);

	//input Layout
	D3D11_INPUT_ELEMENT_DESC layout[]{ { "POSITION", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
							{ "COLOR", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 } };

	renderer.getDevice()->CreateInputLayout(layout, 2, vsData.data(), vsData.size(), &m_inputLayout);
}

void Triangle::createRenderStates(Renderer& renderer) {
	// Rasterizer state
	auto rasterizerDesc = CD3D11_RASTERIZER_DESC(
		D3D11_FILL_SOLID,
		D3D11_CULL_NONE,
		false,
		0, 0, 0, 0,
		false, false, false);
	renderer.getDevice()->CreateRasterizerState(&rasterizerDesc, &m_rasterizerState);

	// Blend state
	auto blendDesc = CD3D11_BLEND_DESC(CD3D11_DEFAULT());
	renderer.getDevice()->CreateBlendState(&blendDesc, &m_blendState);

	// Depth state
	auto depthDesc = CD3D11_DEPTH_STENCIL_DESC(
		FALSE, D3D11_DEPTH_WRITE_MASK_ZERO, D3D11_COMPARISON_LESS,
		FALSE, D3D11_DEFAULT_STENCIL_READ_MASK, D3D11_DEFAULT_STENCIL_WRITE_MASK,
		D3D11_STENCIL_OP_KEEP, D3D11_STENCIL_OP_KEEP, D3D11_STENCIL_OP_KEEP, D3D11_COMPARISON_ALWAYS,
		D3D11_STENCIL_OP_KEEP, D3D11_STENCIL_OP_KEEP, D3D11_STENCIL_OP_KEEP, D3D11_COMPARISON_ALWAYS);
	renderer.getDevice()->CreateDepthStencilState(&depthDesc, &m_depthState);
}
