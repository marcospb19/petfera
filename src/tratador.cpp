#include <iostream>
#include <fstream>
#include "tratador.h"
using namespace std;

Tratador::Tratador(){

}

Tratador::~Tratador(){

}

void inserir_tratador(){
	Tratador *trat = new Tratador;
	if(trat){
		trat->set_id(2);
		trat->set_nome("João Alberto");
		trat->set_cpf("007.404.200-98");
		trat->set_idade(45);
		trat->set_tipo_sanguineo(0);
		trat->set_fator_rh('-');
		trat->set_especialidade("Répteis e Aves");
		trat->set_nivel_de_seguranca(1);

		ofstream saida;
		saida.open("funcionarios.txt", ios::out | ios::app);
		if(saida.is_open()){
			saida << "\n" << trat->get_id() << " | Tratador | " << trat->get_nome() << " | "
			<< trat->get_cpf() << " | " << trat->get_idade() << " | "
			<< trat->get_tipo_sanguineo() << " | " << trat->get_fator_rh() << " | "
			<< trat->get_especialidade() << " | | " << trat->get_nivel_de_seguranca() << " | ";
			saida.close();
		}
		else{
			cerr << "\nErro na abertura do arquivo" << endl;
		}
		delete trat;
	}
	else{
		cerr << "\nMemória insuficiente" << endl;
	}
}

// Setters e Getters:

// Nível_De_Segurança
int Tratador::get_nivel_de_seguranca(){
	return(nivel_de_seguranca);
}
void Tratador::set_nivel_de_seguranca(int _nivel_de_seguranca){
	nivel_de_seguranca = _nivel_de_seguranca;
}
