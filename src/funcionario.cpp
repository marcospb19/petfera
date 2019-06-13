#include "funcionario.h"

//Construtor e Destrutor
Funcionario::Funcionario(){

}

Funcionario::~Funcionario(){
	
}

//Fator_RH
char Funcionario::get_fator_rh(){
	return(fator_rh);
}

void Funcionario::set_fator_rh(char _fator_rh){
	fator_rh = _fator_rh;
}

//Tipo sanguíneo
short Funcionario::get_tipo_sanguineo(){
	return(tipo_sanguineo);
}

void Funcionario::set_tipo_sanguineo(short _tipo_sanguineo){
	tipo_sanguineo = _tipo_sanguineo;
}

//Idade
short Funcionario::get_idade(){
	return(idade);
}

void Funcionario::set_idade(short _idade){
	idade = _idade;
}

//Id
int Funcionario::get_id(){
	return(id);
}

void Funcionario::set_id(int _id){
	id = _id;
}

//Nome
string Funcionario::get_nome(){
	return(nome);
}

void Funcionario::set_nome(string _nome){
	nome = _nome;
}

//Cpf
string Funcionario::get_cpf(){
	return(cpf);
}

void Funcionario::set_cpf(string _cpf){
	cpf = _cpf;
}

//Especialidade
string Funcionario::get_especialidade(){
	return(especialidade);
}

void Funcionario::set_especialidade(string _especialidade){
	especialidade = _especialidade;
}