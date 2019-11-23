#include <SDL.h>
#include "GameObject.h"
#include "GameActor.h"
#include <vector>
#pragma once

// ����� �������

// ����� �� ������ ����� ������� objects � enemies

class GameRoom{
public:
				GameRoom(int i, int j,	// ����������� ������� �� �������� �������� � ����������
					std::vector<GameObject*> start_objects = nullptr,
					std::vector<GameActor*>	start_actors = nullptr);
				GameRoom(int i, int j,	// ����������� ������� �� ������ "template"
					int room_template);

	void		add_object(GameObject*);// ��������� ������ 
	void		add_actor(GameActor*);	// ��������� ���������
private:
	int			map_i, map_j;			// ������� ������� �� ���������� Map
	
	std::vector<GameObject*> objects;		// ������ ��������
	std::vector<GameActor*>	actors;			// ������ ����������
}