#include "Game.h"

Game::Game()
{
	player_1 = new GameActor(new SDL_Point{0,0}, 40, 60,
		0, 10, 10, 5, true, 1); // Создаём объект-персонаж типа "1" - первый игрок

	active_room = nullptr;

	current_actors = nullptr;

	current_objects = nullptr;
}

int Game::check_all_collisions(GameObject* object)
{
	// Проверка на пересечение со всеми объектами в комнате
	auto obj_vector = get_current_objects();
	// Обходим все объекты
	for (int i = 0; i < obj_vector->size(); i++) {
		GameObject* current_obj = obj_vector->at(i); // Текущий объект, с которым ведётся сравнение
		if (current_obj == object) { // Проверяем, чтобы этот объект не является самим первым объектом
			if (SDL_HasIntersection(object->get_object_rect(), current_obj->get_object_rect())) {
				return current_obj->get_type(); // Возвращаем тип объекта, с которым пересеклись
			}
		}
	}

	// Проверяем столкновение с границами комнаты
	auto obj_rect = object->get_object_rect();
	if (obj_rect->x < 0 || obj_rect->x > active_room->get_size()->x ||
		obj_rect->y < 0 || obj_rect->y > active_room->get_size()->y)
		return -1;

	return 0;
}

void Game::load_test_room()
{
	active_room = new GameRoom(1, 1, 0);
	current_actors = active_room->get_actors();
	current_objects = active_room->get_objects();
}
