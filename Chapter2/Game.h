#pragma once
#ifndef __Game__
#define __Game__

#include <iostream>
#include <SDL/include/SDL_image.h>
#include <SDL/include/SDL.h>
#include "TextureManager.h"

class Game
{
public:

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
	int m_currentFrame;
	int m_currentRow;
	
private:

	bool m_bRunning = false;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

};



#endif // Defined __Game__
