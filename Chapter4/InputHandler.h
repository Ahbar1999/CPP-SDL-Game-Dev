#pragma once

#include <iostream>
#include <SDL/include/SDL.h>
#include <vector>
#include "Vector2D.h"


enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2,
};

class InputHandler
{
public:

	//JUST ANOTHER SINGLETON CLASS
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}

		return s_pInstance;
	}

//-----------------JOYSTICK INPUT HANDLING IMPLEMENTATION
	
	void initializeJoysticks();
	bool joysticksInitialized()
	{
		return m_bJoysticksInitialised;
	}
	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);
//-------------------------------------------------------


//-----------------MOUSE INPUT HANDLING IMPLEMENTATION
	bool getMouseButtonState(int buttonNumber)
	{
		return m_mouseButtonStates[buttonNumber];
	}
	Vector2D* getMousePosition()
	{
		return m_mousePosition;
	}
//------------------------------------------------------


//-----------------KEYBOARD INPUT HANDLING IMPLEMENTATION
	bool isKeyDown(SDL_Scancode key);

//------------------------------------------------------

	//for polling inputs 
	void update();

	//a clean function which will clear any devices we have initialized
	void clean();

private:
	InputHandler() 
	{	
		//Initialising Button States
		for (int i = 0; i < 3; i++)
		{
			m_mouseButtonStates.push_back(false);
		}
	}
	~InputHandler() {}
	static InputHandler* s_pInstance;

	//To keep track of the Joysticks initialized
	std::vector<SDL_Joystick* > m_Joysticks;
	bool m_bJoysticksInitialised = false;
	
	//For storing axes movement values
	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
	//For joystick senstivity
	const int m_joystickDeadZone = 10000;

	//Mouse input handling variables
	std::vector<bool> m_mouseButtonStates;	
	Vector2D* m_mousePosition = new Vector2D(0, 0);

	//Keyboard input handling 
	const Uint8* m_keystates;

	//handle keyboard events
	void onKeyUP();
	void onKeyDown();

	//handle mouse events
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

};

typedef InputHandler TheInputHandler;
