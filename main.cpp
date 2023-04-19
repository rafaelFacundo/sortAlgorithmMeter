#include "./include/VectorElements.h"
#include "./include/SortAlgos.h"
#include "./include/RandomNumbers.h"
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
    RandomNumbers ran{};

    VectorElements<int>generateInst{teste, numberOfInstances, vectorLen};
    generateInst.generateInstances(option);
    VectorElements<int>vectorsToSort{numberOfInstances, vectorLen};
    vectorsToSort.copyArray(teste);

     cout << "Quick sort em ação..\n";
    duration<double> quickSortDuration = vectorsToSort.sortVectors('Q');
    vectorsToSort.copyArray(teste);

    cout << "Quick sort com pivot aleatório em ação..\n";
    duration<double> quickSortAleatoryDuration = vectorsToSort.sortVectors('A');
    vectorsToSort.copyArray(teste);

    cout << "Heap sort em ação..\n";
    duration<double> heapSortDuration = vectorsToSort.sortVectors('H');
    vectorsToSort.copyArray(teste);

    cout << "Introsort com heap sort sort em ação..\n";
    duration<double> introHeapSortDuration = vectorsToSort.sortVectors('I');
    vectorsToSort.copyArray(teste);

    cout << "Intro sort com insertion sort em ação..\n";
    duration<double> introInsertionSortDuration = vectorsToSort.sortVectors('S');

    cout << "===========================================\n";

    cout << "AS DURAÇÕES DE CADA ALGORITMO FORAM: \n";
    cout << "Quick sort: " << quickSortDuration.count() << " segundos" << '\n';
    cout << "Quick sort com pivot aleatório: " << quickSortAleatoryDuration.count() << " segundos" << '\n';
    cout << "Heap sort: " << heapSortDuration.count() << " segundos" << '\n';
    cout << "Intro sort com Heap sort: " << introHeapSortDuration.count() << " segundos" << '\n';
    cout << "Intro sort com Insertion sort: " << introInsertionSortDuration.count() << " segundos" << '\n';
    
   /*  int teste2[10] = {1,10,6,0,5,8,1,0,3,0};



    vectorsToSort.sort<HeapSort>(teste2, 2,7);

    cout << "finalizando \n";
    printV(teste2, 10);
    */

}

/* ./programa [Tipo de Instância] [Tamanho do Vetor] [Número de Instâncias] */