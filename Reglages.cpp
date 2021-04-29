#include "Reglages.h"



Reglages::Reglages(Menu* parentMenu) :Menu("Reglages", parentMenu)
{
	menuOptions.push_back("Changer le nom du conducteur");
	menuOptions.push_back("Changer l'heure");
	menuOptions.push_back("Quitter");
}


Reglages::~Reglages()
{

}


void Reglages::pickMenuOption()
{
	if (currentMenu == nullptr) // Navige dans le menu courant
	{
		switch (pollUserForSelection())
		{
		case 1:
			cout << "Il faut changer le nom du conducteur ici";
			break;
		case 2:
			cout << "Comment on faire pour changer l'heure xD";
			break;
		case 3:
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