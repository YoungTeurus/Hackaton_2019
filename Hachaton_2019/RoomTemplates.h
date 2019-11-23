#include "GameObject.h"
#include "GameActor.h"
#include <map>
#pragma once

// Коллекция всех комнат
// Коллекция имеет
std::map< int, vector<GameObject*>* , vector<GameActor*>* > all_rooms;

class RoomTemplates {
public:
	RoomTemplates(); // Загрузка и создание всех Template-ов
private:
};