#include "Game.h"



Game::Game(Window &mainWindow) : m_window(mainWindow), m_renderer(mainWindow), m_triangle(m_renderer)
{

}


Game::~Game()
{
}

void Game::run()
{
	m_renderer.beginFrame();

	m_triangle.draw(m_renderer);

	m_renderer.endFrame();
}
