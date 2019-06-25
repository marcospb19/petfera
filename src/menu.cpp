#include <iostream>
#include "menu.h"
#include "funcionario.h"
#include "animal.h"
using namespace std;


Menu::Menu(){
	this->continuar = true;
}
Menu::~Menu(){

}

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

// Retorna true se os valores da entrada passarem e false
// se os valores forem inválidos e imprime o range correto
bool checar_entrada_do_menu(int entrada, istream& CIN,
                            int limite_inferior, int limite_superior)
{
	if (!checar_entrada_int(CIN))
	{
		return false;
	}

	if (limite_superior < limite_inferior)
		swap(limite_inferior, limite_superior);

	if (entrada < limite_inferior || entrada > limite_superior)
	{
		cout << "Digite um valor válido ["
		     << limite_inferior << '-' << limite_superior << "]\n";
		return false;
	}
	return true;
}

bool checar_entrada_int(istream& CIN){
	if (!CIN)
	{
		cout << "Erro, digite um número inteiro.\n";
		cin.clear();
		cin.ignore(256, '\n');
		return false;
	}
	return true;
}