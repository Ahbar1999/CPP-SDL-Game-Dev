#pragma once
#include "SDLGameObject.h"


class Enemy : public SDLGameObject
{
public:

	Enemy(const LoaderParams* pParams);

	//void load(int x, int y, int width, int height, std::string textureID);
	virtual void draw();
	virtual	void update();
	virtual	void clean();
};

