#ifndef TRATADOR_H
#define TRATADOR_H

#include "funcionario.h"
using namespace std;


class Tratador : public Funcionario
{
	int nivel_de_seguranca;

public:
	Tratador();
	~Tratador();

	friend ostream& operator<< (ostream &o, Tratador t);

	// Setters e Getters:

	int get_nivel_de_seguranca();
	void set_nivel_de_seguranca(int _nivel_de_seguranca);
};

void inserir_tratador();

Tratador get_tratador_tabela(int _id);

#endif
