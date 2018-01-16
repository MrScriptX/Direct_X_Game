#include "Game.h"



Game::Game(Window &mainWindow) : m_window(mainWindow), m_renderer(mainWindow)
{

}


Game::~Game()
{
}

void Game::run()
{
	m_renderer.beginFrame();
	m_renderer.endFrame();
}
