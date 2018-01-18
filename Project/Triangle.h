#pragma once

#include "Renderer.h"

class Triangle
{
public:
	Triangle(Renderer& renderer);
	~Triangle();

	void draw(Renderer& renderer);

private:
	void createMesh(Renderer& renderer);
	void createShader(Renderer& renderer);
	void createRenderStates(Renderer& renderer);

	ID3D11Buffer * m_vertexBuffer = nullptr;
	ID3D11VertexShader * m_vertexShader = nullptr;
	ID3D11PixelShader * m_pixelShader = nullptr;
	ID3D11InputLayout * m_inputLayout = nullptr;
	ID3D11RasterizerState* m_rasterizerState = nullptr;
	ID3D11DepthStencilState* m_depthState = nullptr;
	ID3D11BlendState* m_blendState = nullptr;
};

