#include "GameActor.h"


GameActor::GameActor(SDL_Point* spawn_point, int width, int height,
	int start_lvl, int start_hp, int start_mp, int start_dmg, bool start_is_looking_right) :
	GameObject(spawn_point, // ������� ����������� ��������, ������� ��� ��� ����������� ������
				width,height,
				start_is_looking_right,
				true,	 // bool start_is_rotatable, 
				false,	 // bool start_is_passable,
				false)	 // bool start_is_pushable
{
	// �������� ���������� ���� ��������, ����������� Actor-�
	lvl = start_lvl;
	hp = start_hp;
	mp = start_mp;
	dmg = start_dmg;
}

int GameActor::get_hp()
{
	return hp;
}

int GameActor::get_mp()
{
	return mp;
}

int GameActor::get_dmg()
{
	return dmg;
}

void GameActor::set_hp(int hp_)
{
	hp = hp_;
}

void GameActor::set_mp(int mp_)
{
	mp = mp_;
}

void GameActor::set_dmg(int dmg_)
{
	dmg = dmg_;
}

bool GameActor::move(int direction)
{
	switch(direction){
	case 0: return GameObject::move(0,speed);  break; // �������� �����
	case 1: return GameObject::move(speed,0);  break; // �������� ������
	case 2: return GameObject::move(0,-speed); break; // �������� ����
	case 3: return GameObject::move(-speed,0); break; // �������� �����
	default: return false;
	}
}

void GameActor::attack(GameActor* defencer)
{
	defencer->set_hp(defencer->get_hp() - dmg); // ��������� � ��������� ����� �� dmg
}


