#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState* pState)
{
	//storing our new State
	m_gameStates.push_back(pState);
	
	//Loading our new State
	m_gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
	if (!m_gameStates.empty())
	{
		if (m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}
}

void GameStateMachine::changeState(GameState* pState)
{
	//Check if there's a currently loaded state
	if (!m_gameStates.empty())
	{
		//If the current state and the requested state are same then just return/ do nothing
		if (m_gameStates.back()->getStateID() == pState->getStateID())
		{
			//Do Nothing
			return;
		}

		//Delete the present state
		if (m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}

	//Push back and load our new state
	m_gameStates.push_back(pState);
	pState->onEnter();
}


//Overridden functions from the base class GameState
void GameStateMachine::render()
{
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->render();
	}
}

void GameStateMachine::update()
{
	if (!m_gameStates.empty())
	{
		//Just calling the current state's update function nothing explicit
		m_gameStates.back()->update();
	}
}

bool GameStateMachine::onEnter()
{
	//Empty
	return true;
}

bool GameStateMachine::onExit()
{
	//Empty
	return true;
}

std::string GameStateMachine::getStateID() const
{
	//Empty
	return "Empty";
}