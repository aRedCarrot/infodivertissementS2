#pragma once
#include "Menu.h"
#include "GPS.h"
#include "LecteurMultimedia.h"
#include "Communication.h"
#include "Meteo.h"
#include "Ventilation.h"
#include "Reglages.h"
#include "Informations.h"
class MainMenu : public Menu
{
	//Menu* currentMenu;
public:
	MainMenu(Menu* parentMenu);
	~MainMenu();

	void pickMenuOption();

};