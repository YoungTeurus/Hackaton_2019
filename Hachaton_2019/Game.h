﻿#pragma once

#include "GameActor.h"
#include "GameObject.h"
#include "GameRoom.h"
#include "GameMap.h"
#include <stdlib.h>
#include <math.h>

class Game
{
public:
	Game();

	~Game();

	// Проверяет столкновения GameActor-а со всеми объектами игрового поля, возвращает:
		// -1 - столкновение со стенкой
		// 0 (или false) - нет столкновений ни с чем
		// 1 (или !false) - есть столкновение с чем-то
		// другие числа (или !false) - есть столкновение с чем-то особым (например, дверью или сундуком)
	GameObject*		check_all_collisions(GameObject* object);
	// Двигает игрока, потом проверяет колизии, если столкнулся с чем-то, тогда подвинет обратно
	bool			move_gameObject(GameObject* object, int direction);
	
	void			load_test_room();						// Загружает тестовую комнату в active_room
	void			load_room(int i, int j);				// Загружает комнату map->matrix[i][j] в active_room

	//*******Get-еры*********//
	GameActor*		get_player_1() { return player_1; }		// Возвращает первого игрока
	GameRoom*		get_active_room() { return active_room; }// Возвращает активную комнату
	vector<GameObject*>* get_current_objects() { return current_objects; }// Возвращает текущие объекты в комнате
	vector<GameActor*>* get_current_actors() { return current_actors; }// Возвращает текущих персонажей в комнате
	//***********************//

	//*******Set-еры*********//

	//***********************//
	void			CreateBullet();							// Создаёт новую пулю

	void			tact();									// Проходится по всем actor-ам и двигает их, если они относятся к определённому виду

private:
	GameActor*		player_1;

	// Текущая структура:
	// Map хранит матрицу Room-ов, каждая из которых имеет list enemies и list objects.
	// При переходе из комнаты в комнату мы получаем эти указатели и работаем с врагами и объектами именно в данной комнате.
	// Таким образом остаётся возможность менять объекты других комнат.

	//TODO:над будет еще подумать, как сообщать от game в интерфейс
	// в текущей идее, мы отсюда забираем в методе интрерфейса onloop какую-то инфу
	// а все draw в методе onRender
	// Забираем current_objects и current_actors, чтобы отрисовать их.

	// Функции класса
	double			getDistance(GameObject*, GameObject*);	// Возвращает расстояние между двумя объектами

	// Данные класса

	Map* map; // Указатель на карту подземелья

	GameRoom*		active_room;							// Указатель на активную комнату

	vector<GameActor*>*  current_actors;					// Указатель на список врагов в данной (активной) комнате

	vector<GameObject*>* current_objects;					// Указатель на список объектов в данной (активной) комнате
};