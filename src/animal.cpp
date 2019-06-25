#include <iostream>
#include <fstream>
#include <cstdlib>
#include "animal.h"
#include "menu.h"
#include <vector>
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

void listar_animais_filtro(){
	int filtro;
	cout << "\n";

	while(true){
		cout << "Insira o filtro desejado\n1 - Por tratador 2 - Por veterinário 3 - Por classe\n";
		cin >> filtro;
		if (checar_entrada_do_menu(filtro, cin, 1, 3) == true){
			switch(filtro){
				case 1:
					listar_animais_tratador();
					break;
				case 2:
					listar_animais_veterinario();
					break;
				case 3:
					listar_animais_classe();
					break;
			}
			break;
		}
	}
}

void listar_animais_tratador(){
	int id;
	while(true){
		cout << "Insira o id do tratador\n";
		cin >> id;
		if (checar_entrada_int(cin)){
			if(checar_id_funcionario(id, "T") == -1){
			cout << "Não existe tratador com esse id\n";
			}
			else{
				break;
			}
		}
	}
	string conteudo, aux;
	ifstream f;
	Animal animal;
	f.open("animais.txt", ios::in);
	if (!f.is_open())
	{
		cerr << "\nErro na abertura do arquivo\n";
		return;
	}
	getline(f, conteudo);
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
		if(animal.get_tr() == id){
			f >> conteudo; f >> conteudo;
			animal.set_nome_batismo(conteudo);

			cout << animal << endl;
		}

		getline(f, conteudo);
	}
	f.close();
}

void listar_animais_veterinario(){
	int id;
	while(true){
		cout << "Insira o id do veterinário\n";
		cin >> id;
		if (checar_entrada_int(cin)){
			if(checar_id_funcionario(id, "V") == -1){
			cout << "Não existe veterinário com esse id\n";
			}
			else{
				break;
			}
		}
	}
	string conteudo, aux;
	ifstream f;
	Animal animal;
	f.open("animais.txt", ios::in);
	if (!f.is_open())
	{
		cerr << "\nErro na abertura do arquivo\n";
		return;
	}
	getline(f, conteudo);
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
		if(animal.get_vt() == id){
			f >> conteudo; f >> conteudo;
			animal.set_tr(atoi(conteudo.c_str()));
			f >> conteudo; f >> conteudo;
			animal.set_nome_batismo(conteudo);

			cout << animal << endl;
		}

		getline(f, conteudo);
	}
	f.close();
}

void listar_animais_classe(){
	int cl;
	string classe;
	while(true){
		cout << "Insira a classe do animal\n"
		     << "1 - Mamífero 2 - Ave 3 - Reptil 4 - Anfíbio\n";
		cin >> cl;

		if (checar_entrada_do_menu(cl, cin, 1, 4) == true){
			switch(cl){
				case 1:
					classe = "Mamífero";
					break;
				case 2:
					classe = "Ave";
					break;
				case 3:
					classe = "Reptil";
					break;
				case 4:
					classe = "Anfíbio";
					break;
			}
			break;
		}
	}
	string conteudo, aux;
	ifstream f;
	Animal animal;
	f.open("animais.txt", ios::in);
	if (!f.is_open())
	{
		cerr << "\nErro na abertura do arquivo\n";
		return;
	}
	getline(f, conteudo);
	while(!f.eof()){
		// Id
		f >> conteudo;
		animal.set_id(atoi(conteudo.c_str()));
		// Classe
		f >> conteudo; f >> conteudo;
		animal.set_classe_animal(conteudo);
		if(animal.get_classe_animal() == classe){
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
		}

		getline(f, conteudo);
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
					sexo = 'F';
					break;
				case 2:
					sexo = 'M';
					break;
			}
			break;
		}
	}
	animal.set_sexo(sexo);
	while(true){
		cout << "Insira o tamanho\n";
		cin >> r3;
		if (!cin){
			cout << "Digite um nº real\n";
			cin.clear();
			cin.ignore(256, '\n');
		}
		else {
			break;
		}
	}
	animal.set_tamanho(r3);
	cout << "Insira a dieta\n";
	cin >> r1;
	animal.set_dieta(r1);
	while(true){
		cout << "Insira o id do veterinário\n";
		cin >> r2;
		if (checar_entrada_int(cin)){
			if(checar_id_funcionario(r2, "V") == -1){
				cout << "Não existe veterinário com esse id\n";
			}
			else{
				break;
			}
		}
	}
	animal.set_vt(r2);
	while(true){
		cout << "Insira o id do tratador\n";
		cin >> r2;
		if (checar_entrada_int(cin)){
			if(checar_id_funcionario(r2, "T") == -1){
			cout << "Não existe tratador com esse id\n";
			}
			else{
				break;
			}
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

int checar_id_animal(int _id){
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
		if(id == _id){
			return 1;
		}
		getline(f, conteudo);
	}
	f.close();
	return -1;
}

void remover_animal(){
	Animal animal;
	vector<Animal> animais;

	int r1 = 0;
	string conteudo, aux;

	while (true){
		cout << "Digite o id do animal a ser removido:\n";
		cin >> r1;
		if(checar_entrada_int(cin)){
			if (checar_id_animal(r1) == -1){
				cout << "Não existe animal com esse id\n";
			}
			else{
				break;
			}	
		}
	}

	ifstream f_read;
	f_read.open("animais.txt", ios::in);
	if (!f_read.is_open())
	{
		cerr << "\nErro na abertura do arquivo\n";
		return;
	}

	getline(f_read, conteudo);

	while(!f_read.eof()){
		// Id
		f_read >> conteudo;
		animal.set_id(atoi(conteudo.c_str()));

		if(r1 != animal.get_id()) {
			// Classe
			f_read >> conteudo; f_read >> conteudo;
			animal.set_classe_animal(conteudo);
			// Nome
			f_read >> conteudo; f_read >> conteudo;
			animal.set_nome(conteudo);
			f_read >> conteudo;
			conteudo = "";
			f_read >> aux;

			// Pegando nome composto com vários espaços
			while(aux != "|"){
				conteudo += aux + " ";
				f_read >> aux;
			}
			animal.set_nome_cientifico(conteudo);
			f_read >> conteudo;
			animal.set_sexo(conteudo[0]);
			f_read >> conteudo; f_read >> conteudo;
			animal.set_tamanho(atof(conteudo.c_str()));
			f_read >> conteudo; f_read >> conteudo;
			animal.set_dieta(conteudo);
			f_read >> conteudo; f_read >> conteudo;
			animal.set_vt(atoi(conteudo.c_str()));
			f_read >> conteudo; f_read >> conteudo;
			animal.set_tr(atoi(conteudo.c_str()));
			f_read >> conteudo; f_read >> conteudo;
			animal.set_nome_batismo(conteudo);
			animais.push_back(animal);
		}

		getline(f_read,conteudo);
	}
	f_read.close();

	ofstream f_write;
	f_write.open("animais.txt", ios::out);

	if (!f_write.is_open())
	{
		cerr << "\nErro na abertura do arquivo\n";
		return;
	}

	f_write << "Id | Classe | Nome_animal | Nome_cientifico | Sexo | Tamanho | Dieta | Veterinario | Tratador | Nome_bastismo ";
	for (unsigned int i = 0; i < animais.size(); i++)
	{

		f_write << '\n' << animais[i].get_id()        << " | "
		  << animais[i].get_classe_animal()     << " | "
		  << animais[i].get_nome()              << " | "
		  << animais[i].get_nome_cientifico()   << " | "
		  << animais[i].get_sexo()              << " | "
		  << animais[i].get_tamanho()           << " | "
		  << animais[i].get_dieta()             << " | "
		  << animais[i].get_vt()                << " | "
		  << animais[i].get_tr()                << " | "
		  << animais[i].get_nome_batismo()      << " | ";
	//	  << '\n';
	}

	f_write.close();

}

void editar_animal(){
	Animal animal, animal_editado;
	vector<Animal> animais;

	int id_editar = 0;
	string conteudo, aux;

	while (true){
		cout << "Digite o id do animal a ser editado:\n";
		cin >> id_editar;
		if(checar_entrada_int(cin)){
			if (checar_id_animal(id_editar) == -1){
				cout << "Não existe animal com esse id\n";
			}
			else{
				break;
			}	
		}
	}

	// Variáveis temporárias para receber entrada
	string r1; // Recebe classe_animal, dieta e nome_batismo
	int r2;
	double r3;

	animal_editado.set_id(id_editar);
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
	animal_editado.set_classe_animal(r1);
	cout << "Insira o nome\n";
	cin >> r1;
	animal_editado.set_nome(r1);
	cout << "Insira o nome científico\n";
	cin >> r1;
	animal_editado.set_nome_cientifico(r1);

	char sexo = 'X';

	while(true){
		cout << "Insira o sexo\n1 - Feminino 2 - Masculino\n";
		cin >> r2;

		if (checar_entrada_do_menu(r2, cin, 1, 2) == true){
			switch(r2){
				case 1:
					sexo = 'F';
					break;
				case 2:
					sexo = 'M';
					break;
			}
			break;
		}
	}
	animal_editado.set_sexo(sexo);
	while(true){
		cout << "Insira o tamanho\n";
		cin >> r3;
		if (!cin){
			cout << "Digite um nº real\n";
			cin.clear();
			cin.ignore(256, '\n');
		}
		else {
			break;
		}
	}
	animal_editado.set_tamanho(r3);
	cout << "Insira a dieta\n";
	cin >> r1;
	animal_editado.set_dieta(r1);
	while(true){
		cout << "Insira o id do veterinário\n";
		cin >> r2;
		if (checar_entrada_int(cin)){
			if(checar_id_funcionario(r2, "V") == -1){
				cout << "Não existe veterinário com esse id\n";
			}
			else{
				break;
			}
		}
	}
	animal_editado.set_vt(r2);
	while(true){
		cout << "Insira o id do tratador\n";
		cin >> r2;
		if (checar_entrada_int(cin)){
			if(checar_id_funcionario(r2, "T") == -1){
			cout << "Não existe tratador com esse id\n";
			}
			else{
				break;
			}
		}
	}
	animal_editado.set_tr(r2);
	cout << "Insira o nome de batismo do animal\n";
	cin >> r1;
	animal_editado.set_nome_batismo(r1);

	ifstream f_read;
	f_read.open("animais.txt", ios::in);
	if (!f_read.is_open())
	{
		cerr << "\nErro na abertura do arquivo\n";
		return;
	}

	getline(f_read, conteudo);

	while(!f_read.eof()){
		// Id
		f_read >> conteudo;
		animal.set_id(atoi(conteudo.c_str()));
		// Classe
		f_read >> conteudo; f_read >> conteudo;
		animal.set_classe_animal(conteudo);
		// Nome
		f_read >> conteudo; f_read >> conteudo;
		animal.set_nome(conteudo);
		f_read >> conteudo;
		conteudo = "";
		f_read >> aux;

		// Pegando nome composto com vários espaços
		while(aux != "|"){
			conteudo += aux + " ";
			f_read >> aux;
		}
		animal.set_nome_cientifico(conteudo);
		f_read >> conteudo;
		animal.set_sexo(conteudo[0]);
		f_read >> conteudo; f_read >> conteudo;
		animal.set_tamanho(atof(conteudo.c_str()));
		f_read >> conteudo; f_read >> conteudo;
		animal.set_dieta(conteudo);
		f_read >> conteudo; f_read >> conteudo;
		animal.set_vt(atoi(conteudo.c_str()));
		f_read >> conteudo; f_read >> conteudo;
		animal.set_tr(atoi(conteudo.c_str()));
		f_read >> conteudo; f_read >> conteudo;
		animal.set_nome_batismo(conteudo);
		animais.push_back(animal);

		getline(f_read,conteudo);
	}
	f_read.close();

	for (unsigned int i = 0; i < animais.size(); i++)
	{
		if (animais[i].get_id() == id_editar){
			animais[i] = animal_editado;
		}
	}

	ofstream f_write;
	f_write.open("animais.txt", ios::out);

	if (!f_write.is_open())
	{
		cerr << "\nErro na abertura do arquivo\n";
		return;
	}

	f_write << "Id | Classe | Nome_animal | Nome_cientifico | Sexo | Tamanho | Dieta | Veterinario | Tratador | Nome_bastismo ";
	for (unsigned int i = 0; i < animais.size(); i++)
	{

		f_write << '\n' << animais[i].get_id()        << " | "
		  << animais[i].get_classe_animal()     << " | "
		  << animais[i].get_nome()              << " | "
		  << animais[i].get_nome_cientifico()   << " | "
		  << animais[i].get_sexo()              << " | "
		  << animais[i].get_tamanho()           << " | "
		  << animais[i].get_dieta()             << " | "
		  << animais[i].get_vt()                << " | "
		  << animais[i].get_tr()                << " | "
		  << animais[i].get_nome_batismo()      << " | ";
	//	  << '\n';
	}

	f_write.close();

}

// Quando essa extração é utilizada?
ostream& operator <<(ostream &os, Animal an) {
	os << "Id: "               << an.get_id()
	   << " Nome: "            << an.get_nome()
	   << " Classe: "          << an.get_classe_animal() 
	   << " Sexo: "            << an.get_sexo() << "\n"
	   << "Nome científico: " << an.get_nome_cientifico()
	   << "Dieta: "           << an.get_dieta() << "\n"
	   << "Veterinário: "     << get_veterinario_tabela(an.get_vt()).get_nome()
	   << "Tratador: "        << get_tratador_tabela(an.get_tr()).get_nome() << "\n" 
	   << "Tamanho: "         << an.get_tamanho()
	   << " Nome de batismo: " << an.get_nome_batismo()
	   << "\n==========================================================";
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
