#include <iostream>
#include <fstream>
#include <cstdlib>
#include "animal.h"
#include "menu.h"
using namespace std;


Animal::Animal(){

}
Animal::~Animal(){

}

// Retorna o último id que está na última linha, (o último id
// é o do último animal registrado)
// Ao criar um novo animal é utilizado o id (último_id + 1)
int Animal::get_ultimo_id(){
	int id = 0;
	string conteudo;

	ifstream f;
	f.open("animais.txt", ios::in);
	if (!f.is_open())
	{
		cerr << "\nErro na abertura do arquivo\n";
		return -1;
	}

	getline(f, conteudo);
	while(!f.eof()){
		// Recebe o id e ignora o resto da linha
		f >> id;
		getline(f, conteudo);
	}

	f.close();
	return id;
}

void listar_animais(){
	cout << "\n";

	ifstream f;
	f.open("animais.txt", ios::in);
	if (!f.is_open())
	{
		cerr << "\nErro na abertura do arquivo\n";
		return;
	}

	string conteudo;
	string aux;

	Animal animal;

	// Pulando uma linha
	getline(f,conteudo);
	while(!f.eof()){
		// Id
		f >> conteudo;
		animal.set_id(atoi(conteudo.c_str()));
		// Classe
		f >> conteudo; f >> conteudo;
		animal.set_classe_animal(conteudo);
		// Nome
		f >> conteudo; f >> conteudo;
		animal.set_nome(conteudo);
		f >> conteudo;
		conteudo = "";
		f >> aux;

		// Pegando nome composto com vários espaços
		while(aux != "|"){
			conteudo += aux + " ";
			f >> aux;
		}
		animal.set_nome_cientifico(conteudo);
		f >> conteudo;
		animal.set_sexo(conteudo[0]);
		f >> conteudo; f >> conteudo;
		animal.set_tamanho(atof(conteudo.c_str()));
		f >> conteudo; f >> conteudo;
		animal.set_dieta(conteudo);
		f >> conteudo; f >> conteudo;
		animal.set_vt(atoi(conteudo.c_str()));
		f >> conteudo; f >> conteudo;
		animal.set_tr(atoi(conteudo.c_str()));
		f >> conteudo; f >> conteudo;
		animal.set_nome_batismo(conteudo);

		cout << animal << endl;

		getline(f,conteudo);
	}
	f.close();
}

void inserir_animal(){
	Animal animal;

	// Variáveis temporárias para receber entrada
	string r1; // Recebe classe_animal, dieta e nome_batismo
	int r2;
	double r3;

	animal.set_id(animal.get_ultimo_id()+1);
	while(true){
		cout << "Insira a classe do animal\n"
		     << "1 - Mamífero 2 - Ave 3 - Reptil 4 - Anfíbio\n";
		cin >> r2;

		if (checar_entrada_do_menu(r2, cin, 1, 4) == true){
			switch(r2){
				case 1:
					r1 = "Mamífero";
					break;
				case 2:
					r1 = "Ave";
					break;
				case 3:
					r1 = "Reptil";
					break;
				case 4:
					r1 = "Anfíbio";
					break;
			}
			break;
		}
	}
	animal.set_classe_animal(r1);
	cout << "Insira o nome\n";
	cin >> r1;
	animal.set_nome(r1);
	cout << "Insira o nome científico\n";
	cin >> r1;
	animal.set_nome_cientifico(r1);

	char sexo = 'X';

	while(true){
		cout << "Insira o sexo\n1 - Feminino 2 - Masculino\n";
		cin >> r2;

		if (checar_entrada_do_menu(r2, cin, 1, 2) == true){
			switch(r2){
				case 1:
					r3 = 'F';
					break;
				case 2:
					r3 = 'M';
					break;
			}
			break;
		}
	}
	animal.set_sexo(r3);
	while(true){
		cout << "Insira o tamanho\n";
		cin >> r4;
		if (!cin){
			cout << "Digite um nº real\n";
			cin.clear();
			cin.ignore(256, '\n');
		}
		else {
			break;
		}
	}
	animal.set_tamanho(r4);
	cout << "Insira a dieta\n";
	cin >> r1;
	animal.set_dieta(r1);
	while(true){
		cout << "Insira o id do veterinário\n";
		cin >> r2;
		if (!cin){
			cout << "Digite um inteiro\n";
			cin.clear();
			cin.ignore(256, '\n'); // Entender os argumentos dessa função
		}
		else if(checar_id_funcionario(r2, "V") == -1){
			cout << "Não existe veterinário com esse id\n";
		}
		else{
			break;
		}
	}
	animal.set_vt(r2);
	while(true){
		cout << "Insira o id do tratador\n";
		cin >> r2;
		if (!cin){
			cout << "Digite um inteiro\n";
			cin.clear();
			cin.ignore(256, '\n'); // Entender os argumentos dessa função
		}
		else if(checar_id_funcionario(r2, "T") == -1){
			cout << "Não existe tratador com esse id\n";
		}
		else{
			break;
		}
	}
	animal.set_tr(r2);
	cout << "Insira o nome de batismo do animal\n";
	cin >> r1;
	animal.set_nome_batismo(r1);

	ofstream f;
	f.open("animais.txt", ios::out | ios::app);
	if (!f.is_open())
	{
		cerr << "\nErro na abertura do arquivo\n";
		return;
	}

	f << '\n' << animal.get_id()        << " | "
	  << animal.get_classe_animal()     << " | "
	  << animal.get_nome()              << " | "
	  << animal.get_nome_cientifico()   << " | "
	  << animal.get_sexo()              << " | "
	  << animal.get_tamanho()           << " | "
	  << animal.get_dieta()             << " | "
	  << animal.get_vt()                << " | "
	  << animal.get_tr()                << " | "
	  << animal.get_nome_batismo()      << " | ";
//	  << '\n';
	f.close();
}

// Quando essa extração é utilizada?
ostream& operator <<(ostream &os, Animal an) {
	os << "Id: "               << an.get_id()
	   << " Nome: "            << an.get_nome()
	   << " Classe: "          << an.get_classe_animal()
	   << " Nome científico: " << an.get_nome_cientifico()
	   << " Sexo: "            << an.get_sexo()
	   << " Tamanho: "         << an.get_tamanho()
	   << " Dieta: "           << an.get_dieta()
	   << " Veterinário: "     << get_veterinario_tabela(an.get_vt()).get_nome()
	   << " Tratador: "        << get_tratador_tabela(an.get_tr()).get_nome()
	   << " Nome de batismo: " << an.get_nome_batismo();
	return os;
}

// Setters e Getters:

// Sexo
// Id
// vt
// tr
// Tamanho
// Nome
// Classe_Animal
// Nome_Cientifico
// Dieta
// Nome_Batismo
// Veterinario
// Tratador

char Animal::get_sexo(){
	return sexo;
}
void Animal::set_sexo(char _sexo){
	sexo = _sexo;
}

int Animal::get_id(){
	return id;
}
void Animal::set_id(int _id){
	id = _id;
}

int Animal::get_vt(){
	return vt;
}
void Animal::set_vt(int _vt){
	vt = _vt;
}

int Animal::get_tr(){
	return tr;
}
void Animal::set_tr(int _tr){
	tr = _tr;
}

double Animal::get_tamanho(){
	return tamanho;
}
void Animal::set_tamanho(double _tamanho){
	tamanho = _tamanho;
}

string Animal::get_nome(){
	return nome;
}
void Animal::set_nome(string _nome){
	nome = _nome;
}

string Animal::get_classe_animal(){
	return classe_animal;
}
void Animal::set_classe_animal(string _classe_animal){
	classe_animal = _classe_animal;
}

string Animal::get_nome_cientifico(){
	return nome_cientifico;
}
void Animal::set_nome_cientifico(string _nome_cientifico){
	nome_cientifico = _nome_cientifico;
}

string Animal::get_dieta(){
	return dieta;
}
void Animal::set_dieta(string _dieta){
	dieta = _dieta;
}

string Animal::get_nome_batismo(){
	return nome_batismo;
}
void Animal::set_nome_batismo(string _nome_batismo){
	nome_batismo = _nome_batismo;
}

Veterinario Animal::get_veterinario(){
	return veterinario;
}
void Animal::set_veterinario(Veterinario _veterinario){
	veterinario = _veterinario;
}

Tratador Animal::get_tratador(){
	return tratador;
}
void Animal::set_tratador(Tratador _tratador){
	tratador = _tratador;
}
