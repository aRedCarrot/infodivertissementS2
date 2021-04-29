#pragma once
#include "Menu.h"
class Ventilation :
	public Menu
{
	bool VentilationPower;
	int VentilationIntensity;
	string TemperatureUnit;
	int TemperatureLeft;
	int TemperatureRight;
public:
	Ventilation(Menu* parentMenu);
	~Ventilation();
	void pickMenuOption();
	void loadSettingsFromFile();
	void increaseTemperature();
};

