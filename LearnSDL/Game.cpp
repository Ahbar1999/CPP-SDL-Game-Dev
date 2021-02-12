#include <Game.h>

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		std::cout << "SDL initialized successfully!" << std::endl;
		
		int flags = 0;

		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}
		
		m_pWindow = SDL_CreateWindow("Hello Window", xpos, ypos, width, height, flags);

		if (m_pWindow != 0)
		{
			std::cout << "Window created successfully" << std::endl;
			 
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
			{
				std::cout << "Renderer creation success!" << std::endl;
				SDL_SetRenderDrawColor(m_pRenderer, 0, 190, 255, 255);
			}
			else
			{
				std::cout << "Renderer initialization failed!" << std::endl;
				return false;
			}
		}
		else
		{
			std::cout << "SDL init failed !" << std::endl;
			return false;
		}

		std::cout << "Init Success! " << std::endl;
		m_bRunning = true;

		return true;

	}
	else
	{
		//SDL could not initialize 
		return false;
	}

	return true;
}



void Game::render()
{
	//Set the draw color, i am setting it to sky blue, ps. all the values rgba, are in decimals
	//SDL_SetRenderDrawColor(m_pRenderer, 0, 191, 255, 255);

	//Clearing the bg color
	SDL_RenderClear(m_pRenderer);

	//Show the window on the screen;
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{


}
void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			//SDL_QUIT automatically gets triggered when user clicks the cross button
			case SDL_QUIT:
				m_bRunning = false;
				break;


			default:
				break;
		}
	}

}
void Game::clean()
{
	std::cout << "Cleaning Up!!" << std::endl;
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();

}
