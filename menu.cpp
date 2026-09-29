#include "menu.h"
#include <iostream>
using namespace std;

int Menu::menuAlgoritmo() {
    cout << "\n\n";
    cout << "Menu\n";
    cout << "\n";
    cout << "1 => Insertion Sort\n";
    cout << "2 => Selection Sort\n";
    cout << "3 => Shell Sort\n";
    cout << "4 => Bubble Sort\n";
    cout << "5 => Rodar tudo (todos os algoritmos/tipos/tamanhos)\n";
    cout << "0 => Sair do Programa\n";
    cout << "Escolha uma opcao: ";

    int x;
    cin >> x;
    return x;
}

int Menu::menuTipo() {
    cout << "\n \n";
    cout << "  Tipo de Entradas  \n";
    cout << "\n";
    cout << "1 => Crescente\n";
    cout << "2 => Decrescente\n";
    cout << "3 => Randomico\n";
    cout << "0 => Voltar\n";
    cout << "Escolha uma opcao: ";

    int x;
    cin >> x;
    return x;
}

int Menu::menuTamanho() {
    cout << "\n \n";
    cout << "     Tamanhos    \n";
    cout << "\n";
    cout << "1 => 10\n";
    cout << "2 => 100\n";
    cout << "3 => 1.000\n";
    cout << "4 => 10.000\n";
    cout << "5 => 100.000\n";
    cout << "6 => 1.000.000\n";
    cout << "0 => Voltar\n";
    cout << "Escolha uma opcao: ";

    int x;
    cin >> x;
    return x;
}

void Menu::rodarUm(Algoritmo alg, Tipo tipo, int n) {
    Instancia inst(n, tipo);
    arquivo.salvaEntrada(inst.vet, alg, tipo);

    double tempo = ordenador.ordenar(inst.vet, alg);
    // dai pra frente o vetor ja ta ordenado

    arquivo.salvaSaida(inst.vet, alg, tipo);
    arquivo.salvaTempo(n, tempo, alg, tipo);

    cout << nomeAlgoritmo(alg) << " / " << nomeTipo(tipo) << " / n=" << n
         << " -> tempo: " << tempo << " s\n";
}

void Menu::rodarTudo() {
    Algoritmo algs[] = {INSERTION, SELECTION, SHELL, BUBBLE};
    Tipo tipos[] = {CRESCENTE, DECRESCENTE, RANDOMICO};
    int tamanhos[] = {10, 100, 1000, 10000, 100000, 1000000};

    for (Algoritmo a : algs)
        for (Tipo t : tipos)
            for (int n : tamanhos)
                rodarUm(a, t, n);

    cout << "\nacabou tudo\n";
}

void Menu::executar() {
    while (true) {
        int op = menuAlgoritmo();

        if (op == 0) {
            cout << "saindo\n";
            break;
        }
        if (op == 5) {
            rodarTudo();
            continue;
        }
        if (op < 1 || op > 4) {
            cout << "opcao invalida\n";
            continue;
        }

        Algoritmo alg = (Algoritmo)(op - 1); // 1->INSERTION(0), 2->SELECTION(1)...

        int tipoOp = menuTipo();
        if (tipoOp == 0) continue;
        if (tipoOp < 1 || tipoOp > 3) {
            cout << "opcao invalida\n";
            continue;
        }
        Tipo tipo = (Tipo)(tipoOp - 1);

        int tamOp = menuTamanho();
        if (tamOp == 0) continue;
        int tamanhos[] = {10, 100, 1000, 10000, 100000, 1000000};
        if (tamOp < 1 || tamOp > 6) {
            cout << "opcao invalida\n";
            continue;
        }

        rodarUm(alg, tipo, tamanhos[tamOp - 1]);
    }
}
