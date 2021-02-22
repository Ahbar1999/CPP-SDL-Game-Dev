#include "PlayState.h"
#include <iostream>
#include "TextureManager.h"
#include "Game.h"
#include "PauseState.h"
#include "GameOverState.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
} 

void PlayState::update()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		//Remember that pushState does not remove the old state; 
		//it merely stops using it and uses the new state
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}
	
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[1])))
	{	
		TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
	}
}

//Collision Detection and Resolution
bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	//Variables for storing the sides/edges of the rectangles of p1 and p2
	int leftP1, leftP2,		//left edges
		rightP1, rightP2,   //right edges
		topP1, topP2,		//top edges
		bottomP1, bottomP2; //bottom edges

	//Edges of rectangle of p1
	leftP1 = p1->getPosition().getX();
	rightP1 = p1->getPosition().getX() + p1->getWidth();
	topP1 = p1->getPosition().getY();
	bottomP1 = p1->getPosition().getY() + p1->getHeight();
	
	//Edges of rectangle of p2
	leftP2 = p2->getPosition().getX();
	rightP2 = p2->getPosition().getX() + p2->getWidth();
	topP2 = p2->getPosition().getY();
	bottomP2 = p2->getPosition().getY() + p2->getHeight();

	if (bottomP1 <= topP2) { return false; } //if bottom of p1 is above top of p2 then the box of p1 has to be outside of p2
	if (topP1 >= bottomP2) { return false; } //if top of p2 is below bottom of p2 then the box of p1 has to be outside of p2
	if (rightP1 <= leftP2) { return false; } //if left edge of p2 is farther on right than right edge of p2 then p1 has to be outside of p2
	if (leftP1 >= rightP2) { return false; } //if left edge of p1 is farther on right than right edge of p2 then p1 has to be outside of p2 

	//If none of the above conditions are true then collision has occured
	std::cout << "Collision detected!!! " << std::endl;
	
	return true;
}

bool PlayState::onEnter()
{	
	if (!TheTextureManager::Instance()->load("Assets/run-anim.png", "player", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("Assets/zombies-walk-anim.png", "enemy", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* player = new Player(new LoaderParams(100, 100, 73, 92, "player"));
	GameObject* enemy = new Enemy(new LoaderParams(400, 100, 86, 103, "enemy"));
	
	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy);
		
	std::cout << "Entering PlayState." << std::endl;
	
	return true;
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("idle-player");

	std::cout << "Exiting PlayState." << std::endl;

	return true;
}