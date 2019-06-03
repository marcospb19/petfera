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
};


#endif
