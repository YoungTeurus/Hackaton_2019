//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnLoop() {
	if (game) {
		//получаем смещение игрока
		game->tact();
		CoordObjectIn25D(Wind_Display, &texturePlayer, game->get_player_1(), game);

		vector<GameObject*> tmp_object = *game->get_active_room()->get_objects();
		
		vector<GameActor*> act_vector2 = *game->get_current_actors();

		for (int i = 0; i < act_vector2.size(); i++)
		{
			CoordObjectIn25D(Wind_Display, &act_vector2[i]->texture, act_vector2[i], game);
			act_vector2[i]->texture.OnAnimation();
		}


		for (int i = 0; i < tmp_object.size(); i++)
		{
			CoordObjectIn25D(Wind_Display, &tmp_object[i]->texture, tmp_object[i], game);
			tmp_object[i]->texture.OnAnimation();
		}


		texturePlayer.OnAnimation(); //анимация запуск
		//vector<GameObject*>* g = game->get_current_objects;
		printf_s("%d %d %d %d\n", texturePlayer.InGame.x, texturePlayer.InGame.y, texturePlayer.InGame.w, texturePlayer.InGame.h);
	}
}

//==============================================================================
