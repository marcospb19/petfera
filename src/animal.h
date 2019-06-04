#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include "tratador.h"
#include "veterinario.h"
using namespace std;


class Animal
{
protected:
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


class AnimalSilvestre
{
protected:
	string autorizacao_ibama;

public:
	AnimalSilvestre();
	~AnimalSilvestre();
};


class AnimalNativo : protected AnimalSilvestre
{
protected:
	string uf_origem;
	string autorizacao;

public:
	AnimalNativo();
	~AnimalNativo();
};


class AnimalExotico : protected AnimalSilvestre
{
protected:
	string pais_origem;

public:
	AnimalExotico();
	~AnimalExotico();
};


#endif
