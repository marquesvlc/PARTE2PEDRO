#ifndef ORDENADOR_H
#define ORDENADOR_H

#include <vector>
#include <string>
using namespace std;

enum Algoritmo { INSERTION, SELECTION, SHELL, BUBBLE };

class Ordenador {
public:
    double ordenar(vector<int> &vet, Algoritmo alg);

private:
    void insertionSort(vector<int> &vet);
    void selectionSort(vector<int> &vet);
    void bubbleSort(vector<int> &vet);
    void shellSort(vector<int> &vet);
};

string nomeAlgoritmo(Algoritmo a);

#endif
