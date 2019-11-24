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

	size = SDL_Point{ 500, 500 };
}

GameRoom::GameRoom(int i, int j,
	int room_template) {
	map_i = i;
	map_j = j;

	// Загружаем "template" комнаты из определённого RoomTemplate
	objects = room_templates->get_obj_vector(room_template);
	actors = room_templates->get_act_vector(room_template);
	size = *room_templates->get_size(room_template);

	// Если 
	if (!(objects) || !(actors)) {
		std::cout << "Не был найден подходящий template";
	}

	
}

GameRoom::~GameRoom()
{
	delete &size;

	for (auto i = 0; i < actors->size(); i++)
		delete actors->at(i);
	for (auto i = 0; i < objects->size(); i++)
		delete objects->at(i);

	delete room_templates;
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

SDL_Point GameRoom::get_size()
{
	return size;
}

std::vector<GameObject*>* GameRoom::get_objects()
{
	return objects;
}

std::vector<GameActor*>* GameRoom::get_actors()
{
	return actors;
}

void GameRoom::set_i(int i)
{
	map_i = i;
}

void GameRoom::set_j(int j)
{
	map_j = j;
}
