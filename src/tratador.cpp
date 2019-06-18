#include <iostream>
#include <fstream>
#include <cstdlib>
#include "tratador.h"
using namespace std;


Tratador::Tratador(){

}
Tratador::~Tratador(){

}

Tratador get_tratador_tabela(int _id){
	int id = 0;
	string conteudo, aux;
	ifstream f;
	Tratador tr;
	f.open("funcionarios.txt", ios::in);
	if (!f.is_open())
	{
		cerr << "\nErro na abertura do arquivo\n";
		return tr;
	}
	getline(f, conteudo);
	while(!f.eof()){
		f >> id;
		if(id == _id){
			tr.set_id(id);
			f >> conteudo; f >> conteudo; f >> conteudo;
			conteudo = "";
			f >> aux;
			//Pegando nome
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
			tr.set_tipo_sanguineo(atoi(conteudo.c_str()));
			f >> conteudo; f >> conteudo;
			tr.set_fator_rh(conteudo[0]);
			f >> conteudo; f >> conteudo;
			tr.set_especialidade(conteudo);
			f >> conteudo; f >> conteudo;
			tr.set_nivel_de_seguranca(atoi(conteudo.c_str()));
			f.close();
			return tr;
		}
		getline(f, conteudo);
	}
	f.close();
	return tr;
}

void inserir_tratador(){
	Tratador tr;
	string r1;
	int r2;
	char r3;

	cout << "Ultimo id: " << tr.get_ultimo_id() << endl;
	tr.set_id(tr.get_ultimo_id()+1);
	cout << "Insira o nome do tratador\n";
	cin >> r1;
	tr.set_nome(r1);
	cout << "Insira o CPF\n";
	cin >> r1;
	tr.set_cpf(r1);
	cout << "Insira a idade\n";
	cin >> r2;
	tr.set_idade(r2);
	cout << "Insira o tipo sanguineo(como inteiro)\n";
	cin >> r2;
	tr.set_tipo_sanguineo(r2);
	cout << "Insira o fator RH\n";
	cin >> r3;
	tr.set_fator_rh(r3);
	cout << "Insira a especialidade\n";
	cin >> r1;
	tr.set_especialidade(r1);
	cout << "Insira o nível de segurança\n";
	cin >> r2;
	tr.set_nivel_de_seguranca(r2);

	ofstream f;
	f.open("funcionarios.txt", ios::out | ios::app);

	if (!f.is_open())
	{
		cerr << "\nErro na abertura do arquivo\n";
		return;
	}

	f << tr.get_id()             << " | "
	  << "T"                     << " | "
	  << tr.get_nome()           << " | "
	  << tr.get_cpf()            << " | "
	  << tr.get_idade()          << " | "
	  << tr.get_tipo_sanguineo() << " | "
	  << tr.get_fator_rh()       << " | "
	  << tr.get_especialidade()  << " | "
	  << tr.get_nivel_de_seguranca() << " |\n";
	f.close();
}

// Setters e Getters:

// Nível_De_Segurança
int Tratador::get_nivel_de_seguranca(){
	return nivel_de_seguranca;
}
void Tratador::set_nivel_de_seguranca(int _nivel_de_seguranca){
	nivel_de_seguranca = _nivel_de_seguranca;
}

//Overload do <<
ostream& operator<< (ostream &o, Tratador t) {
o << "Id: " << t.get_id() << " Nome: " << t.get_nome() << " Função: Tratador "
  << " CPF: " << t.get_cpf() << " Idade: " << t.get_idade()
  << " Tipo sanguineo: " << t.get_tipo_sanguineo()
  << " Fator RH: " << t.get_fator_rh() << " Especialidade: " << t.get_especialidade()
  << " Nível de segurança: " << t.get_nivel_de_seguranca();
return o;
}