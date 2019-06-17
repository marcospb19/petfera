#include <iostream>
#include "menu.h"
#include "funcionario.h"
#include "animal.h"

Menu::Menu(){

}
Menu::~Menu(){

}

bool Menu::continuar = true;

void Menu::rodar_menu(){
	short op = -1;
	while (op != 0){
		cout << "\nEscolha a opção desejada:\n"
		     << "1 - Inserir funcionário\n"
		     << "2 - Listar funcionários\n"
		     << "3 - Inserir animal\n"
		     << "4 - Listar animais\n"
		     << "0 - Sair\n";

		cin >> op;
		switch (op){
			case 0:
				this->continuar = false;
				break;
			case 1:
				inserir_funcionario();
				break;
			case 2:
				listar_funcionarios();
				break;
			case 3:
				inserir_animal();
				break;
			case 4:
				listar_animais();
				break;
			default:
				cout << "Escolha uma opção válida\n";
				break;
		}
	}
}
