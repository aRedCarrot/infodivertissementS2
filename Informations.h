#pragma once
#include "Menu.h"
class Informations :
	public Menu
{
public:
	Informations(Menu* parentMenu);
	~Informations();
	void pickMenuOption();
};

