#ifndef ANFIBIO_H
#define ANFIBIO_H

#include "animal.h"


class Anfibio : public Animal
{
	int total_de_mudas;
//	date ultima_muda;
public:
	Anfibio();
	~Anfibio();
};


class AnfibioNativo
{
public:
	AnfibioNativo();
	~AnfibioNativo();
};


class AnfibioExotico
{
public:
	AnfibioExotico();
	~AnfibioExotico();
};


#endif
