#include "Window.h"
#include "Renderer.h"
#include "Game.h"


int CALLBACK WinMain(HINSTANCE appInstance, HINSTANCE prevInstance, LPSTR cmdLine, int cmdCount)//callback?
{
	Window window(1260, 720);
	Game game(window);

	MSG msg = { 0 };

	while (true)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
			{
				break;
			}
		}

		game.run();
	}

	return 0;
}