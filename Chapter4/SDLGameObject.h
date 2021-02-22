#pragma once

#include "GameObject.h"

class SDLGameObject : public GameObject
{
	
public:
	SDLGameObject(const LoaderParams* Params);

	virtual void draw();
	virtual void update();
	virtual void clean();

	//Getters

	//NOTE: returning by reference, probably so we can modify
	Vector2D& getPosition()
	{
		return m_position;
	}

	int getWidth()
	{
		return m_height;
	}
	int getHeight()
	{
		return m_width;
	}

protected:
	
	//old coordinates implementation
	/*
	* 	int m_x;
	*	int m_y;
	*/
	
	//new coordinates implementation with our Vector2D class
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_accelaration;


	int m_height;
	int m_width;

	int m_currentRow;
	int m_currentFrame;

	std::string m_textureID;
};

