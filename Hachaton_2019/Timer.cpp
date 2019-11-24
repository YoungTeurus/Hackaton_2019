#include "Timer.h"
Timer::Timer()
{
	previos_time = SDL_GetTicks();
	delta = 0;
	current_time = SDL_GetTicks();
}

void Timer::Update()
{
	current_time = SDL_GetTicks();
	delta = (current_time - previos_time)/1000;
	current_time = previos_time;
}
