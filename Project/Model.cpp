#include "Model.h"



Model::Model()
{

}


Model::~Model()
{

}

void Model::addMesh(Mesh * mesh)
{
	m_meshes.push_back(mesh);
}

void Model::RenderBuffer(ID3D11DeviceContext * deviceContext)
{

}

void Model::LoadTexture(ID3D11Device * device, WCHAR filename)
{

}

void Model::ReleaseTexture()
{

}
