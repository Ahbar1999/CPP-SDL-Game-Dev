#include "AnimatedGraphic.h"


AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams, int animSpeed) : SDLGameObject(pParams), m_animSpeed(animSpeed)
{

}

void AnimatedGraphic::update()
{
	m_currentFrame = 0;
	//int((SDL_GetTicks() / (1000 / m_animSpeed)));
}