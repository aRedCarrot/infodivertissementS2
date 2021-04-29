#include "MainMenu.h"
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "french");
	MainMenu menuPrincipale(nullptr);
	while (true)
	{
		menuPrincipale.showMenu();
		menuPrincipale.pickMenuOption();
	}
}