#include "Texture.h"

Texture::Texture()
{
	_texture = nullptr;
}

Texture::Texture(SDL_Texture* text, SDL_Rect *InGame, SDL_Rect *InPicter)
{
	_texture = text;
	this->InPicter = *InPicter;
	this->InGame = *InGame;

}

Texture::Texture(SDL_Texture* text, int x, int y, int w, int h, int x1, int y2, int w1, int h2)
{
	_texture = text;
	this->InGame = { x,y,w,h };
	this->InPicter = { x1,y2,w1,h2 };
}

Texture::Texture(SDL_Texture* text, SDL_Rect* InGame, int x1, int y2, int w1, int h2)
{
	this->InGame = *InGame;
	_texture = text;
	this->InPicter = { x1,y2,w1,h2 };
}

Texture::Texture(SDL_Texture* text, int x, int y, int w, int h)
{
	_texture = text;
	this->InGame = { x,y,w,h };
	InPicter = { 0,0,0,0 };

}

Texture::~Texture()
{

}

void Texture::DrawTexture(SDL_Renderer* ren)
{
	if (InPicter.w == 0)
		SDL_RenderCopy(ren, _texture, NULL, &InGame);
	else SDL_RenderCopy(ren, _texture, &InPicter, &InGame);
}
