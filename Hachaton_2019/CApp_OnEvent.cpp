//==============================================================================
#include "CApp.h"

// Направления движения
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

//==============================================================================
void CApp::OnEvent(SDL_Event* Event) 
{
	if (Event->type == SDL_QUIT)
		Running = false;


	switch (IsWhat)
	{
	case 0: IsWhat = menu.Update(Event, Renderer_Display); break;
	case 1:
	{
		if (!gameOn)//если игра началась тут какое-то событие
		{
			gameOn = true;
			game = new Game();//иниц игровую логику
			game->load_test_room();
		}
		switch (Event->type)
		{
		case(SDL_QUIT):  Running = false; break; //окно закрывается
		case(SDL_KEYDOWN): // нажата клавиша
			switch (Event->key.keysym.sym)
			{
			case SDLK_UP: game->get_player_1()->move(UP); break;
			case SDLK_RIGHT: game->get_player_1()->move(RIGHT); break;
			case SDLK_DOWN:  game->get_player_1()->move(DOWN); break;
			case SDLK_LEFT:  game->get_player_1()->move(LEFT); break;
			}//break;
		//нажата клавиша мыши
		case(SDL_MOUSEBUTTONDOWN): break;
		default:
			break;
		}
		break;
	}
	case 2: break;
	case 3: Running = false; break;
	default:
		break;
	}
	
}

//==============================================================================
