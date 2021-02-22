#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"

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

		//Initialise joysticks if joysticks implementation is available 
		//TheInputHandler::Instance()->initializeJoysticks();

		std::cout << "Init Success! " << std::endl;
		m_bRunning = true;
		
			
		// to load
		//if (!TheTextureManager::Instance()->load("Assets/run-anim.png", "animate", m_pRenderer))
		//{
			//return false;
		//}
		
		//m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 73, 92, "animate")));

		//m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 73, 92, "animate")));

		m_pGameStateMachine = new GameStateMachine();
		m_pGameStateMachine->changeState(new MenuState());

		return true;
	}
	else
	{
		
		return false;
	}

}

Game* Game::s_pInstance = 0;

void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	//NOTE: Instead of drawing through the list of gameObjects we will now draw with states
	//      and we will move this draw function/loop to state render functions
	/*
		for (std::vector<GameObject* >::size_type i = 0; i < m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->draw();
		}
	*/

	m_pGameStateMachine->render();

	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{	
	//Same with update function
	/*
		for (std::vector<GameObject* >::size_type i = 0; i < m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->update();
		}
	*/

	m_pGameStateMachine->update();
}

void Game::handleEvents()
{
	//We'll let TheInputHandler class do the work 
	TheInputHandler::Instance()->update();
	
	//Changing states prototype
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(new PlayState());
	}
}

void Game::quit()
{
	SDL_Quit();
}

void Game::clean()
{
	std::cout << "Cleaning Up!!" << std::endl;
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

