#include "GameActor.h"


GameActor::GameActor(SDL_Point spawn_point, int width, int height,
	int start_lvl, int start_hp, int start_mp, int start_dmg, bool start_is_looking_right, int start_type) :
	GameObject(spawn_point, // Вызываю конструктор родителя, передаю ему все необходимые данные
				width,height,
				start_is_looking_right,
				true,	 // bool start_is_rotatable, 
				false,	 // bool start_is_passable,
				false,	 // bool start_is_pushable
				start_type
		)
{
	// Осталось установить лишь свойства, характерные Actor-у
	lvl = start_lvl;
	hp = start_hp;
	mp = start_mp;
	dmg = start_dmg;
}

GameActor::~GameActor()
{
	delete &get_object_rect();
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

void GameActor::attack(GameActor* defencer)
{
	defencer->set_hp(defencer->get_hp() - dmg); // Уменьшаем у защитника жизни на dmg
}


