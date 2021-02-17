#pragma once
#include "SDLGameObject.h"


class Player: public SDLGameObject
{
public:

	Player(const LoaderParams* pParams);

	//draw()
	virtual void draw();

	//update()
	virtual void update();

	//clean()
	virtual	void clean();

};

