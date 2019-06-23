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
	int vt;
	int tr;
	double tamanho;

	string nome;
	string classe_animal;
	string nome_cientifico;
	string dieta;
	string nome_batismo;

	Veterinario veterinario;
	Tratador tratador;

public:
	Animal();
	~Animal();

	int get_ultimo_id();

	// Setters e Getters:

	char get_sexo();
	void set_sexo(char _sexo);

	int get_id();
	void set_id(int _id);

	int get_vt();
	void set_vt(int _vt);

	int get_tr();
	void set_tr(int _tr);

	double get_tamanho();
	void set_tamanho(double _tamanho);

	string get_nome();
	void set_nome(string _nome);

	string get_classe_animal();
	void set_classe_animal(string _classe_animal);

	string get_nome_cientifico();
	void set_nome_cientifico(string _nome_cientifico);

	string get_dieta();
	void set_dieta(string _dieta);

	string get_nome_batismo();
	void set_nome_batismo(string _nome_batismo);

	Veterinario get_veterinario();
	void set_veterinario(Veterinario _veterinario);

	Tratador get_tratador();
	void set_tratador(Tratador _tratador);

	friend ostream& operator<< (ostream &o, Animal a);
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

void inserir_animal();

void listar_animais();

#endif
