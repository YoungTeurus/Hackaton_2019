#pragma once
#include "SDL.h"

class GameObject
{
public:
	GameObject(); // Конструктор по умолчанию

	GameObject(
		SDL_Point* spawn_point, // Точка спавна
		int width, // ширина модельки
		int height, // высота модельки
		bool start_is_looking_right, // В какую сторону объект смотрит изначально (см. ниже)
		bool start_is_rotatable, // Нужно ли отражать текстуру объекта
		bool start_is_passable,
		bool start_is_pushable
	);

	//*Управление состоянием*//
	void			spawn();				// Спавнит объект, делая его активным
	bool			move(double, double);	// Двигает объект на указанное смещение. Возвращает true, если объект СДВИНУЛСЯ
	//						 //

	//*******События*********//
	bool			on_colision(SDL_Rect*);	// Проверяет касается ли объект области
	friend int		check_all_collisions_with(GameObject* other_object); // См. Game.h
	//***********************//

	//*******Get-еры*********//
	SDL_Point*		getCoord();				// Получение координат объекта
	//***********************//

	//*******Set-еры*********//
	void			setCoord(SDL_Point*);	// Установка координат объекта
	//***********************//

private:

	int type; //Ун

	void			convert_pos();			// Переводим real-ую позицию объекта к ближайшим int-ам для coord

	SDL_Rect*		object_rect;			// Моделька объекта: его координаты и размеры
	
	double			real_x, real_y;			// Действительные координаты объекта

	bool			is_active;				// Активен ли в данный момент объект

	bool			is_looking_right;		// Смотрит ли объект направо
	bool			is_rotatable;				// Нужно ли отражать текстуру объекта (игрок - да, бочки и камни - нет) при перемещении
	
	//***Свойства объекта****//
	bool			is_passable;			// Возможно ли пройти сквозь объект?
	bool			is_pushable;			// Возможно ли токнуть объект?
	//***********************//
};

