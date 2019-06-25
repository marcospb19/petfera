#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


void filtrar_campo(vector<string>& lista_de_animais, char* arg, int coluna)
{
	string argumento = arg;
	cout << "Filtrando a " << coluna << "ª coluna pela string \"" << argumento << "\".\n";

	// Lista para qual vou copiar lista_de_animais, já filtrando
	vector<string> nova_lista;

	// Para ler de lista_de_animais como uma stream
	stringstream stream;
	// String utilizada para a leitura
	string read;


	size_t tamanho = lista_de_animais.size();

	if (tamanho == 0) // Importante para evitar um core dumped xD
	{
		cout << "Filtrando uma tabela vazia.\n";
		return;
	}

	for (size_t i = 0; i < tamanho - 1; i++)
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
		if ((read == argumento)) // "! !=" é diferente de "=="
			nova_lista.push_back(lista_de_animais[i]);

		// Limpando a stream para reuso em linhas consecutivas
		stream.clear();
	}
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
	cout << "ccb " << argc << "\n\n";

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


int escrever_arquivo(vector<string> lista_de_animais, string caminho_final)
{
	bool append = false;
	char op;

	ofstream f;
	f.open(caminho_final, ios::in);

	if (f.is_open())
	{
		cout << "O arquivo de saída \"" << caminho_final << "\" já existe."
		     << "Você gostaria de adicionar conteudo ao seu final? (ou apagar) (s/n): ";

		cin >> op;
		op = tolower(op);
		if (op == 's' || op == 'y')
			append = true;

		f.close();
	}


	if (append)
		f.open(caminho_final, ios::app);
	else
		f.open(caminho_final, ios::out);

	if (!f.is_open())
	{
		cerr << "Erro ao tentar abrir o arquivo \"" << caminho_final << "\".";
		return 1;
	}

	for (size_t i = 0; i < lista_de_animais.size(); i++)
	{
		f << lista_de_animais[i];
		f << '\n';
	}

	f.close();

	cout << "Arquivo \"" << caminho_final << "\" salvo com sucesso.\n";

	return 0;
}
