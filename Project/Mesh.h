#pragma once

#include <d3d11.h>
#include <DirectXMath.h>
#include "Renderer.h"


struct Vertex
{
	float x, y, z;
	float texX, texY;
};

class Mesh
{
public:
	Mesh(Renderer& renderer);
	~Mesh();

	void setMesh(Vertex& mesh, unsigned long& indices);
	void setIndexCount(int count);
	void setVertexCount(int count);

private:
	void InitBuffer();

	Renderer * m_renderer = nullptr;
	ID3D11Buffer * m_vertexBuffer = nullptr;
	ID3D11Buffer * m_indexBuffer = nullptr;
	
	int m_indexCount = 0;
	int m_vertexCount = 0;

	Vertex * m_mesh;
	unsigned long * m_indices;
};

