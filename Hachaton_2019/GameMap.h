#pragma once
#include "GameRoom.h"

class Map
{
public:
	int CheckFreeDoor(GameRoom*);
	//Возвращает число **** из 1 и 3 которое отображает состояние соседних комнат
	//1 - свободно для создания; 3 - Уперлись в край массива
	Map(int rooms);
	// выделяет память для rooms*rooms указателей
	~Map();
	//добавить
	GameRoom*** matrix;
	int rooms;
	//количество комнат
	void Gen();
	// Создает карту
	int* mas;
	void gener(GameRoom* Curr, int deep);
};