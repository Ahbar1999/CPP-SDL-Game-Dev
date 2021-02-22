#pragma once
#include <string>

/*
* NOTE:
* AN ABSTRACT BASE CLASS FOR OUR GAME STATES/
*/

class GameState
{
public:

	/*NOTE:
	* note that the methods are purely virtual methods so a derived class must have them defined to work
	*/
	virtual void update() = 0;
	virtual void render() = 0;	

	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	
	virtual std::string getStateID() const = 0;
};

