#pragma once
#include "SDL.h"
#include"GameTexture.h"
class GameObject
{
public:
	// GameObject(); // Конструктор по умолчанию

	GameObject(
		SDL_Point* spawn_point, // Точка спавна
		int width, // ширина модельки
		int height, // высота модельки
		bool start_is_looking_right, // В какую сторону объект смотрит изначально (см. ниже)
		bool start_is_rotatable, // Нужно ли отражать текстуру объекта
		bool start_is_passable, // Можно ли пройти сквозь объект
		bool start_is_pushable, // Можно ли толкать объект
		int start_type // Тип объекта, если нужен
	);

	//*Управление состоянием*//
	void			spawn();				// Спавнит объект, делая его активным
	bool			move(double, double);	// Двигает объект на указанное смещение. Возвращает true, если объект СДВИНУЛСЯ
	//						 //

	//*******События*********//
	bool			on_colision(SDL_Rect*);	// Проверяет касается ли объект области
	// friend int		check_all_collisions_with(GameObject* other_object); // См. Game.h
	//***********************//

	//*******Get-еры*********//
	SDL_Point*		getCoord();				// Получение координат объекта
	SDL_Point*		get_size();				// Получение размеров модельки объекта
	SDL_Rect*		get_object_rect();		// Получение модельки объекта
	int				get_type();				// Получение типа объекта
	//***********************//

	//*******Set-еры*********//
	void			setCoord(SDL_Point*);	// Установка координат объекта
	//***********************//
	GameTexture* texture;

	void SetTexture(const char*);
private:

	int				type;					//Уникальный тип объекта, требуемый для различения объектов, их отрисовки и всего в этом духе
	// Список всех типов:
	// 0 - универсальный объект
	// 1 - первый игрок
	// 2 - второй игрок
	// 3 - враг

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

