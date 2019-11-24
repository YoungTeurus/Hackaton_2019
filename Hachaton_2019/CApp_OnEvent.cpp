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
	switch (MenuState)
	{
	case 0: MenuState = menu.Update(Event, Renderer_Display); break;
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
		/*
		case(SDL_KEYDOWN): // нажата клавиша
		{
			
			}//break;
		//нажата клавиша мыши
		case(SDL_MOUSEBUTTONDOWN): break;
		*/
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
