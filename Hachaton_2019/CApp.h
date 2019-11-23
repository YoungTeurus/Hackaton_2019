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
#include "Windowr.h"
#include <Windows.h>
#include "AnimationTexture.h"
typedef SDL_Texture Picter; // более понятный тип данных


//==============================================================================
class CApp {
    private:
		//иниц всего для окошка
        bool            Running;

		SDL_Window*		Wind_Display;
		SDL_Renderer* Renderer_Display;
		//иниц менюшку
		Menu			menu;
		//иниц игры
		Game*			game;
		const Uint8* board;
		
		bool			menuOn;
		bool			gameOn;

		// описание текстур, которые используются в отрисовки игры
		// дальше их нужно проинициализировать в onInit

		// каждый цикл: обновить их координаты, размеры , анимки в onLoop
		// и отрисовать в onrender
		// когда выходим из програмки обязательно их удаляем 

		//хранит фаил с картинкой (picter == sdl_texture)
		Picter* picturePlayer;
		Picter* AnimPicturePlayer;
		//сама текстурка игрока с размерами и положением
		AnimationTexture texturePlayer;

		int IsWhat = 0;

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
