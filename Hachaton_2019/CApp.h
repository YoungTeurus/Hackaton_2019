#pragma once

#include <SDL.h>
#include "Game.h"
#include "Drawer.h"

//==============================================================================
class CApp {
    private:
        bool            Running;

        SDL_Surface*    Surf_Display;

		SDL_Window*     Wind_Display;

		SDL_Renerer*    Render;

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
