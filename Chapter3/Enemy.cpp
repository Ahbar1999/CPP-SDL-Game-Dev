
#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	m_x += 1;
	m_y += 1;
	m_currentFrame = int((SDL_GetTicks() / 60) % 10);
}

void Enemy::clean()
{
	//Empty for now 
}