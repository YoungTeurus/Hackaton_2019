#include "CSurface.h"

SDL_Renderer* CSurface::ren;
SDL_Texture* CSurface::Rock = nullptr;
SDL_Texture* CSurface::Actor = nullptr;
SDL_Texture* CSurface::Dver = nullptr;
SDL_Texture* CSurface::Enemy = nullptr;
SDL_Texture* CSurface::Stena = nullptr;
SDL_Texture* CSurface::Box = nullptr;



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

AnimationTexture CSurface::OnLoadObject(int type)
{
	AnimationTexture tmp;
	switch (type)
	{
	case 0: tmp = AnimationTexture(CSurface::ren, CSurface::Rock, 9, 4, NADO, NADO); break;
	case 1: tmp = AnimationTexture(CSurface::ren, CSurface::Actor, 9, 4, NADO, NADO); break;
	case 2: tmp = AnimationTexture(CSurface::ren, CSurface::Stena, 9, 4, NADO, NADO); break;
	case 3: tmp = AnimationTexture(CSurface::ren, CSurface::Box, 9, 4, NADO, NADO); break;
	case 4: tmp = AnimationTexture(CSurface::ren, CSurface::Dver, 9, 4, NADO, NADO); break;
	default: tmp = AnimationTexture(CSurface::ren, CSurface::Dver, 9, 4, NADO, NADO);
		break;
	}
	return tmp;
}

void CSurface::InitGameTexture()
{
	CSurface::Rock = CSurface::OnLoad(CSurface::ren, "TextAnim.png");
	CSurface::Actor = CSurface::OnLoad(CSurface::ren, "TextAnim.png");
	CSurface::Dver = CSurface::OnLoad(CSurface::ren, "TextAnim.png");
	CSurface::Enemy = CSurface::OnLoad(CSurface::ren, "TextAnim.png");
	CSurface::Stena = CSurface::OnLoad(CSurface::ren, "TextAnim.png");
	CSurface::Box = CSurface::OnLoad(CSurface::ren, "TextAnim.png");
}

void CSurface::Destroy()
{
	SDL_DestroyTexture(CSurface::Rock);
	SDL_DestroyTexture(CSurface::Actor);
	SDL_DestroyTexture(CSurface::Dver);
	SDL_DestroyTexture(CSurface::Stena);
	SDL_DestroyTexture(CSurface::Enemy);
	SDL_DestroyTexture(CSurface::Box);
}

