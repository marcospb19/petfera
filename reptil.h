#ifndef REPTIL_H
#define REPTIL_H

#include <string>
#include "animal.h"
using namespace std;


class Reptil : public Animal
{
	bool venenoso;
	string tipo_veneno;

public:
	Reptil();
	~Reptil();
};


class ReptilNativo
{
public:
	ReptilNativo();
	~ReptilNativo();
};


class ReptilExotico
{
public:
	ReptilExotico();
	~ReptilExotico();
};


#endif
