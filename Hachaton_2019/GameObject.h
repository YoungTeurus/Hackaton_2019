#pragma once
#include "SDL.h"

class GameObject
{
public:
	GameObject(); // ����������� �� ���������

	GameObject(
		SDL_Point* spawn_point, // ����� ������
		int width, // ������ ��������
		int height, // ������ ��������
		bool start_is_looking_right, // � ����� ������� ������ ������� ���������� (��. ����)
		bool start_is_rotatable, // ����� �� �������� �������� �������
		bool start_is_passable,
		bool start_is_pushable
	);

	//*���������� ����������*//
	void			spawn();				// ������� ������, ����� ��� ��������
	bool			move(double, double);	// ������� ������ �� ��������� ��������. ���������� true, ���� ������ ���������
	//						 //

	//*******�������*********//
	bool			on_colision(SDL_Rect*);	// ��������� �������� �� ������ �������
	friend int		check_all_collisions_with(GameObject* other_object); // ��. Game.h
	//***********************//

	//*******Get-���*********//
	SDL_Point*		getCoord();				// ��������� ��������� �������
	//***********************//

	//*******Set-���*********//
	void			setCoord(SDL_Point*);	// ��������� ��������� �������
	//***********************//

private:

	int type; //��

	void			convert_pos();			// ��������� real-�� ������� ������� � ��������� int-�� ��� coord

	SDL_Rect*		object_rect;			// �������� �������: ��� ���������� � �������
	
	double			real_x, real_y;			// �������������� ���������� �������

	bool			is_active;				// ������� �� � ������ ������ ������

	bool			is_looking_right;		// ������� �� ������ �������
	bool			is_rotatable;				// ����� �� �������� �������� ������� (����� - ��, ����� � ����� - ���) ��� �����������
	
	//***�������� �������****//
	bool			is_passable;			// �������� �� ������ ������ ������?
	bool			is_pushable;			// �������� �� ������� ������?
	//***********************//
};

