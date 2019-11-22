#include "Menu.h"

Menu::Menu(SDL_Renderer * ren)
{
	Init(ren);
}

Menu::~Menu()
{
	SDL_FreeSurface(exit_buttom_sur);
	SDL_FreeSurface(start_buttom_sur);
	SDL_FreeSurface(settings_buttom_sur);
}

bool Menu::Render(SDL_Renderer* ren)
{

}

void Menu::Update(SDL_Event* Event, SDL_Renderer* ren)
{







}

void Menu::Init(SDL_Renderer* ren)
{




}
