#include "Game.h"

Game::Game()
{
	player_1 = new GameActor(new SDL_Point{0,0}, 40, 60,
		0, 10, 10, 5, true, 1); // Создаём объект-персонаж типа "1" - первый игрок

	active_room = nullptr;

	current_actors = nullptr;

	current_objects = nullptr;
}

void Game::load_test_room()
{
	active_room = new GameRoom(1, 1, 0);
	current_actors = active_room->get_actors();
	current_objects = active_room->get_objects();
}
