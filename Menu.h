#pragma once
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Menu
{
protected:
	string menuName;
	vector<string> menuOptions;
	Menu* currentMenu;
	Menu* parentMenu;
public:
	virtual void showMenu();
	virtual void pickMenuOption() = 0;
	virtual void changeCurrentMenu(Menu* newMenu);
	int pollUserForSelection();
	void deleteChildMenu();
	Menu(string menuName, Menu* parentMenu);
	~Menu();
};

