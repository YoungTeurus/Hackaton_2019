//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnLoop() {
	if (game) {
		//получаем смещение игрока
		game->tact();
		texturePlayer.InGame.x = game->get_player_1()->getCoord()->x;
		texturePlayer.InGame.y = game->get_player_1()->getCoord()->y;
		texturePlayer.OnAnimation(); //анимация запуск
		//vector<GameObject*>* g = game->get_current_objects;
		for (int i = 0; i < 0; i++)
		{
			//g->at(i)->move;
		}

	}
}

//==============================================================================
