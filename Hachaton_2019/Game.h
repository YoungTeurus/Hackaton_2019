﻿#pragma once

#include "GameActor.h"
#include "GameObject.h"

class Game
{
public:
	Game();

	// Проверяет столкновения GameActor-а со всеми объектами игрового поля, возвращает:
		// 0 (или false) - нет столкновений ни с чем
		// 1 (или !false) - есть столкновение с чем-то
		// другие числа (или !false) - есть столкновение с чем-то особым (например, дверью или сундуком)
	int				check_all_collisions_with(GameObject* other_object);
	// TO-DO: Коллизии!
	
	//*******Get-еры*********//
	GameActor*		get_player_1() { return player_1; }		// Возвращает первого игрока
	//***********************//

	//*******Set-еры*********//

	//***********************//
private:
	GameActor* player_1;

	// Текущая структура:
	// Map хранит матрицу Room-ов, каждая из которых имеет list enemies и list objects.
	// При переходе из комнаты в комнату мы получаем эти указатели и работаем с врагами и объектами именно в данной комнате.
	// Таким образом остаётся возможность менять объекты других комнат.

	//TODO:над будет еще подумать, как сообщать от game в интерфейс
	// в текущей идее, мы отсюда забираем в методе интрерфейса onloop какую-то инфу
	// а все draw в методе onRender
	// Забираем current_objects и current_enemies, чтобы отрисовать их.

	//Map* map; // Указатель на карту подземелья

	//Room* active_room; // Указатель на активную комнату

	//list<GameActor *>* current_enemies; // Указатель на список врагов в данной (активной) комнате

	//list<GameObject *>* current_objects; // Указатель на список объектов в данной (активной) комнате
};