#pragma once
#include "GameState.h"
#include <vector>
#include "GameObject.h"

/*
* NOTE:
* The Menu State class derived from GameState
*/

class MenuState :    public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_menuID; }

private:
	static const std::string s_menuID;           
	std::vector<GameObject* > m_gameObjects;

	//callback functions for menu items
	static void s_menuToPlay();
	static void s_menuToExit();
};

