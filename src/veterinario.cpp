#include <iostream>
#include <fstream>
#include "veterinario.h"
using namespace std;


Veterinario::Veterinario(){

}

Veterinario::~Veterinario(){

}

void inserir_veterinario(){
	Veterinario *vet = new Veterinario;
	if(vet){
		vet->set_id(1);
		vet->set_nome("Daniel Oscar");
		vet->set_cpf("123.456.789-10");
		vet->set_idade(30);
		vet->set_tipo_sanguineo(0);
		vet->set_fator_rh('+');
		vet->set_especialidade("Felinos");
		vet->set_crmv("CRMV-GO 0406");

		std::ofstream saida;
		saida.open("funcionarios.txt", ios::out | ios::app);
		if(saida.is_open()){
			saida << "\n" << vet->get_id() << " | Veterinário | " << vet->get_nome() << " | "
			<< vet->get_cpf() << " | " << vet->get_idade() << " | "
			<< vet->get_tipo_sanguineo() << " | " << vet->get_fator_rh() << " | "
			<< vet->get_especialidade() << " | " << vet->get_crmv() << " |  | ";
			saida.close();
		}
		else{
			cerr << "\nErro na abertura do arquivo" << endl;
		}
		delete vet;
	}
	else{
		cerr << "\nMemória insuficiente" << endl;
	}
}

// Setters e Getters:

// CRMV
string Veterinario::get_crmv(){
	return(crmv);
}
void Veterinario::set_crmv(string _crmv){
	crmv = _crmv;
}
