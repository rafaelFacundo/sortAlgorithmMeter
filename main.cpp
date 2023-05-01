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
    VectorElements<int> algorithmSorter{numberOfInstances, vectorLen};

    for (int i = 0; i < numberOfInstances; ++i)
    {
        generateAInstace(vectorOfInstances[0], vectorLen, option);
        cout << "Instância de número " << (i + 1) << " gerada.\n";
        for (int alg = 0; alg < 5; ++alg)
        {
            copyArray(vectorOfInstances[0], vectorOfInstances[1], vectorLen);
            algoTimes[alg] += algorithmSorter.sortVector(vectorOfInstances[1], 0, vectorLen - 1, algOptions[alg]);
        }
    }

    cout << "== TEMPO GASTO POR CADA ALGORITMO == \n";
    cout << "== Quick sort com pivô aleatório -- " << algoTimes[0].count() << " seg" << '\n';
    cout << "== Quick sort com pivô fixo ------- " << algoTimes[1].count() << " seg" << '\n';
    cout << "== Heap sort ---------------------- " << algoTimes[2].count() << " seg" << '\n';
    cout << "== Intro sort --------------------- " << algoTimes[3].count() << " seg" << '\n';
    cout << "== Intro sort com Insertion sort -- " << algoTimes[4].count() << " seg" << '\n';
}

/* ./programa [Tipo de Instância] [Tamanho do Vetor] [Número de Instâncias] */