#pragma once

#include "Window.h"
#include "Renderer.h"
#include "Triangle.h"


class Game
{
public:
	Game(Window  &mainWindow);
	~Game();

	void run();

private:
	Window& m_window;
	Renderer m_renderer;
	Triangle m_triangle;
};

