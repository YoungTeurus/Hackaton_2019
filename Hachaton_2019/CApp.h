//==============================================================================
// SDL Tutorial 1
//==============================================================================
#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL.h>
#include "Game.h"
#include <SDL_image.h>
#include "CSurface.h"
#include "Menu.h"

//==============================================================================
class CApp {
    private:
		//иниц всего для окошка
        bool            Running;

		SDL_Window*		Wind_Display;
		//иниц менюшку
		Menu			menu;
		//иниц игры
		Game*			game;
		
		bool			menuOn;

		bool			gameOn;

		//
		SDL_Texture* picturePlayer;
		//
		Texture texturePlayer;

		SDL_Renderer*	Renderer_Display;

		

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

#endif
