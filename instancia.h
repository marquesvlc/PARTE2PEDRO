#ifndef INSTANCIA_H
#define INSTANCIA_H

#include <vector>
#include <string>
using namespace std;

enum Tipo { CRESCENTE, DECRESCENTE, RANDOMICO };

class Instancia {
public:
    vector<int> vet;
    Tipo tipo;

    Instancia(int n, Tipo t);
};

string nomeTipo(Tipo t);       // pro texto do menu 
string nomeTipoArquivo(Tipo t); // pro nome de pasta/arquivo 

#endif
