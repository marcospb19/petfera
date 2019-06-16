#include <iostream>
#include <fstream>
#include "tratador.h"
using namespace std;


Tratador::Tratador(){

}
Tratador::~Tratador(){

}

void inserir_tratador(){
	Tratador tr;

	tr.set_id(2);
	tr.set_nome("João Alberto");
	tr.set_cpf("007.404.200-98");
	tr.set_idade(45);
	tr.set_tipo_sanguineo(0);
	tr.set_fator_rh('-');
	tr.set_especialidade("Répteis e Aves");
	tr.set_nivel_de_seguranca(1);

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
// /* <<     */                  << " | " Pular atributo, a discutir
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
