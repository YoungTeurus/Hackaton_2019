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
		texturePlayer.DrawTexture(Renderer_Display);
	}
	SDL_RenderPresent(Renderer_Display);
	SDL_RenderClear(Renderer_Display);
}

//==============================================================================
