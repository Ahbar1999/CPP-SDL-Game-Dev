#include "InputHandler.h"
#include "Game.h"



void InputHandler::update()
{
	SDL_Event event;
	m_keystates = SDL_GetKeyboardState(0);

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		
		case SDL_MOUSEMOTION:
			onMouseMove(event);
			break;

		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown(event);
			break;

		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
			break;

		case SDL_KEYDOWN:
			onKeyDown();
			break;

		case SDL_KEYUP:
			onKeyUP();
			break;

		default:
			break;
		}
	}
}


void InputHandler::clean()
{
	/*
		if (m_bJoysticksInitialised)
		{
			for (int i = 0; i < m_Joysticks.size(); i++)
			{
				SDL_JoystickClose(m_Joysticks[i]);
			}
		}
	*/
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (m_keystates != 0)
	{
		if (m_keystates[key] == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	return false;
}

void InputHandler::onMouseButtonDown(SDL_Event& event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = true;
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = true;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = true;
	}
}

void InputHandler::onMouseButtonUp(SDL_Event& event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = false;
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] == false;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = false;
	}
}

void InputHandler::onKeyDown()
{

}

void InputHandler::onKeyUP()
{

}

void InputHandler::onMouseMove(SDL_Event& event)
{
	m_mousePosition->setX(event.motion.x);
	m_mousePosition->setY(event.motion.y);
}

InputHandler* InputHandler::s_pInstance = 0;

//-------------------------------------------------
/*
* NOTE
*/

//Useless functions below, never gonna use a joystick


/* 
	void InputHandler::initializeJoysticks()
	{
		//Initialise the Joystick subsystem if it hasnt been already
		if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
		{
			SDL_InitSubSystem(SDL_INIT_JOYSTICK);
		}

		//Check for any currently plugged-in joysticks
		if (SDL_NumJoysticks() > 0)
		{
			//Loop through all of them
			for (int i = 0; i < SDL_NumJoysticks(); i++)
			{
				//Initialising the joystick and storing the pointer to the joystick for later use
				SDL_Joystick* joy = SDL_JoystickOpen(i);
				if (joy != NULL)
				{
					m_Joysticks.push_back(joy);
					m_joystickValues.push_back(std::make_pair(new Vector2D(0, 0), new Vector2D(0, 0)));
				
				}
				else
				{
					std::cout << SDL_GetError() << std::endl;
				}
			}

			SDL_JoystickEventState(SDL_ENABLE);
			m_bJoysticksInitialised = true;
			std::cout << "Initialised" << m_Joysticks.size() << "joystick(s)" << std::endl;
		
		}
		else
		{
			m_bJoysticksInitialised = false;
		}
	}  

	int InputHandler::xvalue(int joy, int stick)
	{
		if (m_joystickValues.size() > 0)
		{
			if (stick == 1)
			{
				return m_joystickValues[joy].first->getX();
			}
			else if (stick == 2)
			{
				return m_joystickValues[joy].second->getX();
			}
		}

		return 0;

	}

	int InputHandler::yvalue(int joy, int stick)
	{
		if (m_joystickValues.size() > 0)
		{
			if (stick == 1)
			{
				return m_joystickValues[joy].first->getY();
			}
			else if (stick == 2)
			{
				return m_joystickValues[joy].second->getY();
			}
		}
	}
*/









