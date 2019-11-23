//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnRender() {


	switch (IsWhat)
	{
	case 0: menu.Render(Renderer_Display); break;
	case 1:
	case 2:
	case 3: Running = false; break;
	default:
		break;
	}
	
	SDL_RenderPresent(Renderer_Display);
}

//==============================================================================
