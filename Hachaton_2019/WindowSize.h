#pragma once
#include <SDL.h>

#define SCREEN_WEIGHT 1280
#define SCREEN_HEIGHT 720

class WindowSize
{
public:
	static int GetW(SDL_Window* win);
	static int GetH(SDL_Window* win);
	static void Init(SDL_Window* win);
	static SDL_Rect Mashtab(SDL_Rect* BaseInGame);

private:
	static double Koef;

};

