// Определяем все типы объектов

#define PLAYER_ONE 1 // Actor, игрок 1
#define ROCK 50, 50, true, false, false, false, 2 // Object, повёрнутый вправо, не нужно вращать, не проходимый, не толкаемый. Размеры: (50,50)
#define ROCK_LONG_HORIZONTAL 100, 50, true, false, false, false, 2 // Object, повёрнутый вправо, не нужно вращать, не проходимый, не толкаемый. Размеры: (100,50)
#define ROCK_LONG_VERTICAL 50, 100, true, false, false, false, 2 // Object, повёрнутый вправо, не нужно вращать, не проходимый, не толкаемый. Размеры: (50,100)
#define ROCK_BIG 100, 100, true, false, false, false, 2 // Object, повёрнутый вправо, не нужно вращать, не проходимый, не толкаемый. Размеры: (100,100)
#define EXIT_LEFT true, false, true, false, 3 // Object, повёрнутый вправо, не нужно вращать, проходимый, не толкаемый, перемещает игрока в другую комнату влево
#define EXIT_RIGHT true, false, true, false, 4 // Object, проходимый, не толкаемый, перемещает игрока в другую комнату влево
#define EXIT_UP true, false, true, false, 5 // Object, проходимый, не толкаемый, перемещает игрока в другую комнату влево
#define EXIT_DOWN true, false, true, false, 6 // Object, проходимый, не толкаемый, перемещает игрока в другую комнату влево
#define TEST_ACTOR 50, 50, 7 // Actor, проходимый, не толкаемый. Размеры: (50,50)