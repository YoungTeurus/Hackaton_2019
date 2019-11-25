#include "GameObject.h"

GameObject::GameObject(
		SDL_Point spawn_point, // Точка спавна
		int width, // ширина модельки
		int height, // высота модельки
		bool start_is_looking_right, // В какую сторону объект смотрит изначально (см. ниже)
		bool start_is_rotatable, // Нужно ли отражать текстуру объекта
		bool start_is_passable,
		bool start_is_pushable,
		int start_type = 0 // Тип объекта, если нужен
	){
	// Задаём объекту координаты и размеры
	object_rect = SDL_Rect{0,0};
	object_rect.x = spawn_point.x;
	object_rect.y = spawn_point.y;
	object_rect.w = width;
	object_rect.h = height;

	//Задаём объекту свойства
	is_rotatable = start_is_rotatable;
	is_passable  = start_is_passable;
	is_pushable  = start_is_pushable;
	is_looking_right = start_is_looking_right;

	is_active = false;

	type = start_type;
	//текстурка обьекта
	
	// Инициализируем начальное реальное положение объекта
	real_x = object_rect.x;
	real_y = object_rect.y;
}

GameObject::~GameObject()
{
	delete &object_rect;
}

void GameObject::convert_pos()
{
	object_rect.x = int(real_x);
	object_rect.y = int(real_y);
}

bool GameObject::move(double delX, double delY)
{
	//TO-DO: Сделать проверку на столкновение с объектами и УМНОЕ "отскакивание" без перемещения текстуры
	// Персонаж вполне может "идти на месте", показывая, что он пытается идти, но при этом НЕ двигаться и НЕ дёргаться

	//double prev_real_x = real_x, prev_real_y = real_y; // Сохраняем предыдущие значения x и y, чтобы можно было откатиться
	//int prev_x = object_rect->x, prev_y = object_rect->y;

	// Прибавляем перемещение
	real_x += delX;
	real_y += delY;
	convert_pos();
	
	// Считаем, что увеличение X - движение вправо
	if (delX >= 0)
		is_looking_right = true;
	else
		is_looking_right = false;

	return true;
}

bool GameObject::move(int direction)
{
	switch (direction) {
	case 0: return GameObject::move(0, -get_speed());  break; // Движение вверх
	case 1: return GameObject::move(get_speed(), 0);  break; // Движение вправо
	case 2: return GameObject::move(0, get_speed()); break; // Движение вниз
	case 3: return GameObject::move(-get_speed(), 0); break; // Движение влево
	default: return false;
	}
}

bool GameObject::on_colision(SDL_Rect* second_rect)
{
	if (SDL_HasIntersection(&object_rect, second_rect))
		return true;
	return false;
}


SDL_Point GameObject::getCoord()
{
	return SDL_Point{ object_rect.x, object_rect.y };
}

SDL_Point GameObject::get_size()
{
	return SDL_Point{ object_rect.w, object_rect.h };
}

SDL_Rect GameObject::get_object_rect()
{
	return object_rect;
}

int GameObject::get_type()
{
	return type;
}

bool GameObject::get_is_passable()
{
	return is_passable;
}

bool GameObject::get_is_pushable()
{
	return is_pushable;
}

double GameObject::get_speed()
{
	return speed;
}

bool GameObject::get_direction()
{
	return is_looking_right;
}


int GameObject::getStatus()
{
	return status;
}


void GameObject::setStatus(int s)
{
	status = static_cast<Status>(s);
}


void GameObject::set_type(int tip)
{
	type = tip;
}

void GameObject::set_direction(bool dir)
{
	is_looking_right = dir;
}

void GameObject::setCoord(SDL_Point* pnt)
{
	real_x = pnt->x;
	real_y = pnt->y;
	convert_pos(); // Меняем координаты x и y
}


void GameObject::set_speed(int s)
{
	speed = s;
}


void GameObject::setIsPushable(bool p)
{
	is_pushable = p;
}

void GameObject::setIsPassable(bool p)
{
	is_passable = p;
}


void GameObject::spawn()
{
	is_active = true;
}
