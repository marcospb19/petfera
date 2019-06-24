#ifndef VETERINARIO_H
#define VETERINARIO_H

#include <string>
#include "funcionario.h"
using namespace std;


class Veterinario : public Funcionario /**<Veterinario, uma classe derivada de Funcionario*/
{
	string crmv; /**<CRMV dado em String*/

public:
	Veterinario(); /**<Construtor da classe*/
	~Veterinario(); /**<Destrutor da classe*/

	friend ostream& operator<< (ostream &o, Veterinario v);

	// Setters e Getters:

	string get_crmv(); /**<função para pegar o CRMV do veterinario*/
	void set_crmv(string _crmv); /**<função para adicionar o CRMV do veterinario*/
};

void inserir_veterinario(); /**<função que insere veterinario ao programa*/

Veterinario get_veterinario_tabela(int _id);


#endif
