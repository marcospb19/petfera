#ifndef TRATADOR_H
#define TRATADOR_H

#include <string>
#include "funcionario.h"
using namespace std;


class Tratador : public Funcionario
{
	int nivel_de_seguranca;

public:
	Tratador();
	~Tratador();

	int get_nivel_de_seguranca();
	void set_nivel_de_seguranca(int _nivel_de_seguranca);
};

void inserir_tratador();


#endif
