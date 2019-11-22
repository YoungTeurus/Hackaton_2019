//==============================================================================
#include "CApp.h"

// ����������� ��������
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

//==============================================================================
void CApp::OnEvent(SDL_Event* Event) 
{
	switch (Event->type)
	{
	case(SDL_QUIT):  Running = false; break; //���� �����������
	case(SDL_KEYDOWN): // ������ �������
		switch (Event->key.keysym.sym)
		{
		case SDLK_UP: game->get_player_1()->move(UP); break;
		case SDLK_RIGHT: game->get_player_1()->move(RIGHT); break;
		case SDLK_DOWN:  game->get_player_1()->move(DOWN); break;
		case SDLK_LEFT:  game->get_player_1()->move(LEFT); break;
		}//break;
	//������ ������� ����
	case(SDL_MOUSEBUTTONDOWN): break;
	default:
		break;
	}
	if (true)//���� ���� �������� ��� �����-�� �������
	{
		game = new Game();//���� ������� ������
	}
}

//==============================================================================
