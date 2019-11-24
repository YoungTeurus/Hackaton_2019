#include "GameMap.h"
#include "GameRoom.h"
#include "RoomTemplates.h"
#include <stdlib.h>
#include <iostream>
// Направления движения
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

extern map< int, Obj_and_Act > all_rooms;

void Map::gener(GameRoom* Curr, int deep)
{
	using namespace std;
	int i = Curr->get_i(), j = Curr->get_j();
	static int room_created = 1;
	int room_template = rand()% NUM_OF_TEMPLATES;//задавать рандомно
	int deepDelta;//программно расчитывается
	int from_start = 0;
	deepDelta = (rand() % 10 + 1) * (deep - from_start);
	//вверх
	if (Curr->get_i() > 0) {
		if (matrix[i - 1][j] == nullptr) {

			matrix[i - 1][j] = new GameRoom(i, j, 1);
			matrix[i - 1][j]->set_i(i - 1);
			matrix[i - 1][j]->set_j(j);
			if (deepDelta > rand() % 100) {
				cout << "i: " << i << " j: " << j << endl;
				gener(matrix[i - 1][j], deep);
			}
		}
	}
	//вправо
	if (Curr->get_j() - 1 < rooms) {
		if (matrix[i][j + 1] == nullptr) {

			matrix[i][j + 1] = new GameRoom(i, j, 1);
			matrix[i][j + 1]->set_i(i);
			matrix[i][j + 1]->set_j(j + 1);
			if (deepDelta > rand() % 100) {
				cout << "i: " << i << " j: " << j << endl;
				gener(matrix[i][j + 1], deep);
			}
		}
	}
	//вниз
	if (Curr->get_i() < rooms - 2) {
		if (matrix[i + 1][j] == nullptr) {
			matrix[i + 1][j] = new GameRoom(i, j, 1);
			matrix[i + 1][j]->set_i(i + 1);
			matrix[i + 1][j]->set_j(j);
			if (deepDelta > rand() % 100) {
				cout << "i: " << i << " j: " << j << endl;
				gener(matrix[i + 1][j], deep);
			}
		}
	}
	//влево
	if (Curr->get_j() > 0)
	{
		if (matrix[i][j - 1]) {
			cout << "i: " << i << " j: " << j << endl;
			matrix[i][j - 1] = new GameRoom(i, j, 1);
			matrix[i][j - 1]->set_i(i);
			matrix[i][j - 1]->set_j(j - 1);
			if (deepDelta > rand() % 100) {
				cout << "i: " << i << " j: " << j << endl;
				gener(matrix[i][j - 1], deep);
			}
		}
	}
}

//гене
void Map::Gen()
{
	matrix = new GameRoom * *[rooms];
	for (int i = 0; i < rooms; i++)
		matrix[i] = new GameRoom * [rooms];
	for (int i = 0; i < rooms; i++)
		for (int j = 0; j < rooms; j++)
			matrix[i][j] = nullptr;

	SDL_Point start_room_index{ 2,2 };

	GameRoom start_room = GameRoom(start_room_index.x, start_room_index.y, 0);
	matrix[start_room_index.x][start_room_index.y] = &start_room;
	gener(&start_room, rooms);
}

int Map::CheckFreeDoor(GameRoom*)
{
	return 0;
}

Map::Map(int rooms)
{
	this->rooms = rooms;
}

Map::~Map()
{
}