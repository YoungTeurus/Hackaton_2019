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

	~GameRoom();

	void		add_object(GameObject*);// Добавляет объект 
	void		add_actor(GameActor*);	// Добавляет персонажа

	//*******Get-еры*********//
	int			get_i();				// Возвращает поле i
	int			get_j();				// Возвращает поле j

	SDL_Point	get_size();				// Возвращает размеры комнаты

	std::vector<GameObject*>* get_objects();// Возвращает массив объектов 
	std::vector<GameActor*>* get_actors();// Возвращает массив объектов 
	//***********************//

	//*******Set-еры*********//
	void		set_i(int i);			// Устанавливает поле i
	void		set_j(int j);			// Устанавливает поле j

	//***********************//

private:
	int			map_i, map_j;			// Индексы комнаты на глобальной Map

	SDL_Point	size;					// Размеры комнаты

	std::vector<GameObject*>* objects;	// Массив объектов
	std::vector<GameActor*>* actors;	// Массив персонажей

	RoomTemplates* room_templates = new RoomTemplates();
};