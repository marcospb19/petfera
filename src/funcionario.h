#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
using namespace std;


class Funcionario
{
protected:
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

	char get_fator_rh();
	void set_fator_rh(char _fator_rh);

	short get_tipo_sanguineo();
	void set_tipo_sanguineo(short _tipo_sanguineo);

	short get_idade();
	void set_idade(short _idade);

	int get_id();
	void set_id(int _id);

	string get_nome();
	void set_nome(string _nome);

	string get_cpf();
	void set_cpf(string _cpf);

	string get_especialidade();
	void set_especialidade(string _especialidade);
};

void inserir_funcionario();

void listar_funcionarios();


#endif
