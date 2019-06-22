#ifndef VETERINARIO_H
#define VETERINARIO_H

#include <string>
#include "funcionario.h"
using namespace std;


class Veterinario : public Funcionario
{
	string crmv;

public:
	Veterinario();
	~Veterinario();

	friend ostream& operator<< (ostream &o, Veterinario v);

	// Setters e Getters:

	string get_crmv();
	void set_crmv(string _crmv);
};

void inserir_veterinario();

Veterinario get_veterinario_tabela(int _id);


#endif
