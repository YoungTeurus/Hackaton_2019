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
	SDL_Rect tmp = { int(BaseInGame->x * WindowSize::Koef),
		int(BaseInGame->y * WindowSize::Koef),
		int(BaseInGame->w * WindowSize::Koef),
		int(BaseInGame->h * WindowSize::Koef)};
	return tmp;
}
