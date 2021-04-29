#include "GPS.h"


GPS::GPS(Menu * parentMenu) : Menu("GPS",parentMenu)
{
	menuOptions.push_back("Voir la carte");
	menuOptions.push_back("Me localiser");
	menuOptions.push_back("Quitter");
}

GPS::~GPS()
{
}

void GPS::pickMenuOption()
{
	if (currentMenu == nullptr) // Navige dans le menu courant
	{
		switch (pollUserForSelection())
		{
		case 1:
			break;
		case 2:
			getMyLocation();
			break;
		case 3:
			parentMenu->deleteChildMenu();
			break;
		case 4:
			break;
		case 5:
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

void GPS::getMyLocation()
{

}
