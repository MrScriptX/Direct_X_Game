#include "Game.h"



Game::Game(Window &mainWindow) : m_window(mainWindow), m_renderer(mainWindow), m_model(m_renderer)
{

}


Game::~Game()
{
}

void Game::run()
{
	m_renderer.beginFrame();

	m_model.draw(m_renderer);

	m_renderer.endFrame();
}
