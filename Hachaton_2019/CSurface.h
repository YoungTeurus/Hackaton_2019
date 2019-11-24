#pragma once

#include <SDL.h>
#include <SDL_image.h>

class CSurface
{
public:
	CSurface();

public:
	// Создаёт текстуру и возвращает её
	static SDL_Texture* OnLoad(SDL_Renderer *ren,const char* File);
};

