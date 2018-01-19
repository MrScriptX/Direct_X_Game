#pragma once

#include "Window.h"
#include "Renderer.h"
#include "Model.h"


class Game
{
public:
	Game(Window  &mainWindow);
	~Game();

	void run();

private:
	Window& m_window;
	Renderer m_renderer;
	Model m_model;
};

