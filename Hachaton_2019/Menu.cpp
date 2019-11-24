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

void Menu::Render(SDL_Renderer* ren)
{
	Back.DrawTexture(ren);
	start.DrawTexture(ren);
	exit.DrawTexture(ren);
	settings.DrawTexture(ren);
}

int Menu::Update(SDL_Event* Event, SDL_Renderer* ren)
{
	int x = 100;
	int xM, yM;
	SDL_GetMouseState(&xM, &yM);


	if (xM >= WindowSize::Mashtab(&start.InGame).x && xM <= WindowSize::Mashtab(&start.InGame).x + WindowSize::Mashtab(&start.InGame).w && yM >= WindowSize::Mashtab(&start.InGame).y && yM <= WindowSize::Mashtab(&start.InGame).y + WindowSize::Mashtab(&start.InGame).h)
		start.InPicter.y = x * 3;
	else start.InPicter.y = 0;
	if (xM >= WindowSize::Mashtab(&exit.InGame).x && xM <= WindowSize::Mashtab(&exit.InGame).x + WindowSize::Mashtab(&exit.InGame).w && yM >= WindowSize::Mashtab(&exit.InGame).y && yM <= WindowSize::Mashtab(&exit.InGame).y + WindowSize::Mashtab(&exit.InGame).h)
		exit.InPicter.y = x * 5;
	else exit.InPicter.y = x * 2;
	if (xM >= WindowSize::Mashtab(&settings.InGame).x && xM <= WindowSize::Mashtab(&settings.InGame).x + WindowSize::Mashtab(&settings.InGame).w && yM >= WindowSize::Mashtab(&settings.InGame).y && yM <= WindowSize::Mashtab(&settings.InGame).y + WindowSize::Mashtab(&settings.InGame).h)
		settings.InPicter.y = x * 4;
	else settings.InPicter.y = x;

	if (Event->button.button == SDL_BUTTON_LEFT)
	{
		if (xM >= WindowSize::Mashtab(&start.InGame).x && xM <= WindowSize::Mashtab(&start.InGame).x + WindowSize::Mashtab(&start.InGame).w && yM >= WindowSize::Mashtab(&start.InGame).y && yM <= WindowSize::Mashtab(&start.InGame).y + WindowSize::Mashtab(&start.InGame).h)
			return 1; // Нажали "Start"
		if (xM >= WindowSize::Mashtab(&exit.InGame).x && xM <= WindowSize::Mashtab(&exit.InGame).x + WindowSize::Mashtab(&exit.InGame).w && yM >= WindowSize::Mashtab(&exit.InGame).y && yM <= WindowSize::Mashtab(&exit.InGame).y + WindowSize::Mashtab(&exit.InGame).h)
			return 3; // Нажали "Exit"
		if (xM >= WindowSize::Mashtab(&settings.InGame).x && xM <= WindowSize::Mashtab(&settings.InGame).x + WindowSize::Mashtab(&settings.InGame).w && yM >= WindowSize::Mashtab(&settings.InGame).y && yM <= WindowSize::Mashtab(&settings.InGame).y + WindowSize::Mashtab(&settings.InGame).h)
			return 2; // Нажали "Setting"
	}

	return 0;


}

void Menu::Init(SDL_Window* win, SDL_Renderer* ren)
{
	TileMenu = CSurface::OnLoad(ren, "Buttoms.png");
	BackP = CSurface::OnLoad(ren, "Back.png");
	int x = 100;

	SDL_Rect start1 = { 743,SCREEN_HEIGHT / 2 - 50 - 65 - 100,358,100 };
	SDL_Rect exit1 = { 743, SCREEN_HEIGHT / 2 +50 +65 ,358,100 };
	SDL_Rect settings1 = { 743,SCREEN_HEIGHT / 2 -50 ,358,100 };

	start = Texture(TileMenu, &start1, 0, 0, 358, x);
	exit = Texture(TileMenu, &exit1, 0, x * 2, 358, x);
	settings = Texture(TileMenu, &settings1, 0, x, 358, x);
	Back = Texture(BackP, 0, 0, WindowSize::GetW(win), WindowSize::GetH(win));
}
