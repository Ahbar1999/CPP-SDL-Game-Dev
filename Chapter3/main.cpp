		
#include "Game.h"


//typedef Game TheGame;

int main(int argc, char* argv[]) //SDL uses cmd line params so it is needed to incude them somehow 
{
	
	if (TheGame::Instance()->init("Chapter 3", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false))
	{
		std::cout << "Game Init success! " << std::endl;
		
		while (TheGame::Instance()->running())
		{
			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();

			SDL_Delay(10);
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