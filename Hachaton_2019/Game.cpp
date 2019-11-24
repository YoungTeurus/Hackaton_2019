#include "Game.h"
#include "RoomTemplates.h"

Game::Game()
{
	SDL_Point* player_spawn_point = new SDL_Point{ 400,400 }; // Точка появления игрока
	SDL_Point player_size{45, 45}; // Размеры игрока
	player_1 = new GameActor(player_spawn_point, player_size.x, player_size.y,
		0, 10, 10, 5, true, 1); // Создаём объект-персонаж типа "1" - первый игрок

	active_room = nullptr;

	current_actors = nullptr;

	current_objects = nullptr;
}

GameObject* Game::check_all_collisions(GameObject* object)
{
	// Проверяем столкновение с границами комнаты
	auto obj_rect = object->get_object_rect();
	if (obj_rect->x < 0 || obj_rect->x + obj_rect->w > active_room->get_size()->x ||
		obj_rect->y < 0 || obj_rect->y + obj_rect->h > active_room->get_size()->y)
		return new GameObject(WALL); // Возвращаем объект с типом "-1"

	// Проверка на пересечение со всеми объектами в комнате
	auto obj_vector = get_current_objects();
	// Обходим все объекты
	for (int i = 0; i < obj_vector->size(); i++) {
		GameObject* current_obj = obj_vector->at(i); // Текущий объект, с которым ведётся сравнение
		if (current_obj != object) { // Проверяем, чтобы этот объект не является самим первым объектом
			if (SDL_HasIntersection(object->get_object_rect(), current_obj->get_object_rect())) {
				return current_obj; // объект, с которым пересеклись
			}
		}
	}

	// Проверка на пересечение со всеми персонажами в комнате
	auto act_vector = get_current_actors();
	// Обходим всех персонажей
	for (int i = 0; i < act_vector->size(); i++) {
		GameObject* current_act = act_vector->at(i); // Текущий объект, с которым ведётся сравнение
		if (current_act != object) { // Проверяем, чтобы этот объект не является самим первым объектом
			if (SDL_HasIntersection(object->get_object_rect(), current_act->get_object_rect())) {
				return current_act; // Возвращаем персонажа, с которым пересеклись
			}
		}
	}

	return nullptr;
}

void Game::load_test_room()
{
	active_room = new GameRoom(1, 1, 0);
	auto player = get_player_1();
	current_actors = active_room->get_actors();
	current_objects = active_room->get_objects();
}


bool Game::move_gameObject(GameObject* object, int direction)
{
	object->move(direction);
	GameObject* object_which_collissed = check_all_collisions(object);
	// Игрок не останавливается, 
	if (!object_which_collissed) // если не пересекаемся ни с одним объектом
		return true;
	else if (object_which_collissed->get_is_pushable()) { // либо объект, с которым пересекаемся, разрешено толкать
		move_gameObject(object_which_collissed, direction);
		// object_which_collissed->move(direction);
		
	}
	else if (object_which_collissed->get_is_passable()) // либо через объект, с которым пересекаемся, разрешено проходить
		return true;
	object->move((direction+2)%4);
	return true;
}