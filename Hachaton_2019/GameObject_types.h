// ���������� ��� ���� ��������

#define WALL SDL_Point{ 0,0 }, 0, 0, false, false, false, false, -1 // ������ �������: "������� �����", �� ����� �������, �� ����������, �� ���������.
#define PLAYER_ONE 1 // Actor, ����� 1
#define ROCK 50, 50, true, false, false, false, 2 // Object, ��������� ������, �� ����� �������, �� ����������, �� ���������. �������: (50,50)
#define ROCK_LONG_HORIZONTAL 100, 50, true, false, false, false, 2 // Object, ��������� ������, �� ����� �������, �� ����������, �� ���������. �������: (100,50)
#define ROCK_LONG_VERTICAL 50, 100, true, false, false, false, 2 // Object, ��������� ������, �� ����� �������, �� ����������, �� ���������. �������: (50,100)
#define ROCK_BIG 100, 100, true, false, false, false, 2 // Object, ��������� ������, �� ����� �������, �� ����������, �� ���������. �������: (100,100)
#define PUSHABLE_ROCK 50, 50, true, false, false, true, 2 // Object, ��������� ������, �� ����� �������, �� ����������, ���������. �������: (50,50)
#define EXIT_LEFT true, false, true, false, 51 // Object, ��������� ������, �� ����� �������, ����������, �� ���������, ���������� ������ � ������ ������� �����
#define EXIT_RIGHT true, false, true, false, 53 // Object, ����������, �� ���������, ���������� ������ � ������ ������� �����
#define EXIT_UP true, false, true, false, 50 // Object, ����������, �� ���������, ���������� ������ � ������ ������� �����
#define EXIT_DOWN true, false, true, false, 52 // Object, ����������, �� ���������, ���������� ������ � ������ ������� �����
#define TEST_ACTOR 45, 45, 7 // Actor, ����������, �� ���������. �������: (45,45)