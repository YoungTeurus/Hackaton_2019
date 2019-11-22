//==============================================================================
#include "CApp.h"

//==============================================================================
CApp::CApp() {
	Wind_Display = NULL;
    Surf_Display = NULL;

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
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
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
