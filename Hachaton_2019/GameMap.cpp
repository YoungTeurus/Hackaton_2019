#include "GameMap.h"
#include "GameRoom.h"
#include <stdlib.h>

// Направления движения
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

void Map::gener(GameRoom* Curr, int deep)
{
	int i = Curr->get_i(), j = Curr->get_j();
	static int room_created = 1;
	int room_template = 0;//задавать рандомно
	int deepDelta;//программно расчитывается
	int from_start = 0;
	deepDelta = (rand() % 10 + 1) * (deep - from_start);
	//вверх
	matrix[i - 1][j] = new GameRoom(i,j,1);
	matrix[i - 1][j]->set_i(i - 1);
	matrix[i - 1][j]->set_j(j);
	if (deepDelta > rand() % 100)
		gener(matrix[i - 1][j], deep);
	//вправо
	matrix[i][j + 1] = new GameRoom(i, j, 1);
	matrix[i][j + 1]->set_i(i - 1);
	matrix[i][j + 1]->set_j(j);
	if (deepDelta > rand() % 100)
		gener(matrix[i - 1][j], deep);
	//вниз
	matrix[i + 1][j] = new GameRoom(i, j, 1);
	matrix[i + 1][j]->set_i(i - 1);
	matrix[i + 1][j]->set_j(j);
	if (deepDelta > rand() % 100)
		gener(matrix[i - 1][j], deep);
	//влево
	matrix[i][j - 1] = new GameRoom(i, j, 1);
	matrix[i][j - 1]->set_i(i - 1);
	matrix[i][j - 1]->set_j(j);
	if (deepDelta > rand() % 100)
		gener(matrix[i - 1][j], deep);

}

//гене
void Map::Gen()
{

	GameRoom start_room = GameRoom(5,5,1);
	gener(&start_room, 10);
}

int Map::CheckFreeDoor(GameRoom*)
{
	return 0;
}

Map::Map(int rooms)
{
}

Map::~Map()
{
}