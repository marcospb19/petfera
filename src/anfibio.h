#ifndef ANFIBIO_H
#define ANFIBIO_H

#include "animal.h"
#include "date.h"


class Anfibio : public Animal
{
protected:
	int total_de_mudas;
	Date ultima_muda;

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
