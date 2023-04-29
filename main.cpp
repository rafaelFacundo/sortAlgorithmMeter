#include "./include/VectorElements.h"
#include "./include/SortAlgos.h"
#include "./include/RandomNumbers.h"
#include <unordered_map>
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;
using std::atoi;

int main(int argc, char *argv[])
{
    char algOptions[5] = {'A', 'Q', 'H', 'I', 'S'};
    unordered_map<int, duration<double>> algoTimes;
    int numberOfInstances = atoi(argv[3]);
    int vectorLen = atoi(argv[2]);
    char option = *(argv[1]);
    int vectorOfInstances[2][vectorLen];
    RandomNumbers ran{};
    VectorElements<int> algorithmSorter{};

    for (int i = 0; i < numberOfInstances; ++i)
    {
        generateAInstace(vectorOfInstances[0], vectorLen, option);
        for (int alg = 0; alg < 5; ++alg)
        {
            copyArray(vectorOfInstances[0], vectorOfInstances[1], vectorLen);
            algoTimes[alg] += algorithmSorter.sortVector(vectorOfInstances[1], 0, vectorLen - 1, algOptions[alg]);
        }
    }

    /* VectorElements<int>generateInst{teste, numberOfInstances, vectorLen};
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
cout << "Intro sort com Insertion sort: " << introInsertionSortDuration.count() << " segundos" << '\n'; */

    /*  int teste2[10] = {1,10,6,0,5,8,1,0,3,0};



     vectorsToSort.sort<HeapSort>(teste2, 2,7);

     cout << "finalizando \n";
     printV(teste2, 10);
     */
}

/* ./programa [Tipo de Instância] [Tamanho do Vetor] [Número de Instâncias] */