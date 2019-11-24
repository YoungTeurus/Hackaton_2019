#include "CSurface.h"

CSurface::CSurface()
{

}

SDL_Texture* CSurface::OnLoad(SDL_Renderer *ren, const char* File)
{
	return IMG_LoadTexture(ren, File);
}

void CSurface::CoordObjectIn25D(SDL_Window* win, AnimationTexture* texture, GameObject* object, Game* game)
{
	double koefW = (double)WindowSize::GetW(win) / ((double)game->get_active_room()->get_size()->x + object->get_object_rect()->w);




	double koefH = ((double)WindowSize::GetH(win) - 500.0 * WindowSize::GetKoef()) / (double)(game->get_active_room()->get_size()->y + object->get_object_rect()->h);
	texture->InGame.x = (double)object->getCoord()->x * (double)koefW + 35.0;
	texture->InGame.y = (double)object->getCoord()->y * (double)koefH + 500.0 * WindowSize::GetKoef() - 200.0;
	//texturePlayer.InGame.y = texturePlayer.InGame.y + texturePlayer.InGame.h > WindowSize::GetH(Wind_Display) ? texturePlayer.InGame.y - texturePlayer.InGame.h : texturePlayer.InGame.y;

	texture->InGame.w = ((double)object->getCoord()->y + 200) * (double)texture->GetKoefW();
	texture->InGame.h = ((double)object->getCoord()->y + 200) * (double)texture->GetKoefh();

	//компенсирование по x
	texture->InGame.x -= object->getCoord()->y * texture->GetKoefW() / 2;
}
