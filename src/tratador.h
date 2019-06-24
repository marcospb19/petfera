#ifndef TRATADOR_H
#define TRATADOR_H

#include "funcionario.h"
using namespace std;


class Tratador : public Funcionario /**<Tratador, uma classe derivada de Funcionario*/
{
	int nivel_de_seguranca; /**<Nivel de segurança dado em inteiro*/

public:
	Tratador(); /**<Construtor da classe*/
	~Tratador(); /**<Destrutor da classe*/

	friend ostream& operator<< (ostream &o, Tratador t);

	// Setters e Getters:

	int get_nivel_de_seguranca(); /**<função para pegar o nível de seguranca do tratador*/
	void set_nivel_de_seguranca(int _nivel_de_seguranca); /**<função para adicionar o nível de seguranca do tratador*/
};

void inserir_tratador(); /**<função que insere tratador ao programa*/

Tratador get_tratador_tabela(int _id);

#endif
