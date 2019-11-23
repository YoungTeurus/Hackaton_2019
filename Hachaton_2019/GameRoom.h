#include <SDL.h>
#include "GameObject.h"
#include "GameActor.h"
#include <vector>
#pragma once

// Класс комнаты

// Здесь мы должны иметь массивы objects и enemies

class GameRoom{
public:
				GameRoom(int i, int j,	// Конструктор комнаты по массивам объектов и персонажей
					std::vector<GameObject*> start_objects = nullptr,
					std::vector<GameActor*>	start_actors = nullptr);
				GameRoom(int i, int j,	// Конструктор комнаты по номеру "template"
					int room_template);

	void		add_object(GameObject*);// Добавляет объект 
	void		add_actor(GameActor*);	// Добавляет персонажа
private:
	int			map_i, map_j;			// Индексы комнаты на глобальной Map
	
	std::vector<GameObject*> objects;		// Массив объектов
	std::vector<GameActor*>	actors;			// Массив персонажей
}