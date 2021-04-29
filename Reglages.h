#pragma once
#include "Menu.h"
class Reglages :
	public Menu
{
public:
	Reglages(Menu* parentMenu);
	~Reglages();
	void pickMenuOption();
};

