#include "Game.h"

Game::Game()
{
	player_1 = new GameActor(new SDL_Point{0,0}, 40, 60,
		0, 10, 10, 5, true, 1); // Создаём объект-персонаж типа "1" - первый игрок
}