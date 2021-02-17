
#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Player::draw()
{
	//Using SDLGameObject class to draw
	SDLGameObject::draw();
}

void Player::update()
{
	m_x -= 1;
	m_currentFrame = int((SDL_GetTicks()/60) % 10);
}

void Player::clean()
{
	//Empty for now 
}