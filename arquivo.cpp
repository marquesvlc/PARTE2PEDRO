#include "arquivo.h"
#include <fstream>
#include <cstdlib>

// cria a pasta se ela ainda nao existir 
void criarPasta(string caminho) {
#ifdef _WIN32
    string cmd = "mkdir \"" + caminho + "\" 2>nul";
#else
    string cmd = "mkdir -p \"" + caminho + "\" 2>/dev/null";
#endif
    system(cmd.c_str());
}

// cria a estrutura
void Arquivo::criarPastas(Algoritmo alg, Tipo tipo) {
    string base = nomeAlgoritmo(alg);
    string tp = nomeTipoArquivo(tipo);

    criarPasta(base + "/Arquivos de Entrada/" + tp);
    criarPasta(base + "/Arquivos de Saida/" + tp);
    criarPasta(base + "/Arquivos de Tempo/" + tp);
}

void Arquivo::salvaEntrada(vector<int> &vet, Algoritmo alg, Tipo tipo) {
    criarPastas(alg, tipo);
    string tp = nomeTipoArquivo(tipo);
    string caminho = nomeAlgoritmo(alg) + "/Arquivos de Entrada/" + tp +
                      "/Entrada" + tp + to_string(vet.size()) + ".txt";

    ofstream arq(caminho);
    arq << vet.size() << "\n";
    for (unsigned i = 0; i < vet.size(); i++)
        arq << vet[i] << "\n";
}

void Arquivo::salvaSaida(vector<int> &vet, Algoritmo alg, Tipo tipo) {
    criarPastas(alg, tipo);
    string tp = nomeTipoArquivo(tipo);
    string caminho = nomeAlgoritmo(alg) + "/Arquivos de Saida/" + tp +
                      "/Saida" + tp + to_string(vet.size()) + ".txt";

    ofstream arq(caminho);
    arq << vet.size() << "\n";
    for (unsigned i = 0; i < vet.size(); i++)
        arq << vet[i] << "\n";
}

void Arquivo::salvaTempo(int n, double tempo, Algoritmo alg, Tipo tipo) {
    criarPastas(alg, tipo);
    string tp = nomeTipoArquivo(tipo);
    string caminho = nomeAlgoritmo(alg) + "/Arquivos de Tempo/" + tp +
                      "/Tempo" + tp + to_string(n) + ".txt";

    ofstream arq(caminho);
    arq << tempo << "\n";
}
