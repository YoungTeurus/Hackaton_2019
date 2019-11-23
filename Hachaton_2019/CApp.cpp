//==============================================================================
#include "CApp.h"
#include "Game.h"

//==============================================================================
CApp::CApp() {
	Wind_Display = NULL;
    Renderer_Display = NULL;

	menu = Menu();
	game = NULL;

	IsWhat = 0;

    Running = true;
}

//------------------------------------------------------------------------------
int CApp::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }

    SDL_Event Event;

    while(Running) {
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
