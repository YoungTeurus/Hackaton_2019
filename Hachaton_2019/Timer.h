#pragma once
#include<SDL_timer.h>
class Timer
{
public: 
	Timer();
	void Update();
	double delta, previos_time, current_time;
};

