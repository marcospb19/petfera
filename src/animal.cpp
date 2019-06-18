#include <iostream>
#include <fstream>
#include <cstdlib>
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
	cout << "\n";
	string conteudo, aux;
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
		f >> conteudo;
		animal.set_id(atoi(conteudo.c_str()));
		f >> conteudo; f >> conteudo;
		animal.set_classe(conteudo);
		f >> conteudo; f >> conteudo;
		animal.set_nome(conteudo);
		f >> conteudo; 
		conteudo = "";
		f >> aux;
		//Pegando nome
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
	string r1;
	int r2;
	char r3;
	double r4;

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
	while(true){
		cout << "Insira o id do veterinário\n";
		cin >> r2;
		if(checar_id_funcionario(r2, "V") == -1){
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
		if(checar_id_funcionario(r2, "T") == -1){
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
	  << animal.get_classe()            << " | "
	  << animal.get_nome()              << " | "
	  << animal.get_nome_cientifico()   << " | "
	  << animal.get_sexo()              << " | "
	  << animal.get_tamanho()           << " | "
	  << animal.get_dieta()             << " | "
	  << animal.get_vt()                << " | "
	  << animal.get_tr()                << " | "
	  << animal.get_nome_batismo()      << " | ";
	  //<< '\n';
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

ostream& operator<< (ostream &o, Animal a) {
o << "Id: " << a.get_id() << " Nome: " << a.get_nome()
  << " Classe: " << a.get_classe() << " Nome científico: " << a.get_nome_cientifico()
  << " Sexo: " << a.get_sexo() << " Tamanho: " << a.get_tamanho()
  << " Dieta: " << a.get_dieta() 
  << " Veterinário: " << get_veterinario_tabela(a.get_vt()).get_nome()
  << " Tratador: " << get_tratador_tabela(a.get_tr()).get_nome()
  << " Nome de batismo: " << a.get_nome_batismo();
return o;
}