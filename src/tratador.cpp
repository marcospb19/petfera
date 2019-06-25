#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "tratador.h"
#include "menu.h"
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

	istringstream stream;
	string line;

	while(getline(f, line)){
		stream.str(line);

		getline(stream, conteudo);
		id = stoi(conteudo);
		if(id == _id){
			tr.set_id(id);
			getline(stream, conteudo);

			tr.set_nome(conteudo);
			getline(stream, conteudo);

			tr.set_cpf(conteudo);
			getline(stream, conteudo);

			tr.set_idade(atoi(conteudo.c_str()));
			getline(stream, conteudo);

			tr.set_tipo_sanguineo(conteudo);
			getline(stream, conteudo);

			tr.set_fator_rh(conteudo[0]);
			getline(stream, conteudo);

			tr.set_especialidade(conteudo);
			getline(stream, conteudo);

			tr.set_nivel_de_seguranca(atoi(conteudo.c_str()));
			f.close();
			stream.clear(line);
			return tr;
		}
		stream.clear(line);

	}
	f.close();
	return tr;
}

void inserir_tratador(){
	Tratador tr;
	string r1;
	int r2;
	char RH = 'X';

	tr.set_id(tr.get_ultimo_id()+1);
	cout << "Insira o nome do tratador\n";
	getline(cin, r1);
	tr.set_nome(r1);
	cout << "Insira o CPF\n";
	cin >> r1;
	tr.set_cpf(r1);
	while(true){
		cout << "Insira a idade\n";
		cin >> r2;
		if (checar_entrada_int(cin)){
			break;
		}
	}
	tr.set_idade(r2);
	while(true){
		cout << "Insira o tipo sanguineo\n1 - A; 2 - B; 3 - AB; 4 - O\n";
		cin >> r2;

		if (checar_entrada_do_menu(r2, cin, 1, 4) == true){
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
	tr.set_tipo_sanguineo(r1);
	while(true){
		cout << "Insira o fator RH\n1 - \'-\' 2 - \'+\'\n";
		cin >> r2;
		if(checar_entrada_do_menu(r2, cin, 1, 2) == true){
			switch(r2){
				case 01:
					RH = '-';
					break;
				case 02:
					RH = '+';
					break;
			}
			break;
		}
	}
	tr.set_fator_rh(RH);
	cout << "Insira a especialidade\n";
	cin >> r1;
	tr.set_especialidade(r1);
	while(true){
		cout << "Insira o nível de segurança\n";
		cin >> r2;
		if (checar_entrada_int(cin)){
			break;
		}
	}
	tr.set_nivel_de_seguranca(r2);
	cin.clear();
	cin.ignore(256, '\n');

	ofstream f;
	f.open("funcionarios.txt", ios::out | ios::app);

	if (!f.is_open())
	{
		cerr << "\nErro na abertura do arquivo\n";
		return;
	}

	f << tr.get_id()                << "|"
	  << "T"                        << "|"
	  << tr.get_nome()              << "|"
	  << tr.get_cpf()               << "|"
	  << tr.get_idade()             << "|"
	  << tr.get_tipo_sanguineo()    << "|"
	  << tr.get_fator_rh()          << "|"
	  << tr.get_especialidade()     << "|"
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

// Overload do <<
ostream& operator<< (ostream &o, Tratador t) {
	o << "Id: " << t.get_id()
	  << " Nome: " << t.get_nome()
	  << "Função: Tratador " << "\n"
	  << "CPF: " << t.get_cpf()
	  << " Idade: " << t.get_idade()
	  << " Tipo sanguineo: " << t.get_tipo_sanguineo()
	  << t.get_fator_rh() << "\n"
	  << "Especialidade: " << t.get_especialidade()
	  << " Nível de segurança: " << t.get_nivel_de_seguranca()
	  << "\n==========================================================";
	return o;
}
