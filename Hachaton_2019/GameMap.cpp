#include "GameMap.h"
#include "GameMap.h"
#include "Map.h"
#include"GameRoom.h"

// Направления движения
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

void Map::gener(GameRoom* Curr, int deep)
{
	
	if (deep > 100)
	{
		int i=Curr->i,j=Curr->j;
		static room_created=1;
		int room_template = 0;//задавать рандомно
		int deepDelta;//программно расчитывается
		int from_start;
		deepDelta = (rand()%10+1)*(deep - from_start);
		

		//вверх
		matrix[i - 1][j] = new GameRoom(i, j, room_template);
		matrix[i - 1][j]->i = i - 1;
		matrix[i - 1][j]->j = j;
		gener(matrix[i - 1][j], deep + deepDelta);
		//вправо
		matrix[i][j+1] = new GameRoom(i, j, room_template);
		matrix[i][j+1]->i = i - 1;
		matrix[i][j+1]->j = j;
		gener(matrix[i - 1][j], deep + deepDelta);
		//вниз
		matrix[i + 1][j] = new GameRoom(i, j, room_template);
		matrix[i + 1][j]->i = i - 1;
		matrix[i + 1][j]->j = j;
		gener(matrix[i - 1][j], deep + deepDelta);
		//влево
		matrix[i][j - 1] = new GameRoom(i, j, room_template);
		matrix[i][j - 1]->i = i - 1;
		matrix[i][j - 1]->j = j;
		gener(matrix[i - 1][j], deep + deepDelta);
	}
}
 
//гене
void Map::Gen()
{

	GameRoom strat_room(5,5,0);
	gener(start_room,10,1);
}

Map::~Map()
{
}
