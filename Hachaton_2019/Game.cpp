#include "Game.h"

Game::Game()
{
	player_1 = new GameActor(new SDL_Point{0,0}, 40, 60,
		0, 10, 10, 5, true, 1); // Создаём объект-персонаж типа "1" - первый игрок

	active_room = nullptr;

	current_enemies = nullptr;

	current_objects = nullptr;
}

void Game::AddBullet()
{
	GameObject* bullet = new GameObject(player_1->getCoord(), 30, 30, false, false, false, false, 3);
	bullet->Bspeed = 2;
	current_objects->push_back(bullet);
}

void Game::load_test_room()
{
	active_room = new GameRoom(1, 1, 0);
	current_enemies = active_room->get_actors();
	current_objects = active_room->get_objects();
}
