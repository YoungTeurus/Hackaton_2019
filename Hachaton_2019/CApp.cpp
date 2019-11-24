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
		if (gameOn)
			inputProssecing(&Event);
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event); //тут обрабатываем все события кроме кнопок игрока
        }

        OnLoop();//в этой штуке забираем от game все изменения и меняем картинку
        OnRender(); //рисуем уже готовую картинку
		SDL_Delay(10); // Задержка перед циклом, чтобы ЦП не убивался
    }

    OnCleanup();

    return 0;
}

//обработка ввода от игрока
void CApp::inputProssecing(SDL_Event* Event)
{
	board = SDL_GetKeyboardState(NULL);

	if (board[SDL_SCANCODE_W] || board[SDL_SCANCODE_UP])
		game->move_gameActor(game->get_player_1(), 0, 2);
	if (board[SDL_SCANCODE_S] || board[SDL_SCANCODE_DOWN])
		game->move_gameActor(game->get_player_1(), 2, 0);
	if (board[SDL_SCANCODE_A] || board[SDL_SCANCODE_LEFT])
		game->move_gameActor(game->get_player_1(), 3, 1);
	if (board[SDL_SCANCODE_D] || board[SDL_SCANCODE_RIGHT])
		game->move_gameActor(game->get_player_1(), 1, 3);
}


//==============================================================================
int main(int argc, char* argv[]) {
    CApp theApp;

    return theApp.OnExecute();
}

//==============================================================================
