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

    if((Wind_Display = SDL_CreateWindow("Wow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WEIGHT, SCREEN_HEIGHT, 0) ) == NULL) {
        return false;
    }
	Renderer_Display = SDL_CreateRenderer(Wind_Display, -1, 0);

	menu = Menu(Wind_Display, Renderer_Display);
	//иниц  текстур для гаме
	picturePlayer = CSurface::OnLoad(Renderer_Display, "GameActor.jpg");
	AnimPicturePlayer = CSurface::OnLoad(Renderer_Display, "TextAnim.png");;


	texturePlayer = AnimationTexture(Renderer_Display, AnimPicturePlayer, 9, 4);
	//texturePlayer.Oscillate = true;
	texturePlayer.InGame.h = 145;
	texturePlayer.InGame.w = 145;
	//texturePlayer = Texture(picturePlayer, 0, 0, 25, 25);
    return true;
}

//==============================================================================
