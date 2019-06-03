#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include "tratador.h"
#include "veterinario.h"
using namespace std;


class Animal
{
	char sexo;
	int id;
	double tamanho;

	string classe;
	string nome_cientifico;
	string dieta;
	string nome_batismo;

	Veterinario veterinario;
	Tratador tratador;

public:
	Animal();
	~Animal();
};


class AnimalNativo
{
	string uf_origem;
	string autorizacao;

public:
	AnimalNativo();
	~AnimalNativo();
};


class AnimalExotico
{
	string pais_origem;

public:
	AnimalExotico();
	~AnimalExotico();
};


class AnimalSilvestre
{
	string autorizacao_ibama;

public:
	AnimalSilvestre();
	~AnimalSilvestre();
};


#endif
