#include <iostream>
#include <fstream>
#include <cstdlib>
#include "funcionario.h"
#include "veterinario.h"
#include "tratador.h"
using namespace std;


Funcionario::Funcionario(){

}
Funcionario::~Funcionario(){

}

int checar_id_funcionario(int _id, string _funcao){
	int id = 0;

	string conteudo, aux, funcao;

	ifstream f;
	f.open("funcionarios.txt", ios::in);
	if (!f.is_open())
	{
		cerr << "\nErro na abertura do arquivo\n";
		return -1;
	}

	getline(f, conteudo);

	while(!f.eof()){
		funcao = "";
		f >> id;
		f >> conteudo;
		f >> funcao;
		f >> conteudo;
		if(id == _id && funcao == _funcao){
			return 1;
		}
		getline(f, conteudo);
	}
	f.close();
	return -1;
}

int Funcionario::get_ultimo_id(){
	int id = 0;

	string conteudo;
	ifstream f;
	f.open("funcionarios.txt", ios::in);

	if (!f.is_open())
	{
		cerr << "\nErro na abertura do arquivo\n";
		return -1;
	}

	getline(f, conteudo);
	while(!f.eof()){
		f >> id;
		getline(f, conteudo);
	}

	f.close();
	return id;
}

void listar_funcionarios(){
	cout << "\n";
	int id;

	string conteudo, aux, funcao;

	Veterinario vt;
	Tratador tr;
	ifstream f;

	f.open("funcionarios.txt", ios::in);
	if (!f.is_open())
	{
		cerr << "\nErro na abertura do arquivo\n";
		return;
	}
	// Pulando uma linha
	getline(f,conteudo);
	while(!f.eof()){
		/*

		// Mostrando só o nome
		for(int i = 0; i < 4; i++){
			f >> conteudo;
		}
		conteudo = "";
		f >> aux;

		while(aux != "|"){
			conteudo += aux + " ";
			f >> aux;
		}
		cout << conteudo << endl;

		// Pulando o resto da linha
		getline(f,conteudo);

		*/

		// Pegando id e função
		funcao = "";
		f >> id;
		f >> conteudo;
		f >> funcao;
		f >> conteudo;
		if(funcao == "V"){
			vt.set_id(id);
			conteudo = "";
			f >> aux;
			// Pegando nome
			while(aux != "|"){
				conteudo += aux + " ";
				f >> aux;
			}
			vt.set_nome(conteudo);
			f >> conteudo;
			vt.set_cpf(conteudo);
			f >> conteudo; f >> conteudo;
			vt.set_idade(atoi(conteudo.c_str()));
			f >> conteudo; f >> conteudo;
			vt.set_tipo_sanguineo(conteudo);
			f >> conteudo; f >> conteudo;
			vt.set_fator_rh(conteudo[0]);
			f >> conteudo; f >> conteudo;
			vt.set_especialidade(conteudo);
			f >> conteudo; f >> conteudo;
			vt.set_crmv(conteudo);
			cout << vt << endl;
		}
		else if(funcao == "T"){
			tr.set_id(id);
			conteudo = "";
			f >> aux;
			// Pegando nome
			while(aux != "|"){
				conteudo += aux + " ";
				f >> aux;
			}
			tr.set_nome(conteudo);
			f >> conteudo;
			tr.set_cpf(conteudo);
			f >> conteudo; f >> conteudo;
			tr.set_idade(atoi(conteudo.c_str()));
			f >> conteudo; f >> conteudo;
			tr.set_tipo_sanguineo(conteudo);
			f >> conteudo; f >> conteudo;
			tr.set_fator_rh(conteudo[0]);
			f >> conteudo; f >> conteudo;
			tr.set_especialidade(conteudo);
			f >> conteudo; f >> conteudo;
			tr.set_nivel_de_seguranca(atoi(conteudo.c_str()));
			cout << tr << endl;
		}
		getline(f,conteudo);
	}
	f.close();
}


void inserir_funcionario(){
	short op;
	while (true){
		cout << "\nInsira a função do funcionário:\n"
		     << "1 - Veterinário\n"
		     << "2 - Tratador\n"
		     << "0 - Sair\n";

		cin >> op;

		if (op == 1){
			inserir_veterinario();
			break;
		}
		else if (op == 2){
			inserir_tratador();
			break;
		}
		else{
			cerr << "\nDigite um valor válido [0-2]\n";
		}
	}
}

// Setters e Getters:

// Fator_RH
// Tipo sanguíneo
// Idade
// Id
// Nome
// Cpf
// Especialidade

char Funcionario::get_fator_rh(){
	return fator_rh;
}
void Funcionario::set_fator_rh(char _fator_rh){
	fator_rh = _fator_rh;
}

string Funcionario::get_tipo_sanguineo(){
	return tipo_sanguineo;
}
void Funcionario::set_tipo_sanguineo(string _tipo_sanguineo){
	tipo_sanguineo = _tipo_sanguineo;
}

short Funcionario::get_idade(){
	return idade;
}
void Funcionario::set_idade(short _idade){
	idade = _idade;
}

int Funcionario::get_id(){
	return id;
}
void Funcionario::set_id(int _id){
	id = _id;
}

string Funcionario::get_nome(){
	return nome;
}
void Funcionario::set_nome(string _nome){
	nome = _nome;
}

string Funcionario::get_cpf(){
	return cpf;
}
void Funcionario::set_cpf(string _cpf){
	cpf = _cpf;
}

string Funcionario::get_especialidade(){
	return especialidade;
}
void Funcionario::set_especialidade(string _especialidade){
	especialidade = _especialidade;
}
