#include <iostream>
#include "menu.h"
#include "funcionario.h"


void menu(){
	short op = -1;
	while (op != 0){
		cout << "\nEscolha a opção desejada:" << endl;
		cout << "1 - Inserir funcionário" << endl;
		cout << "0 - Sair" << endl;
		cin >> op;
		switch(op){
			case 0:
				cout << "\nAté logo!" << endl;
				break;
			case 1:
				inserir_funcionario();
				break;
			case 2:
				listar_funcionarios();
				break;
			default:
				cout << "\nEscolha uma opção válida" << endl;
				break;
		}
	}
}
