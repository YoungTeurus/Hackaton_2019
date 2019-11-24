#pragma once
#include "SDL.h"
#include "GameObject.h"

class GameActor: public GameObject
{
public:
	// GameActor(); // Конструктор по умолчанию

	GameActor(								// Конструктор персонажа
		SDL_Point spawn_point, // Точка спавна
		int width, // ширина модельки
		int height, // высота модельки
		int start_lvl, // Начальный уровень
		int start_hp, // Начальные ХП
		int start_mp, // Начальные МП
		int start_dmg, // Начальный dmg
		bool start_is_looking_right, // В какую сторону игрок смотрит изначально (см. ниже)
		int start_type // Тип персонажа
		);

	~GameActor();

	//*Управление состоянием*//
	void			attack(GameActor*);		// Атакует переданного персонажа, нанося урон его hp в размере своего dmg
	//						 //

	//*******События*********//
	//***********************//
	
	//*******Get-еры*********//
	int				get_hp();				// Получение HP
	int				get_mp();				// Получение MP
	int				get_dmg();				// Получение dmg
	int				get_cooldown();			// Получение cooldown
	//***********************//

	//*******Set-еры*********//
	void			set_hp(int);			// Установка HP
	void			set_mp(int);			// Установка MP
	void			set_dmg(int);			// Установка dmg
	void			set_cooldown(int);		// Установка cooldown
	//***********************//

private:
		
	//****Статы персонажа****//
	int				lvl;					// Уровень персонажа
	int				hp;						// Жизни персонажа
	int				mp;						// Мана персонажа
	
	int				dmg;					// Урон персонажа
	//***********************//

	int				cooldown = 100;			// Время с последней выпущенной пули
	
};

