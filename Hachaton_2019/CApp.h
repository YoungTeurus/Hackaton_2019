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
#include "WindowSize.h"
#include <Windows.h>
#include "AnimationTexture.h"
#include"GameTexture.h"
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

		// Массив для работы с клавиатурой (см. )
		const Uint8*	board;
		
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
		GameTexture Bullettexturer;
		
		int MenuState = 0; // Состояние меню: 0 - ничего не нажато, 1-3 - нажаты кнопки с первой по третью

    public:
        CApp();

        int OnExecute();

    public:
        bool OnInit();

        void OnEvent(SDL_Event* Event);

        void OnLoop();

        void OnRender();

        void OnCleanup();

		void inputProssecing(SDL_Event* Event);
};

//==============================================================================

#endif
