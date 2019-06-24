#ifndef AVE_H
#define AVE_H

#include "animal.h"


class Ave : protected Animal /**<Ave, uma classe derivada de Animal*/
{
protected:
	double tamanho_do_bico_cm; /**<Tamanho do bico medido em centimetros (double)*/
	double envergadura_das_asas; /**<Envergadura das asas medido em centimetros (double)*/

public:
	Ave(); /**<Construtor da classe*/
	~Ave(); /**<Destrutor da classe*/
};


class AveNativo : public Ave, AnimalNativo /**<AveNativo, uma classe derivada de Ave e AnimalNativo*/
{
public:
	AveNativo(); /**<Construtor da classe*/
	~AveNativo(); /**<Destrutor da classe*/
};


class AveExotico : public Ave, AnimalExotico /**<AveExotico, uma classe derivada de Ave e AnimalExotico*/
{
public:
	AveExotico(); /**<Construtor da classe*/
	~AveExotico(); /**<Destrutor da classe*/
};


#endif
