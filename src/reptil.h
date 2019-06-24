#ifndef REPTIL_H
#define REPTIL_H

#include <string>
#include "animal.h"
using namespace std;


class Reptil : protected Animal /**<Reptil, uma classe derivada de Animal*/
{
protected:
	bool venenoso; /**<Clasifica o Reptil entre venenoso ou nao venenoso*/
	string tipo_veneno; /**<Tipo do veneno dado em String*/

public:
	Reptil(); /**<Construtor da classe*/
	~Reptil(); /**<Destrutor da classe*/
};


class ReptilNativo : public Reptil, AnimalNativo /**<ReptilNativo, uma classe derivada de Reptil e AnimalNativo*/
{
public:
	ReptilNativo(); /**<Construtor da classe*/
	~ReptilNativo(); /**<Destrutor da classe*/
};


class ReptilExotico : public Reptil, AnimalExotico /**<ReptilExotico, uma classe derivada de Reptil e AnimalExotico*/
{
public:
	ReptilExotico(); /**<Construtor da classe*/
	~ReptilExotico(); /**<Destrutor da classe*/
};


#endif
