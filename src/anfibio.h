#ifndef ANFIBIO_H
#define ANFIBIO_H

#include "animal.h"
#include "date.h"


class Anfibio : protected Animal
{
protected:
	int total_de_mudas;
	Date ultima_muda;

public:
	Anfibio();
	~Anfibio();
};


class AnfibioNativo : public Anfibio, AnimalNativo
{
public:
	AnfibioNativo();
	~AnfibioNativo();
};


class AnfibioExotico : public Anfibio, AnimalExotico
{
public:
	AnfibioExotico();
	~AnfibioExotico();
};


#endif
