#include "GameTexture.h"

GameTexture::GameTexture()
{
	_texture = nullptr;
}

GameTexture::GameTexture(SDL_Renderer *ren, const char* name, SDL_Rect* InGame)
{
	_texture = CSurface::OnLoad(ren, name);
	this->InGame = *InGame;
}

GameTexture::GameTexture(SDL_Renderer* ren, const char* name, int x, int y, int w, int h)
{
	_texture = CSurface::OnLoad(ren, name);
	this->InGame = { x,y,w,h };
}
void GameTexture::SeetTexture(SDL_Renderer* ren, const char* name, int x, int y, int w, int h)
{

}
GameTexture::~GameTexture()
{
	SDL_DestroyTexture(_texture);
}

void GameTexture::DrawTexture(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, _texture, NULL, &WindowSize::Mashtab(&InGame));
}
