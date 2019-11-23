#pragma once

#include <SDL.h>
#include "Game.h"
#include "Drawer.h"
#include "Menu.h"

//==============================================================================
class CApp {
    private:
        bool            Running;

		SDL_Window*     Wind_Display;

		SDL_Renerer*    Render;

		Menu*		    menu;

		Game*			game;

		Drawer*         drawer;
		

    public:
        CApp();

        int OnExecute();

    public:
        bool OnInit();

        void OnEvent(SDL_Event* Event);

        void OnLoop();

        void OnRender();

        void OnCleanup();
};

//==============================================================================
