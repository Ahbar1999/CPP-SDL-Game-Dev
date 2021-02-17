		
#include "Game.h"


const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;


int main(int argc, char* argv[]) //SDL uses cmd line params so it is needed to incude them somehow 
{
	unsigned int frameTime, frameStart;
	
	if (TheGame::Instance()->init("Chapter 4", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false))
	{
		std::cout << "Game Init success! " << std::endl;
		
		while (TheGame::Instance()->running())
		{
			frameStart = SDL_GetTicks();

			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;
			
			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}

	}
	else
	{

		std::cout << "Game init failure!" << SDL_GetError() << std::endl;
		return -1;
	}

	std::cout << "Game closing ! " << std::endl;
	TheGame::Instance()->clean();
	
	return 0;
}