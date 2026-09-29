#include "instancia.h"
#include <cstdlib>

Instancia::Instancia(int n, Tipo t) {
    tipo = t;
    vet.resize(n);

    if (tipo == CRESCENTE) {
        for (int i = 0; i < n; i++)
            vet[i] = i + 1;
    }
    else if (tipo == DECRESCENTE) {
        for (int i = 0; i < n; i++)
            vet[i] = n - i;
    }
    else {
        for (int i = 0; i < n; i++)
            vet[i] = rand() % 1000000 + 1;
    }
}

string nomeTipo(Tipo t) {
    if (t == CRESCENTE) return "Crescente";
    if (t == DECRESCENTE) return "Decrescente";
    return "Randomico";
}

string nomeTipoArquivo(Tipo t) {
    if (t == CRESCENTE) return "Crescente";
    if (t == DECRESCENTE) return "Decrescente";
    return "Random";
}
