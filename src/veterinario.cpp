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
	string r1;
	int r2;
	char r3;

	//cout << "Ultimo id: " << vt.get_ultimo_id() << endl;
	vt.set_id(vt.get_ultimo_id()+1);
	cout << "Insira o nome do veterinário\n";
	cin >> r1;
	vt.set_nome(r1);
	cout << "Insira o CPF\n";
	cin >> r1;
	vt.set_cpf(r1);
	cout << "Insira a idade\n";
	cin >> r2;
	vt.set_idade(r2);
	cout << "Insira o tipo sanguineo(como inteiro)\n";
	cin >> r2;
	vt.set_tipo_sanguineo(r2);
	cout << "Insira o fator RH\n";
	cin >> r3;
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

//Overload do <<
ostream& operator<< (ostream &o, Veterinario v) {
o << "Id: " << v.get_id() << " Nome: " << v.get_nome() << " Função: Veterinário "
  << " CPF: " << v.get_cpf() << " Idade: " << v.get_idade()
  << " Tipo sanguineo: " << v.get_tipo_sanguineo()
  << " Fator RH: " << v.get_fator_rh() << " Especialidade: " << v.get_especialidade()
  << " Codigo CRMV: " << v.get_crmv();
return o;
}