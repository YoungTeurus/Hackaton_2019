#include "GameObject.h"
#include "GameActor.h"
#include "RoomTemplates.h"
#include <vector>
#pragma once

// Класс комнаты

// Здесь мы должны иметь массивы objects и enemies

class GameRoom {
public:
	GameRoom(int i, int j,	// Конструктор комнаты по массивам объектов и персонажей
		std::vector<GameObject*>* = nullptr,
		std::vector<GameActor*>* = nullptr);

	GameRoom(int i, int j,	// Конструктор комнаты по номеру "template"
		int room_template);

	void		add_object(GameObject*);// Добавляет объект 
	void		add_actor(GameActor*);	// Добавляет персонажа

	int get_i();
	int get_j();

	void set_i(int i);
	void set_j(int j);
private:
	int			map_i, map_j;			// Индексы комнаты на глобальной Map

	std::vector<GameObject*>* objects;	// Массив объектов
	std::vector<GameActor*>* actors;	// Массив персонажей

	RoomTemplates* room_templates = new RoomTemplates();
};