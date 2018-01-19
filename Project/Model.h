#pragma once

#include "Mesh.h"

class Model
{
public:
	Model();
	~Model();

	void RenderBuffer(ID3D11DeviceContext * deviceContext);
	void LoadTexture(ID3D11Device * device, WCHAR filename);
	void ReleaseTexture()
private:
	
};

