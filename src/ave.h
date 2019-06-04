#ifndef AVE_H
#define AVE_H

#include "animal.h"


class Ave : protected Animal
{
protected:
	double tamanho_do_bico_cm;
	double envergadura_das_asas;

public:
	Ave();
	~Ave();
};


class AveNativo : public Ave, AnimalNativo
{
public:
	AveNativo();
	~AveNativo();
};


class AveExotico : public Ave, AnimalExotico
{
public:
	AveExotico();
	~AveExotico();
};


#endif
