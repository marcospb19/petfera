#ifndef ANFIBIO_H
#define ANFIBIO_H

#include "animal.h"
#include "date.h"


class Anfibio : protected Animal /**<Anfibio, uma classe derivada de Animal*/
{
protected:
	int total_de_mudas; /**<Define numero total de mudas de um anfibio*/
	Date ultima_muda; /**<Salva a data da ultima muda*/

public:
	Anfibio(); /**<Construtor da classe*/
	~Anfibio(); /**<Destrutor da classe*/
};


class AnfibioNativo : public Anfibio, AnimalNativo /**<AnfibioNativo, uma classe derivada de AnimalNativo e Anfibio*/
{
public:
	AnfibioNativo(); /**<Construtor da classe*/
	~AnfibioNativo(); /**<Destrutor da classe*/
};


class AnfibioExotico : public Anfibio, AnimalExotico /**<AnfibioExotico, uma classe derivada de AnimalExotico e Anfibio*/
{
public:
	AnfibioExotico(); /**<Construtor da classe*/
	~AnfibioExotico(); /**<Destrutor da classe*/
};


#endif
