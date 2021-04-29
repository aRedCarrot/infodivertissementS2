#pragma once
#include "Menu.h"
#include "SFML/Audio.hpp"
class LecteurMultimedia : public Menu
{
	sf::Music player;
public:
	LecteurMultimedia(Menu* parentMenu);
	~LecteurMultimedia();

	void pickMenuOption();
};

