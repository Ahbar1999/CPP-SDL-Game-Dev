#pragma once

/*
* ABSTRACT GameObject CLASS
*/

#include <iostream>
#include <SDL/include/SDL.h>
#include <SDL/include/SDL_image.h>
#include <LoaderParams.h>

class GameObject
{
public:
	
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual	void clean() = 0;

protected:

	GameObject(const LoaderParams* pParams){}
	virtual ~GameObject() {}
};

