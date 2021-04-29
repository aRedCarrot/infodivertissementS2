#include "Communication.h"
#include <chrono>
#include <thread>



Communication::Communication(Menu* parentMenu):Menu("Communication",parentMenu)
{
	menuOptions.push_back("Appel telephonique");
	menuOptions.push_back("Message texte");
	menuOptions.push_back("Ajouter un contact");
	menuOptions.push_back("Liste de contacts");
	menuOptions.push_back("Quitter");
}


Communication::~Communication()
{
}

void Communication::pickMenuOption()
{
	if (currentMenu == nullptr) // Navige dans le menu courant
	{
		switch (pollUserForSelection())
		{
		case 1:
			currentMenu = new Telephone(this);
			break;
		case 2:
			currentMenu = new Texto(this);
			break;
		case 3:
			ajouterContact();
			system("pause");
			break;
		case 4:
			//afficerListeContact();
			break;
		case 5:
			parentMenu->deleteChildMenu();
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
Telephone::Telephone(Menu* parentMenu):Menu("Appel telephonique",parentMenu)
{
	menuOptions.push_back("Appel a l'aide du clavier");
	menuOptions.push_back("Appel dans la liste de contacts");
	menuOptions.push_back("Quitter");
}

Telephone::~Telephone()
{
}

void Telephone::pickMenuOption()
{
	if (currentMenu == nullptr) // Navige dans le menu courant
	{
		string numeroTelephone = "";
		switch (pollUserForSelection())
		{
		case 1:
			system("cls");
			cout << "Veuillez entrez un numero de telephone : ";
			cin >> numeroTelephone;
			system("cls");
			for (int i=1,count = 1; i < 11; i++)
			{
				if (count == 1)
					cout << "Appel de " << numeroTelephone << " en cours .";
				else if(count == 2)
					cout << "Appel de " << numeroTelephone << " en cours ..";
				else if(count == 3)
					cout << "Appel de " << numeroTelephone << " en cours ...";
				std::this_thread::sleep_for(std::chrono::seconds(1));
				if (++count == 4)
					count = 1;
				system("cls");
			}
			system("cls");
			cout << "L'appel ne peut pas etre effectué , paye ton forfait le pauvre :) " << endl << endl;
			system("pause");
			break;
		case 2:
			cout << "La liste de contacts apparaitra ici\n";
			break;
		case 3:
			parentMenu->deleteChildMenu();
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

Texto::Texto(Menu* parentMenu):Menu("Message texte", parentMenu)
{
	menuOptions.push_back("Historique des textos");
	menuOptions.push_back("Envoyer un message");
	menuOptions.push_back("Quitter");
}
Texto::~Texto()
{
}

void Texto::pickMenuOption()
{
	if (currentMenu == nullptr) // Navige dans le menu courant
	{
		switch (pollUserForSelection())
		{
		case 1:
			cout << "L'historique des messages\n";
			break;
		case 2:
			cout << "Envoyer un message par ici\n";
			break;
		case 3:
			parentMenu->deleteChildMenu();
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

Contact::Contact(string prenom, string nom, string numero)
{
	this->prenom = prenom;
	this->nom = nom;
	this->numero = numero;
}

Contact::~Contact()
{

}

bool Contact:: operator<(Contact& other)
{
	return this->nom < other.nom;
}