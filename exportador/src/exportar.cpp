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
		return 3;

	// if (escrever_arquivo(lista_de_animais))
	// {
	// 	/* code */
	// }

	for (size_t i = 0; i < lista_de_animais.size(); ++i)
		cout << lista_de_animais.at(i) << endl;

	return 0;
}
