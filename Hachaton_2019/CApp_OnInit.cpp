//==============================================================================
#include "CApp.h"

//==============================================================================
bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }	

    if((Wind_Display = SDL_CreateWindow("Wow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0) ) == NULL) {
        return false;
    }
	if((Render = SDL_CreateRenderer(Wind_Display, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) ) == NULL) {
		return false;
	}


	Surf_Display = SDL_GetWindowSurface(Wind_Display);
    return true;
}

//==============================================================================
