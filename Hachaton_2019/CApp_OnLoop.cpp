//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnLoop() {
	if (game) {
		//получаем смещение игрока
		game->tact();
		CoordObjectIn25D(Wind_Display, &texturePlayer, game->get_player_1(), game);
		texturePlayer.OnAnimation(); //анимация запуск
		//vector<GameObject*>* g = game->get_current_objects; 
		printf_s("%d %d %d %d\n", texturePlayer.InGame.x, texturePlayer.InGame.y, texturePlayer.InGame.w, texturePlayer.InGame.h);

		game->get_player_1()->set_cooldown(game->get_player_1()->get_cooldown() - 1); // Уменьшаем кулдаун на 1

		vector<GameObject*>* g = game->get_current_objects();
		for (int i = 0; i < g->size(); i++)
		{
			if (g->at(i)->get_type() == 5) {
				if (g->at(i)->texture == nullptr)
				{
					if (g->at(i)->texture != &Bullet) g->at(i)->texture = &Bullet;
				}
				if (!game->move_gameObject(g->at(i), g->at(i)->get_direction()))
				{
					g->erase(g->begin() + i);
				}
			}

		}
	}
}

//==============================================================================
