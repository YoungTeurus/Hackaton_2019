//==============================================================================
#include "CApp.h"

//==============================================================================
bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }	

	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0)
	{
		return false;
	}

    if((Wind_Display = SDL_CreateWindow("Wow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0) ) == NULL) {
        return false;
    }
	Renderer_Display = SDL_CreateRenderer(Wind_Display, -1, 0);

	menu = Menu(Wind_Display, Renderer_Display);
	//иниц  текстур для гаме
	picturePlayer = CSurface::OnLoad(Renderer_Display, "GameActor.jpg");
	texturePlayer = Texture(picturePlayer, 0, 0, 50, 50);
    return true;
}

//==============================================================================
