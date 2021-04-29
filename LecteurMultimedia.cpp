#include "LecteurMultimedia.h"



LecteurMultimedia::LecteurMultimedia(Menu* menuParent) : Menu("Lecteur multimedia",menuParent)
{
	menuOptions.push_back("Jouer une chanson");
	menuOptions.push_back("Arreter de jouer la chanson");
	menuOptions.push_back("Quitter");
}


LecteurMultimedia::~LecteurMultimedia()
{
}


void LecteurMultimedia::pickMenuOption()
{
	if (currentMenu == nullptr) // Navige dans le menu courant
	{
		string chanson;
		switch(pollUserForSelection())
		{
		case 1:
			cout << endl << endl << "Nom de la chanson? : ";
			cin >> chanson;
			if (!player.openFromFile(chanson + ".ogg"))
				cout << "err loading file" << endl;
			player.play();
			break;
		case 2:
			player.stop();
			break;
		case 3:
			player.stop();
			parentMenu->deleteChildMenu();
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