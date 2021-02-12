		
#include "Game.h"

Game* g_game = 0;


int main(int argc, char* argv[]) //SDL uses cmd line params so it is needed to incude them somehow 
{
	g_game = new Game();

	g_game->init("Chapter 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);


	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	g_game->clean();
	
	return 0;
}