#pragma once

#include "Window.h"
#include "Renderer.h"


class Game
{
public:
	Game(Window  &mainWindow);
	~Game();

	void run();

private:
	Window &m_window;
	Renderer m_renderer;
};

