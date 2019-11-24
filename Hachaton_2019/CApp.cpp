//==============================================================================
#include "CApp.h"
#include "Game.h"

//==============================================================================
Timer main_timer=Timer();
CApp::CApp() {
	Wind_Display = NULL;
    Renderer_Display = NULL;
	timer = 0;
	previos_time = 0;
	delta_time = 0;
	menu = Menu();
	game = NULL;
	menuOn = true;
	gameOn = false;

	IsWhat = 0;

    Running = true;
}

//------------------------------------------------------------------------------
int CApp::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }

    SDL_Event Event;
	bool firstframe = true;
	
    while(Running) { //Игровой цикл

		board = SDL_GetKeyboardState(NULL);
		main_timer.Update();
		if (firstframe)
		{
			firstframe = false;
			main_timer.delta = 0;
		}
	// нажата клавиша
		if(board[SDL_SCANCODE_W])game->get_player_1()->move(0);
		else if (board[SDL_SCANCODE_S])game->get_player_1()->move(2);
		if (board[SDL_SCANCODE_D])game->get_player_1()->move(1);
		else if (board[SDL_SCANCODE_A])game->get_player_1()->move(3);
		if (board[SDL_SCANCODE_SPACE]) game->AddBullet();
		
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event); //тут передаем все изменения от игрока
        }


        OnLoop();//в этой штуке забираем от game все изменения и меняем картинку
        OnRender(); //рисуем уже готовую картинку
		SDL_Delay(30); // Задержка перед циклом, чтобы ЦП не убивался
    }

    OnCleanup();

    return 0;
}

//==============================================================================
int main(int argc, char* argv[]) {
    CApp theApp;

    return theApp.OnExecute();
}

//==============================================================================
