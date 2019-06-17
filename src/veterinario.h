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

	string get_crmv();
	void set_crmv(string _crmv);

	friend ostream& operator<< (ostream &o, Veterinario v);
};

void inserir_veterinario();


#endif
