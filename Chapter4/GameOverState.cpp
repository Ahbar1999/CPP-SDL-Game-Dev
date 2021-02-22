#include "GameOverState.h"
#include "Game.h"
#include "PlayState.h"
#include "MenuState.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::s_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

bool GameOverState::onEnter()
{
	//Gamer Over!! text that will appear on the screen
	if (!TextureManager::Instance()->load("Assets/gameover-anim.png", "gameovertext", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	//Resume button texture
	if (!TextureManager::Instance()->load("Assets/menu-anim.png", "menubutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	//Menu button texture, im using the same button texture that i have used for resume button
	if (!TextureManager::Instance()->load("Assets/resume-anim.png", "restartbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* gameOverText = new AnimatedGraphic(new LoaderParams(100, 100, 159, 65, "gameovertext"), 1);
	GameObject* button1 = new MenuButton(new LoaderParams(200, 200, 51, 51, "restartbutton"), s_restartPlay);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 51, 51, "menubutton"), s_gameOverToMain);

	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering GameOverState" << std::endl;
	return true;
}

void GameOverState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

void GameOverState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

bool GameOverState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("idle-player");

	std::cout << "Exiting GameOverState." << std::endl;
	return true;
}
