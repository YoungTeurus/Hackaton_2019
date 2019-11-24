#pragma once
#include <SDL.h>
#include "WindowSize.h"
#include "CSurface.h"
class GameTexture
{

	
	public:
		GameTexture();
		GameTexture(SDL_Renderer* ren, const char* name, SDL_Rect* InGame);
		GameTexture(SDL_Renderer* ren, const char* name, int x, int y, int w, int h);
		void SeetTexture(SDL_Renderer* ren, const char* name, int x, int y, int w, int h);
		~GameTexture();
		SDL_Rect InGame;

		void DrawTexture(SDL_Renderer* ren);
	private:
		SDL_Texture* _texture;

	
};

