#include <iostream>
#include "menu.h"
#include "funcionario.h"

Menu::Menu(){

}
Menu::~Menu(){

}

void Menu::rodar_menu(){
	short op = -1;
	while (op != 0){
		cout << "\nEscolha a opção desejada:\n"
		     << "1 - Inserir funcionário\n"
		     << "2 - Listar funcionários\n"
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
			default:
				cout << "Escolha uma opção válida\n";
				break;
		}
	}
}
