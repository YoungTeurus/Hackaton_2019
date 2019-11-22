#include "CSurface.h"

CSurface::CSurface()
{

}

SDL_Surface* CSurface::OnLoad(const char* File)
{
	SDL_Surface* Surf_Temp = NULL;
	//SDL_Surface* Surf_Return = NULL;

	if ((Surf_Temp = IMG_Load(File)) == NULL) {
		return NULL;
	}

	//Surf_Return = SDL_ConvertSurfaceFormat(Surf_Temp,SDL_PIXELFORMAT_UNKNOWN,0);
	//SDL_FreeSurface(Surf_Temp);

	return Surf_Temp;
}

bool CSurface::OnDraw(SDL_Renderer* Ren_Dest, SDL_Surface* Surf_Src, int X, int Y, int W, int H)
{
	if (Ren_Dest == NULL || Surf_Src == NULL) {
		return false;
	}

	SDL_Rect DestR = { X,Y,W,H };

	SDL_Texture* tmp_text = SDL_CreateTextureFromSurface(Ren_Dest, Surf_Src);
	SDL_RenderCopy(Ren_Dest, tmp_text, NULL, &DestR);
	SDL_DestroyTexture(tmp_text);

	return true;
}

bool CSurface::OnDraw(SDL_Renderer* Ren_Dest, SDL_Surface* Surf_Src, int X, int Y)
{
	if (Ren_Dest == NULL || Surf_Src == NULL) {
		return false;
	}

	SDL_Rect DestR = { X,Y,Surf_Src->w,Surf_Src->h };

	SDL_Texture* tmp_text = SDL_CreateTextureFromSurface(Ren_Dest, Surf_Src);
	SDL_RenderCopy(Ren_Dest, tmp_text, NULL, &DestR);
	SDL_DestroyTexture(tmp_text);

	return true;
}

bool CSurface::OnDraw(SDL_Renderer* Ren_Dest, SDL_Surface* Surf_Src, int X, int Y, int X_text, int Y_text, int W_text, int H_text)
{
	if (Ren_Dest == NULL || Surf_Src == NULL) {
		return false;
	}

	SDL_Rect DestR = { X,Y,Surf_Src->w,Surf_Src->h };

	SDL_Rect TextRec = { X_text,Y_text,W_text,H_text };

	SDL_Texture* tmp_text = SDL_CreateTextureFromSurface(Ren_Dest, Surf_Src);
	SDL_RenderCopy(Ren_Dest, tmp_text, &TextRec, &DestR);
	SDL_DestroyTexture(tmp_text);

	return true;
}

bool CSurface::OnDraw(SDL_Renderer* Ren_Dest, SDL_Surface* Surf_Src, int X, int Y, int W, int H, int X_text, int Y_text, int W_text, int H_text)
{
	if (Ren_Dest == NULL || Surf_Src == NULL) {
		return false;
	}

	SDL_Rect DestR = { X,Y,W,H };

	SDL_Rect TextRec = { X_text,Y_text,W_text,H_text };

	SDL_Texture* tmp_text = SDL_CreateTextureFromSurface(Ren_Dest, Surf_Src);
	SDL_RenderCopy(Ren_Dest, tmp_text, &TextRec, &DestR);
	SDL_DestroyTexture(tmp_text);

	return true;
}
