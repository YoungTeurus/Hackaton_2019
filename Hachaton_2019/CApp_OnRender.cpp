//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnRender() {
	if (menuOn && !gameOn)//если мы в менюшке
	{
		menu.Render(Renderer_Display);
	}
	else // иначе отрисуем все картиночки из game
	{
		// Если игра запущена - отрисовываем прямоугольник комнаты
		if (game && !pauseOn) {
			SDL_Point* rect_size = game->get_active_room()->get_size();
			SDL_Rect rect_to_draw = {
				(WindowSize::GetW(Wind_Display) / 2) - (rect_size->x / 2),
				(WindowSize::GetH(Wind_Display) / 2) - (rect_size->y / 2),
				rect_size->x,
				rect_size->y
			};
			SDL_SetRenderDrawColor(Renderer_Display, 240, 240, 240, 255);
			SDL_RenderDrawRect(Renderer_Display, &rect_to_draw);
			SDL_SetRenderDrawColor(Renderer_Display, 0, 0, 0, 255);

			//TODO: Избавиться от повторения кода
			// В этом прямоугольнике нужно отрисовать прямоугольники поменьше - объекты
			if (game->get_current_objects()) {
				auto obj_vector = game->get_current_objects();
				for (int i = 0; i < obj_vector->size(); i++) {
					GameObject* current_obj = obj_vector->at(i);
					SDL_Point* rect_pos = current_obj->getCoord();
					SDL_Point* rect_size = current_obj->get_size(); //Временно
					SDL_SetRenderDrawColor(Renderer_Display, 255, 10, 10, 255);
					SDL_RenderDrawRect(Renderer_Display, new SDL_Rect{rect_pos->x + rect_to_draw.x, rect_pos->y + rect_to_draw.y,
														rect_size->x, rect_size->y});
					SDL_SetRenderDrawColor(Renderer_Display, 0, 0, 0, 255);
				}
			}
			if (game->get_current_actors()) {
				auto act_vector = game->get_current_actors();
				for (int i = 0; i < act_vector->size(); i++) {
					GameObject* current_act = act_vector->at(i);
					SDL_Point* rect_pos = current_act->getCoord();
					SDL_Point* rect_size = current_act->get_size(); //Временно
					SDL_SetRenderDrawColor(Renderer_Display, 255, 255, 10, 255);
					SDL_RenderDrawRect(Renderer_Display, new SDL_Rect{ rect_pos->x + rect_to_draw.x, rect_pos->y + rect_to_draw.y,
														rect_size->x, rect_size->y });
					SDL_SetRenderDrawColor(Renderer_Display, 0, 0, 0, 255);
				}
			}

			// Отрисоываем actor-игрока
			if (game->get_player_1()) {
				auto player = game->get_player_1();
				// texturePlayer.DrawTexture(Renderer_Display); Отрисовываем рогалик
				SDL_Point* rect_pos = player->getCoord();
				SDL_Point* rect_size = player->get_size();
				SDL_SetRenderDrawColor(Renderer_Display, 0, 250, 250, 255);
				SDL_RenderDrawRect(Renderer_Display, new SDL_Rect{ rect_pos->x + rect_to_draw.x, rect_pos->y + rect_to_draw.y,
													rect_size->x, rect_size->y });
				SDL_SetRenderDrawColor(Renderer_Display, 0, 0, 0, 255);
			}
			texturePlayer.DrawAnimationTexture(Renderer_Display);
		}
	}
	SDL_RenderPresent(Renderer_Display);
}

//==============================================================================