#pragma once

#include <iostream>
#include <GameObject.h>

//A PLAYER CLASS WHICH INHERITS FROM THE GAMEOBJECT CLASS

class Player: public GameObject
{
public:

	//load()
	void load(int x, int y, int width, int height, std::string textureID);

	//draw()
	void draw(SDL_Renderer* pRenderer);

	//update()
	void update();

	//clean()
	void clean();

};

