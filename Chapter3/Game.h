#pragma once
#ifndef __Game__
#define __Game__

/*
* A SINGLETON CLASS
*/

#include <iostream>
#include <vector>
#include <SDL/include/SDL_image.h>
#include <SDL/include/SDL.h>
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"

typedef class Game
{
public:

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}

		return s_pInstance;
	}

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }

	int m_currentFrame;
	int m_currentRow;

	std::vector<GameObject*> m_gameObjects;
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

private:

	Game() {};
	static Game* s_pInstance;

	bool m_bRunning = false;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

} TheGame;



#endif // Defined __Game__
