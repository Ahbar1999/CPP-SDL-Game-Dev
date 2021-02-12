#include "Game.h"


typedef TextureManager TheTextureManager;

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
		
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
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
		
		
		// to load
		if (!TheTextureManager::Instance()->load("Assets/run-anim.png", "animate", m_pRenderer))
		{
			return false;
		}

		return true;
	}
	else
	{
		
		return false;
	}

}



void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	//DRAWING STATIC IMAGE AT 0,0 i,e top left corner of the screen
	TheTextureManager::Instance()->draw("animate", 0, 0, 73, 92, m_pRenderer);

	//DRAWING ANIMATED SPRITE AT 100, 100
	TheTextureManager::Instance()->drawFrame("animate", 100, 100, 73, 92, 1, m_currentFrame, m_pRenderer);

	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{		
	//Updating our current frame, 0 <=  m_currentFrame <= 10	
	m_currentFrame = int(((SDL_GetTicks() / 60) % 10));
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
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
