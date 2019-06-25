#include <iostream>
#include <string>
using namespace std;


int checar_argumentos(int argc, char *argv[])
{
	if (argc == 1)
	{
		cerr << "Nenhum argumento foi passado.\n";
		return 1;
	}

	// Flags
	bool c = false;
	bool v = false;
	bool t = false;
	int c_pos = -1;
	int v_pos = -1;
	int t_pos = -1;

	string aux;

	for (int i = 1; i < argc; ++i)
	{
		aux = argv[i];

		if (aux == "-c")
		{
			if (!c)
			{
				c = true;
				c_pos = i;
			}
			else
			{
				cerr << "Flag \"-c\" passada mais de uma vez.\n";
				return 2;
			}
		}
		else if (aux == "-v")
		{
			if (!v)
			{
				v = true;
				v_pos = i;
			}
			else
			{
				cerr << "Flag \"-v\" passada mais de uma vez.\n";
				return 2;
			}
		}
		else if (aux == "-t")
		{
			if (!t)
			{
				t = true;
				t_pos = i;
			}
			else
			{
				cerr << "Flag \"-t\" passada mais de uma vez.\n";
				return 2;
			}
		}
	}


	// Verifica o número de argumentos
	int numero_de_argumentos = 2;  // O executável chamado e o <Nome-Do-Arquivo>
	if (c)
		numero_de_argumentos += 2; // -c <Arg>
	if (v)
		numero_de_argumentos += 2; // -v <Arg>
	if (t)
		numero_de_argumentos += 2; // -t <Arg>

	if (argc != numero_de_argumentos)
	{
		cerr << "Número de argumentos passado é insuficiente para as flags dadas [";

		if (v)
			cerr << "-v";

		if (c)
		{
			if (v)
				cerr << " ";
			cerr << "-c";
		}
		if (t)
		{
			if (v || c)
				cerr << " ";
			cerr << "-t";
		}

		cerr << "]\n"
		     << "Esperado: " << numero_de_argumentos - 1 << endl
		     << "Recebido: " << argc - 1                 << endl;
	    return 3;
	}


	// Verifica se alguma das flags está perto demais uma da outra
	if (c && v)
		if (abs(c_pos - v_pos) < 2)
		{
			cerr << "As flags passadas não receberam seus argumentos\n.";
			return 4;
		}
	if (c && t)
		if (abs(c_pos - t_pos) < 2)
		{
			cerr << "As flags passadas não receberam seus argumentos\n.";
			return 4;
		}
	if (v && t)
		if (abs(v_pos - t_pos) < 2)
		{
			cerr << "As flags passadas não receberam seus argumentos\n.";
			return 4;
		}

	return 0;
}
