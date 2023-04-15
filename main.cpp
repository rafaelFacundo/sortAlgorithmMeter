#include "./include/VectorElements.h"
#include "./include/SortAlgos.h"
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;
using std::atoi;




int main (int argc, char* argv[]) {
    int numberOfInstances = atoi(argv[3]);
    int vectorLen = atoi(argv[2]);
    char option = *(argv[1]);
    int **teste;
    teste = (int**)(malloc(numberOfInstances * sizeof(int*)));
    for (int i = 0; i < numberOfInstances; ++i) {
        teste[i] = new int[vectorLen];
    }

    VectorElements<int>generateInst{teste, numberOfInstances, vectorLen};
    generateInst.generateInstances(option);
    VectorElements<int>vectorsToSort{numberOfInstances, vectorLen};
    vectorsToSort.copyArray(teste);

    duration<double> quickSortDuration = vectorsToSort.sortVectors('Q');
    vectorsToSort.copyArray(teste);

    duration<double> heapSortDuration = vectorsToSort.sortVectors('H');
    vectorsToSort.copyArray(teste);

    duration<double> introHeapSortDuration = vectorsToSort.sortVectors('I');
    vectorsToSort.copyArray(teste);

    duration<double> introInsertionSortDuration = vectorsToSort.sortVectors('S');

    cout << "AS DURAÇÕES DE CADA ALGORITMO FORAM: \n";
    cout << "Quick sort: " << quickSortDuration.count() << '\n';
    cout << "Heap sort: " << heapSortDuration.count() << '\n';
    cout << "Intro sort com Heap sort: " << introHeapSortDuration.count() << '\n';
    cout << "Intro sort com Insertion sort: " << introInsertionSortDuration.count() << '\n';

    
    
}

/* ./programa [Tipo de Instância] [Tamanho do Vetor] [Número de Instâncias] */