#ifndef AVE_H
#define AVE_H

#include "animal.h"


class Ave : public Animal
{
	double tamanho_do_bico_cm;
	double envergadura_das_asas;

public:
	Ave();
	~Ave();
};


class AveNativo
{
public:
	AveNativo();
	~AveNativo();
};


class AveExotico
{
public:
	AveExotico();
	~AveExotico();
};


#endif
