#pragma once

#include <SDL.h>
#include <SDL_image.h>

class CSurface
{
public:
	CSurface();

public:
	static SDL_Surface* OnLoad(const char* File);

	//������ �������� � ��������������
	static bool OnDraw(SDL_Renderer* Ren_Dest, SDL_Surface* Surf_Src, int X, int Y, int W, int H);

	//������ �������� � ����������� x,y �������� ����� ��, ��� � ���� ��������
	static bool OnDraw(SDL_Renderer* Ren_Dest, SDL_Surface* Surf_Src, int X, int Y);

	//������ �������� � ����������� x,y �������� ����� ��, ��� � ���� ��������. �������� ���������� �� �������� � �������������� TEXT
	static bool OnDraw(SDL_Renderer* Ren_Dest, SDL_Surface* Surf_Src, int X, int Y, int X_text, int Y_text, int W_text, int H_text);
	//������ �������� � ��������������. ������� ���������� �� �������� � �������������� TEXT
	static bool OnDraw(SDL_Renderer* Ren_Dest, SDL_Surface* Surf_Src, int X, int Y, int W, int H, int X_text, int Y_text, int W_text, int H_text);
};

