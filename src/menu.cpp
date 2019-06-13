#include "menu.h"

void menu(){
	short op = -1;
	while (op != 0){
		cout << "\nEscolha a opção desejada:" << endl;
		cout << "1 - Inserir funcionário" << endl;
		cout << "0 - Sair" << endl;
		cin >> op;
		switch(op){
			case 0:
				cout << "\nAté logo!" << endl;
				break;
			case 1:
				inserir_funcionario();
				break;
			case 2:
				listar_funcionarios();
				break;
			default:
				cout << "\nEscolha uma opção válida" << endl;
				break;
		}
	}
}

void inserir_funcionario(){
	string *funcao = new string;
	if(funcao){
		while (true){
			cout << "\nInsira a função do funcionário: " << endl;
			cin >> *funcao;
			if (*funcao == "Veterinário"){
				inserir_veterinario();
				break;
			}
			else if (*funcao == "Tratador"){
				inserir_tratador();
				break;
			}
			else{
				cout << "\nInsira um valor válido: Veterinário ou Tratador" << endl;
			}
		}
		delete funcao;
	}
	else{
		cerr << "\nMemória insuficiente" << endl;
	}
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

		ofstream saida;
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

void listar_funcionarios(){
	cout << "TODO" << endl;
}