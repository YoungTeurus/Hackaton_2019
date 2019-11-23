#pragma once
#include "SDL.h"

class Drawer
{
public:
	Drawer(				//конструктор
			SDL_Window, // наше окошко
			int);		// индекс
	//void init();
	bool drawPlayer(SDL_Rect); // принимает размеры игрока и его положние на экране
private:
	SDL_Renderer render;
	bool drawTexture(SDL_Rect, SDL_Texture); // принимает обл, где рисуем и текстурку, которую рисуем

}
