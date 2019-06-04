#ifndef REPTIL_H
#define REPTIL_H

#include <string>
#include "animal.h"
using namespace std;


class Reptil : protected Animal
{
protected:
	bool venenoso;
	string tipo_veneno;

public:
	Reptil();
	~Reptil();
};


class ReptilNativo : public Reptil, AnimalNativo
{
public:
	ReptilNativo();
	~ReptilNativo();
};


class ReptilExotico : public Reptil, AnimalExotico
{
public:
	ReptilExotico();
	~ReptilExotico();
};


#endif
