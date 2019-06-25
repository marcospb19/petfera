#include <iostream>
using namespace std;


void mostrar_ajuda()
{
	cerr << "\nEscreva ./exportar <Nome-Do-Arquivo>\n"
	     << "\n"
	     << "Flags:\n"
	     << "    -c <Classe>\n"
	     << "\tFiltra animais pela classe animal.\n"
	     << "\n"
	     << "    Classes disponíveis (Case-Sensitive):\n"
		 << "\tAnfNat\n"
		 << "\tAnfExo\n"
		 << "\tAveNat\n"
		 << "\tAveExo\n"
		 << "\tMamNat\n"
		 << "\tMamExo\n"
		 << "\tRepNat\n"
		 << "\tRepExo\n"
	     << "\n"
	     << "    -v <veterinario>\n"
	     << "\tFiltra animais sob a responsabilidade apenas do veterinário determinado.\n"
	     << "\n"
	     << "    -t <tratador>​\n"
	     << "\tFiltra animais sob a responsabilidade apenas do tratador determinado.\n";
}
