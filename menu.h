#ifndef MENU_H
#define MENU_H

#include "instancia.h"
#include "ordenador.h"
#include "arquivo.h"

class Menu {
public:
    void executar();

private:
    Ordenador ordenador;
    Arquivo arquivo;

    int menuAlgoritmo();  // devolve 0 se for sair
    int menuTipo();
    int menuTamanho();

    void rodarUm(Algoritmo alg, Tipo tipo, int n);
    void rodarTudo(); // roda os 4 algoritmos, 3 tipos, 6 tamanhos de uma vez
};

#endif
