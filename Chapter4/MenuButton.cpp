#include "MenuButton.h"
#include "InputHandler.h"
																								 //this initializes the m_callback = callback										
MenuButton::MenuButton(const LoaderParams* pParams, void (*callback)()): SDLGameObject(pParams), m_callback(callback)
{
	m_currentFrame = MOUSE_OUT; //Start at frame 0, MOUSE_OUT = 0
}

void MenuButton::draw()
{
	//Use the baseclass method for drawing
	SDLGameObject::draw();
}

void MenuButton::update()
{
	//Getting and Storing mouse's coordinates
	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

	//Checking if our mouse lies in our gameObject's rectangle
	if (pMousePos->getX() > m_position.getX() && pMousePos->getX() < m_position.getX() + m_width
	&& pMousePos->getY() > m_position.getY() && pMousePos->getY	() < m_position.getY() + m_height)
	{
		m_currentFrame = MOUSE_OUT;
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased)
		{
			m_currentFrame = CLICKED;

			m_callback(); //call our callback function

			m_bReleased = false;
		}
		else if(!TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_bReleased = true;
			m_currentFrame = MOUSE_OUT;
		}
		else
		{
			m_currentFrame = MOUSE_OUT;
		}
	}	
}

void MenuButton::clean()
{
	//Just Calling the base class' functions
	SDLGameObject::clean();
}



