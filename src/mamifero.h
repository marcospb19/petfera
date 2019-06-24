#ifndef MAMIFERO_H
#define MAMIFERO_H

#include <string>
#include "animal.h"
using namespace std;


class Mamifero : protected Animal /**<Mamofero, uma classe derivada de Animal*/
{
protected:
	string cor_pelo; /**<Cor do pelo dado em String*/

public:
	Mamifero(); /**<Construtor da classe*/
	~Mamifero(); /**<Destrutor da classe*/
};


class MamiferoNativo : public Mamifero, AnimalNativo /**<MamiferoNativo, uma classe derivada de Mamifero e AnimalNativo*/
{
public:
	MamiferoNativo(); /**<Construtor da classe*/
	~MamiferoNativo(); /**<Destrutor da classe*/
};


class MamiferoExotico : public Mamifero, AnimalExotico /**<MamiferoExotico, uma classe derivada de Mamifero e AnimalExotico*/
{
public:
	MamiferoExotico(); /**<Construtor da classe*/
	~MamiferoExotico(); /**<Destrutor da classe*/
};


#endif
