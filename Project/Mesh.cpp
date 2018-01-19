#include "Mesh.h"



Mesh::Mesh(Renderer& renderer): m_renderer(&renderer)
{
}


Mesh::~Mesh()
{
	m_vertexBuffer->Release();
	m_indexBuffer->Release();
}

void Mesh::setMesh(Vertex& mesh)
{
	m_mesh = &mesh;//get the mesh
}

void Mesh::setIndexCount(int count)
{

}

void Mesh::setVertexCount(int count)
{

}

void Mesh::InitBuffer()
{
	CD3D11_BUFFER_DESC vertexBufferDesc = CD3D11_BUFFER_DESC(sizeof(m_mesh), D3D11_BIND_VERTEX_BUFFER);
	CD3D11_BUFFER_DESC indexBufferDesc = CD3D11_BUFFER_DESC(sizeof(m_mesh), D3D11_BIND_INDEX_BUFFER);

	D3D11_SUBRESOURCE_DATA vertexData = { 0 };
	D3D11_SUBRESOURCE_DATA indexData = { 0 };

	//vertex
	vertexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	vertexBufferDesc.ByteWidth = sizeof(vertexData) * m_vertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	vertexData.pSysMem = m_mesh;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	m_renderer->getDevice()->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);

	//index
	indexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	indexBufferDesc.ByteWidth = sizeof(indexData) * m_indexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	indexData.pSysMem = m_indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	m_renderer->getDevice()->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);

	delete[] m_mesh;
	m_mesh = 0;

	delete[] m_indices;
	m_indices = 0;
}
