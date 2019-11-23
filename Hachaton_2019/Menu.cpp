#include "Menu.h"

Menu::Menu()
{
	BackP = nullptr;
	TileMenu = nullptr;
}

Menu::Menu(SDL_Window* win, SDL_Renderer * ren)
{
	Init(win,ren);
}

Menu::~Menu()
{
	
}

bool Menu::Render(SDL_Renderer* ren)
{
	Back.DrawTexture(ren);
	start.DrawTexture(ren);
	exit.DrawTexture(ren);
	settings.DrawTexture(ren);
	return false;
}

void Menu::Update(SDL_Event* Event, SDL_Renderer* ren)
{








}

void Menu::Init(SDL_Window* win, SDL_Renderer* ren)
{
	TileMenu = CSurface::OnLoad(ren, "Buttoms.png");
	BackP = CSurface::OnLoad(ren, "Back.png");
	int x = 100;

	SDL_Rect start1 = { WindowSize::GetW(win) / 2 - 358 / 2,WindowSize::GetH(win) / 2 - 150,358,100 };
	SDL_Rect exit1 = { WindowSize::GetW(win) / 2 - 358 / 2, WindowSize::GetH(win) / 2 + 100 ,358,100 };
	SDL_Rect settings1 = { WindowSize::GetW(win) / 2 - 358 / 2,WindowSize::GetH(win) / 2 - 50,358,100 };


	start = Texture(TileMenu, &start1, 0, 0, 358, x);
	exit = Texture(TileMenu, &exit1, 0, x * 2, 358, x);
	settings = Texture(TileMenu, &settings1, 0, x, 358, x);
	Back = Texture(BackP, 0, 0, WindowSize::GetW(win), WindowSize::GetH(win));
}
