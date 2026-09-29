#include "ordenador.h"
#include <ctime>

double Ordenador::ordenar(vector<int> &vet, Algoritmo alg) {
    clock_t ini = clock();

    if (alg == INSERTION) insertionSort(vet);
    else if (alg == SELECTION) selectionSort(vet);
    else if (alg == SHELL) shellSort(vet);
    else bubbleSort(vet);

    clock_t fim = clock();
    return (double)(fim - ini) / CLOCKS_PER_SEC;
}

void Ordenador::insertionSort(vector<int> &vet) {
    int n = vet.size();
    for (int i = 1; i < n; i++) {
        int chave = vet[i];
        int j = i - 1;
        while (j >= 0 && vet[j] > chave) {
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = chave;
    }
}

void Ordenador::selectionSort(vector<int> &vet) {
    int n = vet.size();
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (vet[j] < vet[menor])
                menor = j;
        }
        if (menor != i) {
            int temp = vet[i];
            vet[i] = vet[menor];
            vet[menor] = temp;
        }
    }
}

void Ordenador::bubbleSort(vector<int> &vet) {
    int n = vet.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (vet[j] > vet[j+1]) {
                int temp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
            }
        }
    }
}

void Ordenador::shellSort(vector<int> &vet) {
    int n = vet.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = vet[i];
            int j = i;
            while (j >= gap && vet[j-gap] > temp) {
                vet[j] = vet[j-gap];
                j -= gap;
            }
            vet[j] = temp;
        }
    }
}

string nomeAlgoritmo(Algoritmo a) {
    if (a == INSERTION) return "Insertion Sort";
    if (a == SELECTION) return "Selection Sort";
    if (a == SHELL) return "Shell Sort";
    return "Bubble Sort";
}
