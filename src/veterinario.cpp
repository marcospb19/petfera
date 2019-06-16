#include <iostream>
#include <fstream>
#include "veterinario.h"
using namespace std;


Veterinario::Veterinario(){

}
Veterinario::~Veterinario(){

}

void inserir_veterinario(){
	Veterinario vt;
	vt.set_id(1);
	vt.set_nome("Daniel Oscar");
	vt.set_cpf("123.456.789-10");
	vt.set_idade(30);
	vt.set_tipo_sanguineo(0);
	vt.set_fator_rh('+');
	vt.set_especialidade("Felinos");
	vt.set_crmv("CRMV-GO 0406");

	std::ofstream f;
	f.open("funcionarios.txt", ios::out | ios::app);
	if (!f.is_open())
	{
		cerr << "\nErro na abertura do arquivo\n";
		return;
	}

	f << vt.get_id()             << " | "
	  << "Veterinário"           << " | "
	  << vt.get_nome()           << " | "
	  << vt.get_cpf()            << " | "
	  << vt.get_idade()          << " | "
	  << vt.get_tipo_sanguineo() << " | "
	  << vt.get_fator_rh()       << " | "
	  << vt.get_especialidade()  << " | "
	  << vt.get_crmv()           << " | "
// /* <<     */                  << " | " Pular atributo, a discutir
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
