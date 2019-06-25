#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
using namespace std;


class Funcionario
{
protected:
	char fator_rh;
	string tipo_sanguineo;
	short idade;
	int id;

	string nome;
	string cpf;
	string especialidade;

public:
	Funcionario(); /**<Construtor da classe*/
	~Funcionario(); /**<Destrutor da classe*/

	int get_ultimo_id(); /**<função para pegar o ultimo id acessado*/

	// Setters e Getters:

	char get_fator_rh(); /**<função para pegar o fator RH do Funcionário*/
	void set_fator_rh(char _fator_rh); /**<função para adicionar o fator RH do Funcionário*/

	string get_tipo_sanguineo(); /**<função para pegar o tipo sanguineo do Funcionário*/
	void set_tipo_sanguineo(string _tipo_sanguineo); /**<função para adicionar o tipo sanguineo do Funcionário*/

	short get_idade(); /**<função para pegar a idade do Funcionário*/
	void set_idade(short _idade);/**<função para adicionar a idade RH do Funcionário*/

	int get_id(); /**<função para pegar o ultimo id acessado*/
	void set_id(int _id); /**<função para adicionar o id do Funcionário*/

	string get_nome(); /**<função para pegar o nome do Funcionário*/
	void set_nome(string _nome);/**<função para adicionar o nome do Funcionário*/

	string get_cpf(); /**<função para pegar o CPF do Funcionário*/
	void set_cpf(string _cpf);/**<função para adicionar o CPF do Funcionário*/

	string get_especialidade(); /**<função para pegar a especialidade do Funcionário*/
	void set_especialidade(string _especialidade);/**<função para adicionar a especialidade do Funcionário*/
};

void inserir_funcionario(); /**<função que insere funcionario ao programa*/

void listar_funcionarios(); /**<função que lista os funcionarios cadastrados*/

int checar_id_e_funcao_funcionario(int _id, string _funcao);  /**<função que checar o id do funcionario*/

#endif
