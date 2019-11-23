#pragma once

#include <SDL.h>
#include "Texture.h"
#include "CSurface.h"
#include "WindowSize.h"

class Menu
{
public:
	Menu();
	Menu(SDL_Window* win, SDL_Renderer* ren);
	~Menu();

	void Render(SDL_Renderer* ren);

	int Update(SDL_Event *Event, SDL_Renderer* ren);


private:
	SDL_Texture* TileMenu;
	SDL_Texture* BackP;
	Texture start;
	Texture exit;
	Texture settings;
	Texture Back;

	void Init(SDL_Window* win,SDL_Renderer* ren);
};

