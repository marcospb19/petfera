#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include "tratador.h"
#include "veterinario.h"
using namespace std;


class Animal /**<Classe mestra de onde outras classes animais vão se ramificar*/
{
protected:
	char sexo;
	int id; /**<id do animal*/
	int vt; /**<id do veterinario do animal*/
	int tr; /**<id do tratador do animal*/
	double tamanho;

	string nome;
	string classe;
	string nome_cientifico;
	string dieta;
	string nome_batismo;

	Veterinario veterinario;
	Tratador tratador;

public:
	Animal(); /**<Construtor de animal*/
	~Animal(); /**<Destrutor de animal*/

	int get_ultimo_id(); /**<função para pegar o ultimo id acessado*/

	char get_sexo(); /**<função para pegar o sexo*/
	void set_sexo(char _sexo); /**<função para adicionar o sexo do animal*/

	int get_id(); /**<função para pegar o ultimo id acessado*/
	void set_id(int _id); /**<função para adicionar o id do animal*/

	int get_vt();
	void set_vt(int _vt); /**<função para adicionar o id do veterinario do anmal*/

	int get_tr();
	void set_tr(int _tr); /**<função para adicionar o id do tratador do animal*/

	double get_tamanho();
	void set_tamanho(double _tamanho); /**<função para adicionar o tamanho do animal*/

	string get_nome();
	void set_nome(string _nome); /**<função para adicionar o nome do animal*/

	string get_classe();
	void set_classe(string _classe); /**<função para adicionar a classe do animal (anfibio.mamifero,...)*/

	string get_nome_cientifico();
	void set_nome_cientifico(string _nome_cientifico); /**<função para adicionar o nome cientidico do animal*/

	string get_dieta();
	void set_dieta(string _dieta); /**<função para adicionar a dieta do animal*/

	string get_nome_batismo();
	void set_nome_batismo(string _nome_batismo); /**<função para adicionar o nome de batismo do animal (apelido)*/

	Veterinario get_veterinario();
	void set_veterinario(Veterinario _veterinario); /**<função para adicionar o veterinario*/

	Tratador get_tratador();
	void set_tratador(Tratador _tratador); /**<função para adicionar o tratador*/

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
	string uf_origem; /**<local de origem do animal*/
	string autorizacao;

public:
	AnimalNativo(); /**<Construtor*/
	~AnimalNativo(); /**<Destrutor*/
};


class AnimalExotico : protected AnimalSilvestre
{
protected:
	string pais_origem;

public:
	AnimalExotico(); /**<Construtor*/
	~AnimalExotico(); /**<Destrutor*/
};

void inserir_animal(); /**<função que insere animal ao programa*/

void listar_animais(); /**<função que lista os animais cadastrados*/

#endif
