// ќпредел€ем все типы объектов

#define WALL SDL_Point{ 0,0 }, 0, 0, false, false, false, false, -1 // —тенка комнаты: "смотрит влево", не нужно вращать, не проходимый, не толкаемый.
#define PLAYER_ONE 1 // Actor, игрок 1
#define ROCK 50, 50, true, false, false, false, 2 // Object, повЄрнутый вправо, не нужно вращать, не проходимый, не толкаемый. –азмеры: (50,50)
#define ROCK_LONG_HORIZONTAL 100, 50, true, false, false, false, 2 // Object, повЄрнутый вправо, не нужно вращать, не проходимый, не толкаемый. –азмеры: (100,50)
#define ROCK_LONG_VERTICAL 50, 100, true, false, false, false, 2 // Object, повЄрнутый вправо, не нужно вращать, не проходимый, не толкаемый. –азмеры: (50,100)
#define ROCK_BIG 100, 100, true, false, false, false, 2 // Object, повЄрнутый вправо, не нужно вращать, не проходимый, не толкаемый. –азмеры: (100,100)
#define PUSHABLE_ROCK 50, 50, true, false, false, true, 2 // Object, повЄрнутый вправо, не нужно вращать, не проходимый, толкаемый. –азмеры: (50,50)
#define EXIT_LEFT true, false, true, false, 51 // Object, повЄрнутый вправо, не нужно вращать, проходимый, не толкаемый, перемещает игрока в другую комнату влево
#define EXIT_RIGHT true, false, true, false, 53 // Object, проходимый, не толкаемый, перемещает игрока в другую комнату влево
#define EXIT_UP true, false, true, false, 50 // Object, проходимый, не толкаемый, перемещает игрока в другую комнату влево
#define EXIT_DOWN true, false, true, false, 52 // Object, проходимый, не толкаемый, перемещает игрока в другую комнату влево
#define TEST_ACTOR 45, 45, 7 // Actor, проходимый, не толкаемый. –азмеры: (45,45)