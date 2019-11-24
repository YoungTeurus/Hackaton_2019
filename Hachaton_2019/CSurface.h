#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "AnimationTexture.h"
class AnimationTexture;

class CSurface
{
public:
	CSurface();

public:
	// Создаёт текстуру и возвращает её
	static SDL_Texture* OnLoad(SDL_Renderer *ren,const char* File);
	static AnimationTexture OnLoadObject(int type);
	static void InitGameTexture();
	static void Destroy();
	static SDL_Renderer* ren;

private:
	static SDL_Texture* Rock, * Actor, * Dver, * Enemy, * Stena, *Box;

};

