//==============================================================================
#include "CApp.h"

//==============================================================================
bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

	SDL_Window *a = SDL_CreateWindow("Wow", SDL_WINDOWPOS_CENTERED,0,600,800,0);

    if((Surf_Display = SDL_CreateRGBSurface(0, 640, 480, 32, 0,0,0,0)) == NULL) {
        return false;
    }
    return true;
}

//==============================================================================
