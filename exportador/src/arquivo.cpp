#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


// Não utilizado, mas aí para possível mudança no programa principal
// const string classes[] = {
// 	"AnfNat",
// 	"AnfExo",
// 	"AveNat",
// 	"AveExo",
// 	"MamNat",
// 	"MamExo",
// 	"RepNat",
// 	"RepExo"
// };


void filtrar_campo(vector<string>& lista_de_animais, char* arg, int coluna)
{
	string argumento = arg;

	// Lista para qual vou copiar lista_de_animais, já filtrando
	vector<string> nova_lista;

	// Para ler de lista_de_animais como uma stream
	stringstream stream;

	// String utilizada para a leitura
	string read;

	for (size_t i = 0; i < lista_de_animais.size(); i++)
	{
		// Setando a stream
		stream.str(lista_de_animais[i]);

		// Pular colunas desnecessárias
		for (int _ = 0; _ < coluna - 1; _++)
		{
			stream.ignore(1024, '|');
		}

		// Lê conteúdo da coluna
		getline(stream, read, '|');

		// Se a linha passar no filtro, adicionar
		if (!(read != argumento)) // "! !=" é diferente de "=="
			nova_lista.push_back(lista_de_animais[i]);

		// Limpando a stream para reuso em linhas consecutivas
		stream.clear();
	}

	lista_de_animais = nova_lista;
}


int filtrar_linhas(int argc, char *argv[], vector<string>& lista_de_animais)
{
	string argumento;

	for (int i = 1; i < argc - 1; ++i)
	{
		argumento = argv[i];
		if (argumento == "-c")
			filtrar_campo(lista_de_animais, argv[i + 1], 2);

		else if (argumento == "-v")
			filtrar_campo(lista_de_animais, argv[i + 1], 8);

		else if (argumento == "-t")
			filtrar_campo(lista_de_animais, argv[i + 1], 9);
	}

	return 0;
}


int ler_arquivo(const char* const caminho_do_arquivo , vector<string>& lista_de_animais)
{
	ifstream f;
	f.open(caminho_do_arquivo, ios::in);
	if (!f.is_open())
	{
		cerr << "Erro na abertura do arquivo.\n"
		     << "Verifique se \'animaix.txt\' existe.\n";
		return 1;
	}

	// String para receber cada linha
	string read;

	while (getline(f, read))
		lista_de_animais.push_back(read);

	f.close();
	return 0;
}
