#include "GameObject.h"

GameObject::GameObject(
		SDL_Point* spawn_point, // ����� ������
		int width, // ������ ��������
		int height, // ������ ��������
		bool start_is_looking_right, // � ����� ������� ������ ������� ���������� (��. ����)
		bool start_is_rotatable, // ����� �� �������� �������� �������
		bool start_is_passable,
		bool start_is_pushable,
		int start_type = 0 // ��� �������, ���� �����
	){
	// ����� ������� ���������� � �������
	object_rect = new SDL_Rect();
	object_rect->x = spawn_point->x;
	object_rect->y = spawn_point->y;
	object_rect->w = width;
	object_rect->h = height;

	//����� ������� ��������
	is_rotatable = start_is_rotatable;
	is_passable  = start_is_passable;
	is_pushable  = start_is_pushable;
	is_looking_right = start_is_looking_right;

	is_active = false;

	type = start_type;

	// �������������� ��������� �������� ��������� �������
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
	//TO-DO: ������� �������� �� ������������ � ��������� � ����� "������������" ��� ����������� ��������
	// �������� ������ ����� "���� �� �����", ���������, ��� �� �������� ����, �� ��� ���� �� ��������� � �� ��������

	real_x += delX;
	real_y += delY;

	// �������, ��� ���������� X - �������� ������
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