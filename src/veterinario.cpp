#include "veterinario.h"

Veterinario::Veterinario(){

}

Veterinario::~Veterinario(){
	
}

string Veterinario::get_crmv(){
	return(crmv);
}

void Veterinario::set_crmv(string _crmv){
	crmv = _crmv;
}