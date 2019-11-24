#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "AnimationTexture.h"
#include "Game.h"

class AnimationTexture;
class CSurface
{
public:
	CSurface();

public:
	// Создаёт текстуру и возвращает её
	static SDL_Texture* OnLoad(SDL_Renderer *ren,const char* File);
	static void CoordObjectIn25D(SDL_Window* win, AnimationTexture* texture, GameObject* object, Game* game);
};

