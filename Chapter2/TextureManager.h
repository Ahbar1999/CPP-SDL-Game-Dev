#pragma once
#ifndef __TextureManager__
#define __TextureManager__

#include <iostream>
#include <SDL/include/SDL_image.h>
#include <SDL/include/SDL.h>
#include <map>


class TextureManager
{

public:

	//loading texture through path 
	bool load(const std::string filename, std::string id, SDL_Renderer* pRenderer);

	//draw function to draw just static images
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//drawFrame function to draw frame by frame in case of animated images
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//texture maps/ maps are basically like dictioanry/ key valued pairs
	std::map<std::string, SDL_Texture*> m_textureMap;

	//Making this class a singleton
	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}

private:
	TextureManager() {}
	static TextureManager* s_pInstance;
};



#endif // Defined __TextureManager__