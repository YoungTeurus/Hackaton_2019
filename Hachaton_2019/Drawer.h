#pragma once
#include "SDL.h"

class Drawer
{
public:
	Drawer(				//�����������
			SDL_Window, // ���� ������
			int);		// ������
	//void init();
	bool drawPlayer(SDL_Rect); // ��������� ������� ������ � ��� �������� �� ������
private:
	SDL_Renderer render;
	bool drawTexture(SDL_Rect, SDL_Texture); // ��������� ���, ��� ������ � ���������, ������� ������

}
