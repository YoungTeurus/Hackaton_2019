#include "WindowSize.h"

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
