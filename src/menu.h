#ifndef MENU_H
#define MENU_H
using namespace std;


class Menu
{
public:
	bool continuar;

	void rodar_menu();

	Menu();
	~Menu();
};

bool checar_entrada_do_menu(int entrada, istream& CIN,
                            int limite_inferior, int limite_superior);
bool checar_entrada_int(istream& CIN);

#endif
