#include "GameObject.h"
#include "GameActor.h"
#include <map>
#pragma once

// ��������� ���� ������
// ��������� �����
std::map< int, vector<GameObject*>* , vector<GameActor*>* > all_rooms;

class RoomTemplates {
public:
	RoomTemplates(); // �������� � �������� ���� Template-��
private:
};