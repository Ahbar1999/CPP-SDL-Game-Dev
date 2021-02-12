#include "TextureManager.h"


bool TextureManager::load(const std::string filename, std::string id, SDL_Renderer* pRenderer)
{
	SDL_Surface* pTempSurface = IMG_Load(filename.c_str());
	
	//If failed to load Surface 
	if (pTempSurface == 0)
	{
		return false;
	}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	if (pTexture != 0)
	{
		m_textureMap[id] = pTexture;
		return true;
	}

	return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = srcRect.y = 0;
	srcRect.w = destRect.w = width; //setting width and height of the src and dest rectangle to that of our texture
	srcRect.h = destRect.h = height;
	
	//Where we wanna draw on screen
	destRect.x = x;
	destRect.y = y;

	//Just like SDL_RenderCopy but with extra parameters for rotation and flipping
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1); //currentRow  = 0 => srcRect.y  = -height, which should be clamped to 0
	destRect.x = x;
	destRect.y = y;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

TextureManager* TextureManager::s_pInstance = 0;