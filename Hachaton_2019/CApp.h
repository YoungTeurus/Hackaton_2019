//==============================================================================
// SDL Tutorial 1
//==============================================================================
#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL.h>
#include <SDL_image.h>
#include "CSurface.h"
#include "Menu.h"

//==============================================================================
class CApp {
    private:
        bool            Running;
		SDL_Renderer*	Renderer_Display;
		SDL_Window*     Wind_Display;
		SDL_Surface*	IMG;

		Menu menu;

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
