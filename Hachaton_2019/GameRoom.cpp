#include "GameRoom.h"
#include <iostream>

using namespace std;

GameRoom::GameRoom(int i, int j,	// Конструктор комнаты
	vector<GameObject*>* start_objects,
	vector<GameActor*>*	start_actors)
{
	map_i = i;
	map_j = j;
	if (start_objects)
		objects = start_objects;
	else
		objects = new vector<GameObject*>(0);
	if (start_actors)
		actors = start_actors;
	else
		actors = new vector<GameActor*>(0);
}

GameRoom::GameRoom(int i, int j,
	int room_template) {
	map_i = i;
	map_j = j;

	// Загружаем "template" комнаты из определённого RoomTemplate
	objects = room_templates->get_obj_vector(room_template);
	actors = room_templates->get_act_vector(room_template);

	// Если 
	if (!(objects) || !(actors)) {
		std::cout << "Не был найден подходящий template";
	}
}

void GameRoom::add_object(GameObject* obj_to_add) {
	objects->push_back(obj_to_add);
}

void GameRoom::add_actor(GameActor* act_to_add) {
	actors->push_back(act_to_add);
}

int GameRoom::get_i()
{
	return map_i;
}

int GameRoom::get_j()
{
	return map_j;
}

void GameRoom::set_i(int i)
{
	map_i = i;
}

void GameRoom::set_j(int j)
{
	map_j = j;
}
