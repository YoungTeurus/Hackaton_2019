#pragma once

#include <SDL.h>
#include "CApp.h"

class Menu
{
public:
	Menu(SDL_Renderer* ren);
	~Menu();

	bool Render(SDL_Renderer* ren);

	void Update(SDL_Event *Event, SDL_Renderer* ren);


private:
	SDL_Rect* start_buttom;
	SDL_Rect* settings_buttom;
	SDL_Rect* exit_buttom;
	SDL_Surface* start_buttom_sur;
	SDL_Surface* settings_buttom_sur;
	SDL_Surface* exit_buttom_sur;


	void Init(SDL_Renderer* ren);
};

