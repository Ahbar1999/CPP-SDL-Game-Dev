#pragma once
#include "GameState.h"
#include <vector>

/*
* NOTE:
* BUILDING OUR FINITE STATE MACHINE FOR OPERATING BETWEEN STATES
*/

class GameStateMachine :    public GameState
{
public:

	//For pushing a state on top of the other
	void pushState(GameState* pState);
	
	//For changing the state permanently from one/none to another thus removing the previous state
	void changeState(GameState* pState);
	
	//For removing a state
	void popState();

	//Overriding base class methods
	void render();
	void update();
	bool onEnter();
	bool onExit();

private:

	//For storing our game states
	std::vector<GameState* > m_gameStates;
	
	//Overriding base class method
	std::string getStateID() const;
};

