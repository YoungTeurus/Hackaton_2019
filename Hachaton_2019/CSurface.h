#pragma once

#include <SDL.h>
#include <SDL_image.h>

class CSurface
{
public:
	CSurface();

public:
	static SDL_Texture* OnLoad(SDL_Renderer *ren,const char* File);
};

