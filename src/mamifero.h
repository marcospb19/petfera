#ifndef MAMIFERO_H
#define MAMIFERO_H

#include <string>
#include "animal.h"
using namespace std;


class Mamifero : public Animal
{
protected:
	string cor_pelo;

public:
	Mamifero();
	~Mamifero();
};


class MamiferoNativo
{
public:
	MamiferoNativo();
	~MamiferoNativo();
};


class MamiferoExotico
{
public:
	MamiferoExotico();
	~MamiferoExotico();
};


#endif
