#include "GameObject.h"

GameObject::GameObject(
		SDL_Point* spawn_point, // Точка спавна
		int width, // ширина модельки
		int height, // высота модельки
		bool start_is_looking_right, // В какую сторону объект смотрит изначально (см. ниже)
		bool start_is_rotatable, // Нужно ли отражать текстуру объекта
		bool start_is_passable,
		bool start_is_pushable,
		int start_type = 0 // Тип объекта, если нужен
	){
	// Задаём объекту координаты и размеры
	object_rect = new SDL_Rect();
	object_rect->x = spawn_point->x;
	object_rect->y = spawn_point->y;
	object_rect->w = width;
	object_rect->h = height;

	//Задаём объекту свойства
	is_rotatable = start_is_rotatable;
	is_passable  = start_is_passable;
	is_pushable  = start_is_pushable;
	is_looking_right = start_is_looking_right;

	is_active = false;

	type = start_type;

	// Инициализируем начальное реальное положение объекта
	real_x = object_rect->x;
	real_y = object_rect->y;
}

void GameObject::convert_pos()
{
	object_rect->x = int(real_x);
	object_rect->y = int(real_y);
}

bool GameObject::move(double delX, double delY)
{
	//TO-DO: Сделать проверку на столкновение с объектами и УМНОЕ "отскакивание" без перемещения текстуры
	// Персонаж вполне может "идти на месте", показывая, что он пытается идти, но при этом НЕ двигаться и НЕ дёргаться

	real_x += delX;
	real_y += delY;

	// Считаем, что увеличение X - движение вправо
	if (delX >= 0)
		is_looking_right = true;
	else
		is_looking_right = false;

	convert_pos();

	return true;;
}

bool GameObject::on_colision(SDL_Rect* second_rect)
{
	if (SDL_HasIntersection(object_rect, second_rect))
		return true;
	return false;
}


SDL_Point* GameObject::getCoord()
{
	return new SDL_Point{ object_rect->x, object_rect->y };
}

void GameObject::setCoord(SDL_Point* pnt)
{
	object_rect->x = pnt->x;
	object_rect->y = pnt->y;
}


void GameObject::spawn()
{
	is_active = true;
}