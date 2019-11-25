#include "GameObject.h"
#include "GameActor.h"
#include <vector>
#include <map>
#include "GameObject_types.h"
#pragma once

using namespace std;

struct Obj_and_Act
{
	vector<GameObject*>* obj_vector;
	vector<GameActor*>* act_vector;
	SDL_Point* size;
};

// Коллекция всех комнат
// Коллекция имеет
static map< int, Obj_and_Act > all_rooms;

class RoomTemplates {
public:
	RoomTemplates() { // Загрузка и создание всех Template-ов
		vector<GameObject*>* temp_obj_vect = new vector<GameObject*>(); // Вектор объектов для Template
		add_object(temp_obj_vect, SDL_Point{ 50,50 }, PUSHABLE_ROCK); // Создание объекта. ROCK - заDEFINEнная перменная
		add_object(temp_obj_vect, SDL_Point{ 100,100 }, ROCK_LONG_HORIZONTAL);
		add_object(temp_obj_vect, SDL_Point{ 200,200 }, ROCK_LONG_VERTICAL);
		add_object(temp_obj_vect, SDL_Point{ 50,200 }, ROCK_BIG);

		add_object(temp_obj_vect, SDL_Point{ 1,200 }, 5, 100, EXIT_LEFT);
		add_object(temp_obj_vect, SDL_Point{ 494, 200}, 5, 100, EXIT_RIGHT);

		vector<GameActor*>* temp_act_vect = new vector<GameActor*>();
		add_actor(temp_act_vect, SDL_Point{ 400,50 }, 1, 10, 5, 3, true, TEST_ACTOR);

		SDL_Point* temp_room_size = new SDL_Point{ 500,500 };

		Obj_and_Act temp_0 = { temp_obj_vect, temp_act_vect,  temp_room_size};

		all_rooms[0] = temp_0;
	}

	~RoomTemplates() {
		// Не очень понятно, что деструкторить...
	}

	// Возвращает вектор GameObject-ов соответствующий ключу type.
	// Если такого ключа нет, возвращаем nullptr
	vector<GameObject*>*	get_obj_vector(int type) {
		if (all_rooms.find(type) != all_rooms.end())
			return all_rooms[type].obj_vector;
		return nullptr;
	}

	// Возвращает вектор GameActor-ов соответствующий ключу type.
	// Если такого ключа нет, возвращаем nullptr
	vector<GameActor*>*		get_act_vector(int type) {
		if (all_rooms.find(type) != all_rooms.end())
			return all_rooms[type].act_vector;
		return nullptr;
	}

	SDL_Point* get_size(int type) {
		if (all_rooms.find(type) != all_rooms.end())
			return all_rooms[type].size;
		return nullptr;
	}

private:
	void add_object(vector<GameObject*>* temp_obj_vect, SDL_Point spawn_point, 
			int w, int h,
			bool looking_right, // В какую сторону объект смотрит изначально (см. ниже)
			bool rotatable, // Нужно ли отражать текстуру объекта
			bool passable,
			bool pushable,
			int	 type // Тип объекта, если нужен
	) {
		auto temp_obj = new GameObject(spawn_point, w, h, looking_right, rotatable, passable, pushable, type);
		temp_obj_vect->push_back(temp_obj);
	}

	void add_actor(vector<GameActor*>* temp_act_vect, SDL_Point spawn_point,int start_lvl, int start_hp, int start_mp,
		int start_dmg, bool start_is_looking_right, int w, int h, int start_type, int speed = 4) {
		GameActor* temp_act = new GameActor(spawn_point, w, h, start_lvl, start_hp, start_mp, start_dmg, start_is_looking_right, start_type);
		//меняем скорость и толкаемость
		temp_act->set_speed(2);
		temp_act->setIsPushable(true);
		temp_act_vect->push_back(temp_act);
	}
};