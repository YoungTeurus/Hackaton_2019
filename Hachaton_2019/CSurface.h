#pragma once

#include <SDL.h>
#include <SDL_image.h>

class CSurface
{
public:
	CSurface();

public:
	static SDL_Surface* OnLoad(const char* File);

	//рисует картинку в пр€моугольнике
	static bool OnDraw(SDL_Renderer* Ren_Dest, SDL_Surface* Surf_Src, int X, int Y, int W, int H);

	//рисует картинку в координатах x,y размером таким же, как и была картинка
	static bool OnDraw(SDL_Renderer* Ren_Dest, SDL_Surface* Surf_Src, int X, int Y);

	//рисует картинку в координатах x,y размером таким же, как и была картинка.  артинка вырезаетс€ из тайлсета в пр€моугольнике TEXT
	static bool OnDraw(SDL_Renderer* Ren_Dest, SDL_Surface* Surf_Src, int X, int Y, int X_text, int Y_text, int W_text, int H_text);
	//рисует картинку в пр€моугольнике. артинка вырезаетс€ из тайлсета в пр€моугольнике TEXT
	static bool OnDraw(SDL_Renderer* Ren_Dest, SDL_Surface* Surf_Src, int X, int Y, int W, int H, int X_text, int Y_text, int W_text, int H_text);
};

