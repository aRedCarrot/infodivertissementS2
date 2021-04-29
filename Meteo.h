#pragma once
#include "Menu.h"
#include "nlohmann/json.hpp"

struct Location
{
	string Country;
	string Province;
	string City;
	string PostalCode;
};

class Meteo : public Menu
{
	Location location;
	void loadLocationSettingsFromFile();
public:
	Meteo(Menu* parentMenu);
	~Meteo();
	void pickMenuOption();
};