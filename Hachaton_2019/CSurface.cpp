#include "CSurface.h"

CSurface::CSurface()
{

}

SDL_Texture* CSurface::OnLoad(SDL_Renderer *ren, const char* File)
{
	SDL_Surface* Surf_Temp = NULL;
	//SDL_Surface* Surf_Return = NULL;

	if ((Surf_Temp = IMG_Load(File)) == NULL) {
		return NULL;
	}

	//Surf_Return = SDL_ConvertSurfaceFormat(Surf_Temp,SDL_PIXELFORMAT_UNKNOWN,0);
	
	SDL_Texture* tmp_text = SDL_CreateTextureFromSurface(ren, Surf_Temp);

	SDL_FreeSurface(Surf_Temp);
	return tmp_text;
}

