#include "GameObject.h"
#include "GameActor.h"
#include "RoomTemplates.h"
#include <vector>
#pragma once

// ����� �������

// ����� �� ������ ����� ������� objects � enemies

class GameRoom {
public:
	GameRoom(int i, int j,	// ����������� ������� �� �������� �������� � ����������
		std::vector<GameObject*>* = nullptr,
		std::vector<GameActor*>* = nullptr);

	GameRoom(int i, int j,	// ����������� ������� �� ������ "template"
		int room_template);

	void		add_object(GameObject*);// ��������� ������ 
	void		add_actor(GameActor*);	// ��������� ���������

	int get_i();
	int get_j();

	void set_i(int i);
	void set_j(int j);
private:
	int			map_i, map_j;			// ������� ������� �� ���������� Map

	std::vector<GameObject*>* objects;	// ������ ��������
	std::vector<GameActor*>* actors;	// ������ ����������

	RoomTemplates* room_templates = new RoomTemplates();
};