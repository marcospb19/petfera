#include <iostream>
#include <fstream>
#include <cstdlib>
#include "veterinario.h"
using namespace std;


Veterinario::Veterinario(){

}
Veterinario::~Veterinario(){

}

Veterinario get_veterinario_tabela(int _id){
	int id = 0;
	string conteudo, aux;
	ifstream f;
	Veterinario vt;
	f.open("funcionarios.txt", ios::in);
	if (!f.is_open())
	{
		cerr << "\nErro na abertura do arquivo\n";
		return vt;
	}
	getline(f, conteudo);
	while(!f.eof()){
		f >> id;
		if(id == _id){
			vt.set_id(id);
			f >> conteudo; f >> conteudo; f >> conteudo;
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

			f.close();
			return vt;
		}
		getline(f, conteudo);
	}
	f.close();
	return vt;
}

void inserir_veterinario(){
	Veterinario vt;
	string r1;
	int r2;
	char r3;

	vt.set_id(vt.get_ultimo_id()+1);
	cout << "Insira o nome do veterinário\n";
	cin >> r1;
	vt.set_nome(r1);
	cout << "Insira o CPF\n";
	cin >> r1;
	vt.set_cpf(r1);
	while(true){
		cout << "Insira a idade\n";
		cin >> r2;
		if (!cin){
			cout << "Digite um inteiro\n";
			cin.clear();
			cin.ignore(256, '\n');
		}
		else{
			break;
		}
	}
	vt.set_idade(r2);
	cin.clear();
	cin.ignore(256, '\n');
	while(true){
		cout << "Insira o tipo sanguineo\n1 - A; 2 - B; 3 - AB; 4 - O\n";
		cin >> r2;
		if (!cin){
			cout << "Digite um inteiro\n";
			cin.clear();
			cin.ignore(256, '\n');
		}
		else if(r2 < 1 || r2 > 4){
			cout << "Digite um valor válido [1-4]\n";
		}
		else{
			switch(r2){
				case 01:
					r1 = "A";
					break;
				case 02:
					r1 = "B";
					break;
				case 03:
					r1 = "AB";
					break;
				case 04:
					r1 = "O";
					break;
			}
			break;
		}
	}
	vt.set_tipo_sanguineo(r1);
	while(true){
		cout << "Insira o fator RH\n+ ou -\n";
		cin >> r3;
		if(r3 != '+' && r3 != '-'){
			cout << "Digite um valor válido\n";
		}
		else{
			break;
		}
	}
	vt.set_fator_rh(r3);
	cout << "Insira a especialidade\n";
	cin >> r1;
	vt.set_especialidade(r1);
	cout << "Insira o código CRMV\n";
	cin >> r1;
	vt.set_crmv(r1);

	ofstream f;
	f.open("funcionarios.txt", ios::out | ios::app);
	if (!f.is_open())
	{
		cerr << "\nErro na abertura do arquivo\n";
		return;
	}

	f << vt.get_id()             << " | "
	  << "V"                     << " | "
	  << vt.get_nome()           << " | "
	  << vt.get_cpf()            << " | "
	  << vt.get_idade()          << " | "
	  << vt.get_tipo_sanguineo() << " | "
	  << vt.get_fator_rh()       << " | "
	  << vt.get_especialidade()  << " | "
	  << vt.get_crmv()           << " | "
	  << '\n';

	f.close();
}

// Setters e Getters:

// CRMV
string Veterinario::get_crmv(){
	return crmv;
}
void Veterinario::set_crmv(string _crmv){
	crmv = _crmv;
}

// Overload do <<
ostream& operator<< (ostream &o, Veterinario v) {
o << "Id: " << v.get_id() << " Nome: " << v.get_nome() << " Função: Veterinário "
  << " CPF: " << v.get_cpf() << " Idade: " << v.get_idade()
  << " Tipo sanguineo: " << v.get_tipo_sanguineo()
  << " Fator RH: " << v.get_fator_rh() << " Especialidade: " << v.get_especialidade()
  << " Codigo CRMV: " << v.get_crmv();
return o;
}
