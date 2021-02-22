#include "PauseState.h"
#include "Game.h"
#include "MenuState.h"
#include "MenuButton.h"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void PauseState::s_resumePlay()
{
	TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PauseState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PauseState::onEnter()
{
	//Loading resume button texture
	if (!TextureManager::Instance()->load("Assets/resume-anim.png", "resumeButton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	//Loading menu button texture
	if (!TextureManager::Instance()->load("Assets/menu-anim.png", "menuButton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	//Creating a GameObject instance out of them
	GameObject* button2 = new MenuButton(new LoaderParams(200, 200, 51, 51, "resumeButton"), s_resumePlay);
	GameObject* button1 = new MenuButton(new LoaderParams(200, 100, 51, 51, "menuButton"), s_pauseToMain);

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	
	std::cout << "Entering the Pause state." << std::endl;
	return true;
}

bool PauseState::onExit()
{
	std::cout << "Exiting Play State." << std::endl;

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("resumeButton");
	TheTextureManager::Instance()->clearFromTextureMap("menuButton");
	
	//Reset the mouse button states to false
	TheInputHandler::Instance()->reset();

	return true;
}







