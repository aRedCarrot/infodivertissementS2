#include "Ventilation.h"
#include <fstream>
#include <sstream>
#include <exception>
#include "nlohmann/json.hpp"


Ventilation::Ventilation(Menu* parentMenu):Menu("Ventilation",parentMenu)
{
	menuOptions.push_back("Temperature à l'interieur du véhicule");
	menuOptions.push_back("Augmenter la température");
	menuOptions.push_back("Diminuer la température");
	menuOptions.push_back("Intensité");
	menuOptions.push_back("Quitter");
	loadSettingsFromFile();
}


Ventilation::~Ventilation()
{
	//Save settings
}

void Ventilation::pickMenuOption()
{
	if (currentMenu == nullptr) // Navige dans le menu courant
	{
		switch (pollUserForSelection())
		{
		case 1:
			system("cls");
			cout << endl << "La temperature du ventilateur de gauche est : " << this->TemperatureLeft << " °" << this->TemperatureUnit << "  \n le ventilateur de droite est : " << this->TemperatureRight << " °" << this->TemperatureUnit << endl;
			system("pause");
			break;
		case 2:
			increaseTemperature();
			break;
		case 3:
			cout << "Diminution de la temperature";
			break;
		case 4:
			cout << "Roulette pour jouer avec l'intensite de l'aeration a implementer";
			break;
		case 5:
			parentMenu->deleteChildMenu();
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

void Ventilation::loadSettingsFromFile()
{
	ifstream inFile;
	inFile.open("InfodivertissementSettings.json"); //open the input file

	std::stringstream strStream;
	strStream << inFile.rdbuf(); //read the file
	std::string str = strStream.str(); //str holds the content of the file

	auto j = nlohmann::json::parse(str)["Dashboard"];

	if (j["VentilationPower"] == "ON")
		this->VentilationPower = true;
	else
		this->VentilationPower = false;
	this->VentilationIntensity = j["VentilationIntensity"];
	this->TemperatureLeft = j["TemperatureLeft"];
	this->TemperatureRight = j["TemperatureRight"];
	this->TemperatureUnit = "C";
}

void Ventilation::increaseTemperature()
{
	system("cls");
	cout << "Augmentation de la temperature" << endl << endl;
	cout << "Temperature du ventilateur de gauche( En " << this->TemperatureUnit << " ) : ";
	cin >> this->TemperatureLeft;
	cout << endl << endl << "Temperature du ventilateur de droite( En " << this->TemperatureUnit << " ) : ";
	cin >> this->TemperatureRight;
}