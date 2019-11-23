//==============================================================================
#include "CApp.h"
#include "Game.h"

//==============================================================================
CApp::CApp() {
	Wind_Display = NULL;
    Renderer_Display = NULL;

	menu = Menu();
	game = NULL;
	menuOn = true;
	gameOn = false;

	MenuState = 0;

    Running = true;
}

//------------------------------------------------------------------------------
int CApp::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }

    SDL_Event Event;

    while(Running) {
		board = SDL_GetKeyboardState(NULL);

		if (board[SDL_SCANCODE_W] || board[SDL_SCANCODE_UP])
			game->get_player_1()->move(0);
		if (board[SDL_SCANCODE_S] || board[SDL_SCANCODE_DOWN])
			game->get_player_1()->move(2);
		if (board[SDL_SCANCODE_A] || board[SDL_SCANCODE_LEFT])
			game->get_player_1()->move(3);
		if (board[SDL_SCANCODE_D] || board[SDL_SCANCODE_RIGHT])
			game->get_player_1()->move(1);
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event); //тут передаем все изменения от игрока
        }

        OnLoop();//в этой штуке забираем от game все изменения и меняем картинку
        OnRender(); //рисуем уже готовую картинку
		SDL_Delay(10); // Задержка перед циклом, чтобы ЦП не убивался
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
