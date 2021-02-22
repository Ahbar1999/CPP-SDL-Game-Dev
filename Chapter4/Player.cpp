
#include "Player.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Game.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	//m_velocity.setX(1);
	//m_accelaration.setX(0.1);
}

void Player::draw()
{
	//NOTE:
	//NOT using SDLGameObject class to draw	due to flip global flip issues	
	//SDLGameObject::draw();
	if (m_velocity.getX() > 0)
	{
		TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
	}
	else
	{
		TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
	}
}

void Player::handleInput()
{
	/*
	* JOYSTICK INPUT
	* PROBABLY WONT NEED IT SO I'M LEAVING IT UNFINISHED
	* 
		if (TheInputHandler::Instance()->joysticksInitialized())
			{
				if (TheInputHandler::Instance()->xvalue(0, 1) > 0 || TheInputHandler::Instance()->xvalue(0, 1) < 0)
				{
					m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0, 1));
				}
				if (TheInputHandler::Instance()->yvalue(0, 1) > 0 ||
					TheInputHandler::Instance()->yvalue(0, 1) < 0)
				{
					m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0,
						1));
				}
				if (TheInputHandler::Instance()->xvalue(0, 2) > 0 ||
					TheInputHandler::Instance()->xvalue(0, 2) < 0)
				{
					m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0,
						2));
				}
				if (TheInputHandler::Instance()->yvalue(0, 2) > 0 ||
					TheInputHandler::Instance()->yvalue(0, 2) < 0)
				{
					m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0, 2));
				}
			}
	*/

	//Mouse Input
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
	}

	//Keyboard Input
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
	{
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))
	{
		m_velocity.setY(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
	{
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
	{
		m_velocity.setX(2);
	}

	//Vector2D* target = TheInputHandler::Instance()->getMousePosition();

	//Finding relative velocity wrt position
	//m_velocity = *target - m_position;

	//m_velocity /= 50;
}

void Player::update()
{
	//Mouse tracking
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	//m_velocity = (*vec - m_position);
	
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	
	//Updating the acceleration and velocity vectors
	SDLGameObject::update();
}

void Player::clean()
{
	//Empty for now 
}