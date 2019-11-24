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

	// Создаём окно
	if((Wind_Display = SDL_CreateWindow("Wow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0) ) == NULL) {
        return false;
    }
	//SDL_SetWindowFullscreen(Wind_Display, SDL_WINDOW_FULLSCREEN);
	CSurface::ren = SDL_CreateRenderer(Wind_Display, -1, 0);
	WindowSize::Init(Wind_Display);

	CSurface::InitGameTexture();

	menu = Menu(Wind_Display, CSurface::ren);
	//иниц  текстур для гаме
	picturePlayer = CSurface::OnLoad(CSurface::ren, "GameActor.jpg");
	AnimPicturePlayer = CSurface::OnLoad(CSurface::ren, "TextAnim.png");;

	Bullettexturer.SeetTexture(CSurface::ren, "bullet.png", 20, 20, 20, 20);
	texturePlayer = AnimationTexture(CSurface::ren, AnimPicturePlayer, 9, 4, NADO, NADO);
	//texturePlayer = Texture(picturePlayer, 0, 0, 25, 25);
    return true;
}

//==============================================================================
