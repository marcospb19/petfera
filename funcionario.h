#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
using namespace std;


class Funcionario
{
	char fator_rh;
	short tipo_sanguineo;
	short idade;
	int id;

	string nome;
	string cpf;
	string especialidade;

public:
	Funcionario();
	~Funcionario();
};


#endif
