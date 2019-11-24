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
		
		bool			menuOn;
		bool			gameOn;
		
		//клава
		const Uint8* board;
		// описание текстур, которые используются в отрисовки игры
		// дальше их нужно проинициализировать в onInit

		// каждый цикл: обновить их координаты, размеры , анимки в onLoop
		// и отрисовать в onrender
		// когда выходим из програмки обязательно их удаляем 

		//хранит фаил с картинкой
		SDL_Texture* picturePlayer;
		//сама текстурка игрока с размерами и положением
		Texture texturePlayer;

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

		double timer, delta_time, previos_time;
		//Timer время с запуска прогрыммы
		//Дельта время между кадрами
		//Время на кадр назад
};

//==============================================================================

#endif
