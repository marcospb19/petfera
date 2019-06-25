#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <vector>
#include <string>
using namespace std;


int ler_arquivo(const char* const caminho_do_arquivo , vector<string>& lista_de_animais);

int filtrar_linhas(int argc, char *argv[], vector<string>& lista_de_animais);

void filtrar_campo(vector<string>& lista_de_animais, char* arg, int coluna);

int escrever_arquivo(vector<string> lista_de_animais, string caminho_final);


#endif
