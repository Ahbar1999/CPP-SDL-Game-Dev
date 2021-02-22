#pragma once
#include "SDLGameObject.h"


class MenuButton :    public SDLGameObject
{
public:
	MenuButton(const LoaderParams* pParams, void (*m_callback)());

	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	//function pointer
	void (*m_callback)();

	bool m_bReleased = true;

	//Mouse interaction states, 
	//I'm keeping only two states because i have only two frames in the sprite sheet
	enum button_state
	{
		MOUSE_OUT = 0,
		//MOUSE_OVER = 1,
		CLICKED = 1,
	};
};

