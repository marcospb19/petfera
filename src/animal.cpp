#include <iostream>
#include <fstream>
#include "animal.h"
using namespace std;

Animal::Animal(){

}

Animal::~Animal(){
	
}

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
		f >> id;
		getline(f, conteudo);
	}
	f.close();
	return id;
}

void listar_animais(){
	cout << "TODO\n";
	string conteudo;
	Animal animal;
	ifstream f;

	f.open("animais.txt", ios::in);
	if (!f.is_open())
	{
		cerr << "\nErro na abertura do arquivo\n";
		return;
	}
	//Pulando uma linha
	getline(f,conteudo);
	while(!f.eof()){
		//Mostrando só o nome
		for(int i = 0; i < 4; i++){
			f >> conteudo;
		}
		f >> conteudo;
		cout << conteudo << endl;

		//Pulando o resto da linha
		getline(f,conteudo);
	}
}

void inserir_animal(){
	Animal animal;
	string r1;
	int r2;
	char r3;
	double r4;

	cout << "Ultimo id: " << animal.get_ultimo_id() << endl;
	animal.set_id(animal.get_ultimo_id()+1);
	cout << "Insira a classe do animal\n";
	cin >> r1;
	animal.set_classe(r1);
	cout << "Insira o nome\n";
	cin >> r1;
	animal.set_nome(r1);
	cout << "Insira o nome científico\n";
	cin >> r1;
	animal.set_nome_cientifico(r1);
	cout << "Insira o sexo\n";
	cin >> r3;
	animal.set_sexo(r3);
	cout << "Insira o tamanho\n";
	cin >> r4;
	animal.set_tamanho(r4);
	cout << "Insira a dieta\n";
	cin >> r1;
	animal.set_dieta(r1);
	cout << "Insira o id do veterinário\n";
	cin >> r2;
	animal.set_vt(r2);
	cout << "Insira o id do tratador\n";
	cin >> r2;
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

	f << animal.get_id()                << " | "
	  << animal.get_classe()            << " | "
	  << animal.get_nome()              << " | "
	  << animal.get_nome_cientifico()   << " | "
	  << animal.get_sexo()              << " | "
	  << animal.get_tamanho()           << " | "
	  << animal.get_dieta()             << " | "
	  << animal.get_vt()                << " | "
	  << animal.get_tr()                << " | "
	  << animal.get_nome_batismo()      << " | "
	  << '\n';
	f.close();
}

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

string Animal::get_classe(){
	return classe;
}
void Animal::set_classe(string _classe){
	classe = _classe;
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