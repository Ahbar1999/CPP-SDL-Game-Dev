
#include "Enemy.h"
#include "TextureManager.h"
#include "Game.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	//m_velocity.setY(2);
	m_velocity.setX(-2);
}

void Enemy::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);

	//SDLGameObject::draw();
}

void Enemy::update()
{
	m_currentFrame = int((SDL_GetTicks() / 60) % 10);
	
	/*
		if (m_velocity.getY() < 0)
		{
			m_velocity.setY(2);
		}
		else if (m_position.getY() > 400)
		{
			m_velocity.setY(-2);
		}
	*/
	SDLGameObject::update();
}

void Enemy::clean()
{
	//Empty for now 
}