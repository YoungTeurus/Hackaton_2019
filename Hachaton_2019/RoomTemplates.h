#include "GameObject.h"
#include "GameActor.h"
#include <vector>
#include <map>
#pragma once

using namespace std;

struct Obj_and_Act
{
	vector<GameObject*>* obj_vector;
	vector<GameActor*>* act_vector;
};

// Коллекция всех комнат
// Коллекция имеет
static map< int, Obj_and_Act > all_rooms;

class RoomTemplates {
public:
	RoomTemplates() { // Загрузка и создание всех Template-ов
		vector<GameObject*>* temp_obj_vect = new vector<GameObject*>();
		GameObject* temp_obj = new GameObject(new SDL_Point{ 65,65 },50,50,true,false,false,false,0);
		temp_obj_vect->push_back(temp_obj);
		temp_obj = new GameObject(new SDL_Point{ 90,90 }, 10, 100, true, false, false, false, 0);
		temp_obj_vect->push_back(temp_obj);

		vector<GameActor*>* temp_act_vect = new vector<GameActor*>();
		GameActor* temp_act = new GameActor(new SDL_Point{ 0,0 },55, 55, 1,10,5,3,true,1);
		temp_act_vect->push_back(temp_act);

		Obj_and_Act temp_0 = { temp_obj_vect, temp_act_vect };

		all_rooms[0] = temp_0;
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
};