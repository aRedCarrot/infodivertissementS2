#pragma once
#include "Menu.h"
class GPS : public Menu
{
public:
	GPS(Menu* parentMenu);
	~GPS();
	void pickMenuOption();
	void getMyLocation();
};