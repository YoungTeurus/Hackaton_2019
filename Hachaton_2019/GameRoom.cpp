#include "GameRoom.h"

GameRoom::GameRoom(int i, int j,	// Конструктор комнаты
	vector<GameObject*> start_objects,
	vector<GameActor*>	start_actors)
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

	// Загружаем "template" комнаты откуда-то
	// objects = RoomTemplates[room_template]->objects;
	// actors = RoomTemplates[room_template]->actors;
}

void GameRoom::add_object(GameObject* obj_to_add) {
	objects.push_back(obj_to_add);
}

void GameRoom::add_actor(GameActor* act_to_add) {
	actors.push_back(act_to_add);
}