#include "Menu.h"

#include <iostream>
using namespace std;


void Menu::showMenu()
{
	system("cls");
	cout << " ==== " << menuName << " ==== " << endl << endl;
	for (int i = 0; i < menuOptions.size(); i++)
	{
		cout << i + 1 << " : " << menuOptions[i] << endl;
	}

	cout << endl << "Votre selection : ";
}

void Menu::changeCurrentMenu(Menu * newMenu)
{
	this->currentMenu = newMenu;
}

int Menu::pollUserForSelection()
{
	int selection = -1;
	cin >> selection;
	return selection;
}

void Menu::deleteChildMenu()
{
	delete currentMenu;
	currentMenu = nullptr;
	showMenu();
	pickMenuOption();
}

Menu::Menu(string menuName,Menu* parentMenu)
{
	this->menuName = menuName;
	this->currentMenu = nullptr;
	this->parentMenu = parentMenu;
}


Menu::~Menu()
{
	delete currentMenu;
	//delete parentMenu;
}
