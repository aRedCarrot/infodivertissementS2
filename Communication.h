#pragma once
#include "Menu.h"
#include <list>

class Contact
{
public:
	string prenom;
	string nom;
	string numero;
	Contact(string prenom, string nom, string numero);
	~Contact();
	bool operator< (Contact& other);
};

class Communication :
	public Menu
{
public:
	Communication(Menu* parentMenu);
	~Communication();
	void pickMenuOption();
	list<Contact> repertoire;
	void ajouterContact();
};

class Telephone :
	public Menu
{
public:
	Telephone(Menu* parentMenu);
	~Telephone();
	void pickMenuOption();
};

class Texto :
	public Menu
{
public:
	Texto(Menu* parentMenu);
	~Texto();
	void pickMenuOption();
};

