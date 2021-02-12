#pragma once
#ifndef __Game__
#define __Game__

#include <iostream>
#include <SDL/include/SDL.h>

class Game
{
public:

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }

private:

	bool m_bRunning;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
};



#endif // Defined __Game__
