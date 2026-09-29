#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "instancia.h"
#include "ordenador.h"
#include <vector>
#include <string>
using namespace std;

class Arquivo {
public:
    void salvaEntrada(vector<int> &vet, Algoritmo alg, Tipo tipo);
    void salvaSaida(vector<int> &vet, Algoritmo alg, Tipo tipo);
    void salvaTempo(int n, double tempo, Algoritmo alg, Tipo tipo);

private:
    void criarPastas(Algoritmo alg, Tipo tipo);
};

#endif
