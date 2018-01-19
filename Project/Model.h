#pragma once

#include <vector>
#include "Mesh.h"

class Model
{
public:
	Model();
	~Model();

	void addMesh(Mesh * mesh);

	void RenderBuffer(ID3D11DeviceContext * deviceContext);
	void LoadTexture(ID3D11Device * device, WCHAR filename);
	void ReleaseTexture();
private:
	std::vector<Mesh*> m_meshes;
};

