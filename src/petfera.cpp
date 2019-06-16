#include <iostream>
#include "menu.h"
using namespace std;


int main(int argc, char* argv[])
{
	cout << "PetFera\n";

	Menu menu;
	while (menu.continuar)
		menu.rodar_menu();

	return 0;
}
