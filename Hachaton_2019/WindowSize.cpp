#include "WindowSize.h"
double WindowSize::Koef;


int WindowSize::GetW(SDL_Window* win)
{
	int x, y;
	SDL_GetWindowSize(win, &x, &y);
	return x;
}

int WindowSize::GetH(SDL_Window* win)
{
	int x, y;
	SDL_GetWindowSize(win, &x, &y);
	return y;
}

void WindowSize::Init(SDL_Window* win)
{
	WindowSize::Koef = (double)GetW(win) / (double)SCREEN_WEIGHT;
}

double WindowSize::GetKoef()
{
	return Koef;
}

SDL_Rect WindowSize::Mashtab(SDL_Rect* BaseInGame)
{
	SDL_Rect tmp = { BaseInGame->x* WindowSize::Koef,BaseInGame->y* WindowSize::Koef,BaseInGame->w* WindowSize::Koef,BaseInGame->h* WindowSize::Koef };
	return tmp;
}
