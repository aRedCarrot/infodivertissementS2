#include "MainMenu.h"

MainMenu::MainMenu(Menu* parentMenu) : Menu("Menu principale", nullptr)
{
	currentMenu = nullptr;
	menuOptions.push_back("Lecteur multimedia");
	menuOptions.push_back("GPS");
	menuOptions.push_back("Ventilation");
	menuOptions.push_back("Reglage");
	menuOptions.push_back("Communication");
	menuOptions.push_back("Informations du véhicule");
	menuOptions.push_back("Meteo");
	menuOptions.push_back("Quitter");
} 


MainMenu::~MainMenu()
{
	delete currentMenu;
}

void MainMenu::pickMenuOption()
{
	if (currentMenu == nullptr) // Navige dans le menu courant
	{
		switch (pollUserForSelection())
		{
		case 1:
			currentMenu = new LecteurMultimedia(this);
			break;
		case 2:
			currentMenu = new GPS(this);
			break;
		case 3:
			currentMenu = new Ventilation(this);
			break;
		case 4:
			currentMenu = new Reglages(this);
			break;
		case 5:
			currentMenu = new Communication(this);
			break;
		case 6:
			currentMenu = new Informations(this);
			break;
		case 7:
			currentMenu = new Meteo(this);
			break;
		case 8:
			exit(0);
			break;
		default:
			currentMenu = nullptr;
			break;
		}
	}
	else // Un autre sous-menu est actif , aller a celui-ci
	{
		currentMenu->showMenu();
		currentMenu->pickMenuOption();
	}
}
