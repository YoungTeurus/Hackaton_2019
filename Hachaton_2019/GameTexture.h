#pragma once
#include <SDL.h>
#include "WindowSize.h"
#include "CSurface.h"
#include <string>
class GameTexture
{

	
	public:
		GameTexture();
		GameTexture(SDL_Renderer* ren, const char* name, SDL_Rect* InGame);
		GameTexture(SDL_Renderer* ren, const char* name, int x, int y, int w, int h);
		void SetTexture(SDL_Renderer* ren, int type, SDL_Point* coord, SDL_Point* size);
		~GameTexture();
		SDL_Rect InGame;
		std::string bulletname = "bullet.png";
		void DrawTexture(SDL_Renderer* ren);
	private:
		SDL_Texture* _texture;

	
};

