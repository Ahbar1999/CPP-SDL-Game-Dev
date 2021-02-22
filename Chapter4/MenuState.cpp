#include "MenuState.h"
#include <iostream>
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"
#include "PlayState.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
	//Just loop through all the objects and call their update methods 
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	//Call the draw methods
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

}
bool MenuState::onEnter()
{

	if (!TheTextureManager::Instance()->load("Assets/PlayButton-anim.png", "playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	
	if (!TheTextureManager::Instance()->load("Assets/QuitButton-anim.png", "quitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	
	GameObject* button1 = new MenuButton(new LoaderParams(200, 100, 204, 153, "playbutton"), s_menuToPlay);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 204, 153, "quitbutton"), s_menuToExit);
	
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "Entering Menu State." << std::endl;
	return true;
}

bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()->clearFromTextureMap("exitbutton");
		
	std::cout << "Exiting Menu State." << std::endl;
	return true;
}

void MenuState::s_menuToPlay()
{
	std::cout << "Play button clicked" << std::endl;

	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

//Exit the game
void MenuState::s_menuToExit()
{
	//
	std::cout << "Quit/Exit button clicked" << std::endl;
	TheGame::Instance()->quit();
}

