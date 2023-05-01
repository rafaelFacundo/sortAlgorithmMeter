#pragma once
#include "./RandomNumbers.h"
#include "./SortAlgos.h"
#include "./Instances.h"
#include <chrono>
#include <iostream>
#include <math.h>
using namespace std;
using namespace chrono;

template <typename T>
class VectorElements
{
private:
    int numberOfInstances;
    int lenOfEachInstance;
    int limit;

public:
    void setLimit()
    {
        int n = this->lenOfEachInstance;
        this->limit = 0;
        while (n > 1)
        {
            n = n >> 1;
            ++this->limit;
        }
    }

    VectorElements(){};

    VectorElements(int nOfIns, int instLen) : numberOfInstances(nOfIns), lenOfEachInstance(instLen)
    {
        setLimit();
    }

    ~VectorElements() {}

    void printVector(T *v, int len)
    {
        for (int *i = v; i != (v + len); ++i)
        {
            cout << *(i) << " ";
        }
        cout << '\n';
    }

    template <void f(T v[], int begin, int end, int stopLimit)>
    duration<double> sort(T vec[], int startIndex, int endIndex)
    {
        auto begin = steady_clock::now();
        f(vec, startIndex, endIndex, this->limit);
        auto finish = steady_clock::now();
        if (!(this->isItSorted(vec, endIndex + 1)))
        {
            cout << "erro\n";
            this->printVector(vec, endIndex + 1);
        }
        return finish - begin;
    }

    duration<double> sortVector(T v[], int startInde, int EndInde, const char option)
    {

        duration<double> d;
        switch (option)
        {
        case 'A':
            cout << "== Quick sort com pivô aleatório está ordenando a instância ==\n";
            d = sort<lomutoQuickSortWithAleatoryPivot>(v, startInde, EndInde);
            break;
        case 'Q':
            cout << "== Quick sort com pivô fixo está ordenando a instância ==\n";
            d = sort<lomutoQuickSort>(v, startInde, EndInde);
            break;
        case 'H':
            cout << "== Heap Sort está ordenando a instância ==\n";
            d = sort<HeapSort>(v, startInde, EndInde);
            break;
        case 'I':
            cout << "== Intro está ordenando a instância ==\n";
            d = sort<introSortWithHeapSort>(v, startInde, EndInde);
        case 'S':
            cout << "== Intro sort com Insertion sort está ordenando a instância ==\n";
            d = sort<introSortWithInsertionSort>(v, startInde, EndInde);
        default:
            break;
        }
        return d;
    }

    bool isItSorted(T v[], int len)
    {
        int *positionImLooking = v + (len - 1);
        while (positionImLooking != v)
        {
            if (*(positionImLooking - 1) > *(positionImLooking))
                break;
            --positionImLooking;
        }
        if ((v - positionImLooking) == 0)
            return true;
        else
            return false;
    }
};