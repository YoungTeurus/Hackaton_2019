//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnRender() {
	//SDL_RenderClear(Renderer_Display);

	CSurface::OnDraw(Renderer_Display, IMG, 0, 0, 100, 100, 25, 25, 100, 100);


	menu.Render(Renderer_Display);


	SDL_RenderPresent(Renderer_Display);
}

//==============================================================================
