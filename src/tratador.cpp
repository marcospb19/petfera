#include "tratador.h"

Tratador::Tratador(){

}

Tratador::~Tratador(){
	
}

int Tratador::get_nivel_de_seguranca(){
	return(nivel_de_seguranca);
}

void Tratador::set_nivel_de_seguranca(int _nivel_de_seguranca){
	nivel_de_seguranca = _nivel_de_seguranca;
}