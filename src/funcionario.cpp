#include <iostream>
#include "funcionario.h"
#include "veterinario.h"
#include "tratador.h"
using namespace std;


Funcionario::Funcionario(){

}

Funcionario::~Funcionario(){

}

void listar_funcionarios(){
	cout << "TODO\n";
}


void inserir_funcionario(){
	string funcao;
	while (true){
		cout << "\nInsira a função do funcionário: " << endl;
		cin >> funcao;
		if (funcao == "Veterinário"){
			inserir_veterinario();
			break;
		}
		else if (funcao == "Tratador"){
			inserir_tratador();
			break;
		}
		else{
			cout << "\nInsira um valor válido: Veterinário ou Tratador" << endl;
		}
	}
}

// Setters e Getters:

// Fator_RH
char Funcionario::get_fator_rh(){
	return(fator_rh);
}
void Funcionario::set_fator_rh(char _fator_rh){
	fator_rh = _fator_rh;
}

// Tipo sanguíneo
short Funcionario::get_tipo_sanguineo(){
	return(tipo_sanguineo);
}
void Funcionario::set_tipo_sanguineo(short _tipo_sanguineo){
	tipo_sanguineo = _tipo_sanguineo;
}

// Idade
short Funcionario::get_idade(){
	return(idade);
}
void Funcionario::set_idade(short _idade){
	idade = _idade;
}

// Id
int Funcionario::get_id(){
	return(id);
}
void Funcionario::set_id(int _id){
	id = _id;
}

// Nome
string Funcionario::get_nome(){
	return(nome);
}
void Funcionario::set_nome(string _nome){
	nome = _nome;
}

// Cpf
string Funcionario::get_cpf(){
	return(cpf);
}
void Funcionario::set_cpf(string _cpf){
	cpf = _cpf;
}

// Especialidade
string Funcionario::get_especialidade(){
	return(especialidade);
}
void Funcionario::set_especialidade(string _especialidade){
	especialidade = _especialidade;
}
