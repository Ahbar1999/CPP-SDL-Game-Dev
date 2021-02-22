#pragma once
#include "GameState.h"
#include <vector>
#include "SDLGameObject.h"

class PlayState :    public GameState
{
public:
	virtual void render();
	virtual void update();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_playID; }
	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);

private:
	static const std::string s_playID;	
	std::vector<GameObject*> m_gameObjects;
};

