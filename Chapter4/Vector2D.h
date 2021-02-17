#pragma once

#include <math.h>

class Vector2D
{
public:

	//Constructor
	Vector2D(float x, float y): m_x(x), m_y(y)
	{

	}

	//Setters
	float getX() { return m_x; }
	float getY() { return m_y; }

	//Getters
	void setX(float x) { m_x = x; }
	void setY(float y) { m_y = y; }

	float length()
	{
		return sqrt(m_x * m_x + m_y * m_y);
	}

	/* 
	->Some overlaoded operators follow below.
	NOTE:
	'RHS' stands for  Right Hand Side.
	*/


	Vector2D operator+(const Vector2D& vRHS) const
	{
		//This function does not change the value of the existing operator thats why retrun by value 
		return Vector2D(m_x + vRHS.m_x, m_y + vRHS.m_y);
	}

	//Not a member function of this class still has access to member variables
	friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
	{
		//Friend keyword allows us to use two arguements instead of usual one for binary operator overloading
		//This function changes the value of v1 thats why we return by reference the same v1
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;

		return v1;
	}

	Vector2D operator*(float scalar)
	{
		return Vector2D(m_x * scalar, m_y * scalar);
	}

	Vector2D& operator*=(float scalar)
	{
		m_x = m_x* scalar;
		m_y = m_y * scalar;

		return *this;
	}

	Vector2D operator-(const Vector2D& vRHS) const
	{
		return Vector2D(m_x - vRHS.m_x, m_y - vRHS.m_y);
	}

	friend Vector2D& operator-=(Vector2D& vLHS, const Vector2D& vRHS)
	{
		vLHS.m_x = vLHS.m_x - vRHS.m_x;
		vLHS.m_y = vLHS.m_y - vRHS.m_y;

		return vLHS;
	}

	Vector2D operator/(const float scalar)
	{
		return Vector2D(m_x / scalar, m_y / scalar);
	}

	Vector2D& operator/=(float scalar)
	{
		m_x /= scalar;
		m_y /= scalar;

		//Just returning the current(after being modified) member variables
		return *this;
	}

	void normalize()
	{
		float l = length();
		if (l > 1)
		{
			//just dividing the vector by its mod/length
			(*this) *= 1 / l;
		}
	}


private:

	float m_x;
	float m_y;
};

