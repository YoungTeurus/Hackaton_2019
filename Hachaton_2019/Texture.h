#pragma once

#include <SDL.h>
class Texture
{
public:
	Texture();
	Texture(SDL_Texture* text, SDL_Rect* InGame, SDL_Rect* InPicter);
	Texture(SDL_Texture* text, int x,int y,int w,int h, int x1,int y2, int w1, int h2);
	Texture(SDL_Texture* text, SDL_Rect* InGame, int x1, int y2, int w1, int h2);
	Texture(SDL_Texture* text, int x, int y, int w, int h);

	~Texture();
    SDL_Rect InGame;


	void DrawTexture(SDL_Renderer* ren);
private:
	SDL_Texture* _texture;
	SDL_Rect InPicter;
};

