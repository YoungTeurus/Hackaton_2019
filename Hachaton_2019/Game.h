#pragma once

#include "GameActor.h"
#include "GameObject.h"
#include "GameRoom.h"
#include "Timer.h"
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
	
	void			load_test_room();						// Загружает тестовую комнату в active_room

	void AddBullet();

	//*******Get-еры*********//
	GameActor*		get_player_1() { return player_1; }		// Возвращает первого игрока
	//***********************//

	//*******Set-еры*********//

	//***********************//

private:
	GameActor*		player_1;

	// Текущая структура:
	// Map хранит матрицу Room-ов, каждая из которых имеет list enemies и list objects.
	// При переходе из комнаты в комнату мы получаем эти указатели и работаем с врагами и объектами именно в данной комнате.
	// Таким образом остаётся возможность менять объекты других комнат.

	//TODO:над будет еще подумать, как сообщать от game в интерфейс
	// в текущей идее, мы отсюда забираем в методе интрерфейса onloop какую-то инфу
	// а все draw в методе onRender
	// Забираем current_objects и current_enemies, чтобы отрисовать их.

	vector<GameActor*>* current_enemies;					// Указатель на список врагов в данной (активной) комнате

	vector<GameObject*>* current_objects;					// Указатель на список объектов в данной (активной) комнате

	//Map* map; // Указатель на карту подземелья

	GameRoom*		active_room;							// Указатель на активную комнату

};