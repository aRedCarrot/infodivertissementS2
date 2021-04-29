#include "Informations.h"



Informations::Informations(Menu* parentMenu):Menu("Informations",parentMenu)
{
	menuOptions.push_back("Niveau des fluides");
	menuOptions.push_back("Température du moteur");
	menuOptions.push_back("Pression des pneus");
	menuOptions.push_back("Consommation moyenne");
	menuOptions.push_back("Quitter");
}


Informations::~Informations()
{
}

void Informations::pickMenuOption()
{
	if (currentMenu == nullptr) // Navige dans le menu courant
	{
		switch (pollUserForSelection())
		{
		case 1:
			cout << "Niveau des fluides apparaitra ici";
			break;
		case 2:
			cout << "La temperature du moteur est de _____°C";
			break;
		case 3:
			cout << "La pression des pneus est de ____PSI";
		case 4:
			cout << "La consommation moyenne du véhicule est de ____L / 100km";
			break;
		case 5:
			parentMenu->deleteChildMenu();
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