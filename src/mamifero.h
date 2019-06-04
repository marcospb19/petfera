#ifndef MAMIFERO_H
#define MAMIFERO_H

#include <string>
#include "animal.h"
using namespace std;


class Mamifero : protected Animal
{
protected:
	string cor_pelo;

public:
	Mamifero();
	~Mamifero();
};


class MamiferoNativo : public Mamifero, AnimalNativo
{
public:
	MamiferoNativo();
	~MamiferoNativo();
};


class MamiferoExotico : public Mamifero, AnimalExotico
{
public:
	MamiferoExotico();
	~MamiferoExotico();
};


#endif
