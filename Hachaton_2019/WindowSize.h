#pragma once
#include <SDL.h>

#define SCREEN_WEIGHT 1280
#define SCREEN_HEIGHT 720
#define NADO 45

class WindowSize
{
public:
	static int GetW(SDL_Window* win);
	static int GetH(SDL_Window* win);
	static void Init(SDL_Window* win);
	static SDL_Rect Mashtab(SDL_Rect* BaseInGame);
	static double GetKoef();

private:
	static double Koef;

};

