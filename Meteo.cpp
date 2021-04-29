#include "Meteo.h"
#include <fstream>
#include <sstream>
#include <exception>

Meteo::Meteo(Menu * parentMenu) : Menu("Meteo", parentMenu)
{
	menuOptions.push_back("Voir la meteo pour ma localisation");
	menuOptions.push_back("Changer ma localisation");
	menuOptions.push_back("Voir la meteo pour une autre ville");
	menuOptions.push_back("Quitter");
	//loadLocationSettingsFromFile();
}

Meteo::~Meteo()
{

}

void Meteo::pickMenuOption()
{
	if (currentMenu == nullptr) // Navige dans le menu courant
	{
		switch (pollUserForSelection())
		{
		case 1:
			loadLocationSettingsFromFile();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			parentMenu->deleteChildMenu();
			break;
		case 5:
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

void Meteo::loadLocationSettingsFromFile()
{
	ifstream inFile;
	inFile.open("InfodivertissementSettings.json"); //open the input file

	std::stringstream strStream;
	strStream << inFile.rdbuf(); //read the file
	std::string str = strStream.str(); //str holds the content of the file

	auto j = nlohmann::json::parse(str);

	cout << j["Weather"]["Location"] << endl;
}
