
#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	//m_velocity.setX(1);
	//m_accelaration.setX(0.1);
}

void Player::draw()
{
	//Using SDLGameObject class to draw		
	SDLGameObject::draw();
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
}

void Player::update()
{
	//Mouse tracking
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position);
	
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	
	//Updating the acceleration and velocity vectors
	SDLGameObject::update();
}

void Player::clean()
{
	//Empty for now 
}