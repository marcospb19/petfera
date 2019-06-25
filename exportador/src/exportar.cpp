#include <iostream>
#include <vector>
#include <string>
#include "parse.h"
#include "arquivo.h"
#include "messages.h"

using namespace std;

const char* const caminho_do_arquivo = "animais.txt";


int main(int argc, char *argv[])
{
	vector<string> lista_de_animais;

	if (checar_argumentos(argc, argv))
	{
		mostrar_ajuda();
		return 1;
	}

	if (ler_arquivo(caminho_do_arquivo, lista_de_animais))
		return 2;

	if (filtrar_linhas(argc, argv, lista_de_animais))
	{
		mostrar_ajuda();
		return 3;
	}
	cout << "a " << argc << "\n\n";
	string caminho_final = parse_caminho_final(argv, argc);
	cout << "b " << argc << "\n\n";

	if (escrever_arquivo(lista_de_animais, caminho_final))
		return 4;

	return 0;
}
