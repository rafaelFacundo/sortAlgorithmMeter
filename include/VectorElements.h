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
    T **vectors;
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
        this->vectors = (int **)(malloc(numberOfInstances * sizeof(int *)));
        for (int i = 0; i < numberOfInstances; ++i)
        {
            this->vectors[i] = new int[lenOfEachInstance];
        }
    }
    VectorElements(T **vec, int nOfIns, int instLen) : vectors(vec), numberOfInstances(nOfIns), lenOfEachInstance(instLen) {}

    ~VectorElements()
    {
        for (int i = 0; i < numberOfInstances; ++i)
        {
            delete this->vectors[i];
        }
        delete this->vectors;
    }

    void copyArray(T **vec)
    {
        for (int j = 0; j < numberOfInstances; ++j)
        {
            for (int k = 0; k < lenOfEachInstance; ++k)
            {
                this->vectors[j][k] = vec[j][k];
            }
        }
    }

    void printVector(T *v)
    {
        for (int *i = v; i != (v + this->lenOfEachInstance); ++i)
        {
            cout << *(i) << " ";
        }
        cout << '\n';
    }

    void printVectors()
    {
        for (int i = 0; i < this->numberOfInstances; ++i)
        {
            printVector(this->vectors[i]);
        }
    }

    template <void f(T *vector, int lenght)>
    void generateEachInstances()
    {
        for (int i = 0; i < this->numberOfInstances; ++i)
        {
            f(this->vectors[i], this->lenOfEachInstance);
        }
    }

    template <void f(T v[], int begin, int end, int stopLimit)>
    duration<double> sort(T vec[], int startIndex, int endIndex)
    {
        auto begin = steady_clock::now();
        f(vec, startIndex, endIndex, this->limit);
        auto finish = steady_clock::now();
        if (!(this->isItSorted(vec)))
        {
            cout << "erro\n";
            this->printVector(vec);
        }
        return finish - begin;
    }

    template <void f(T v[], int begin, int end, int stopLimit)>
    duration<double> sortEachInstance()
    {
        duration<double> d;
        for (int i = 0; i < this->numberOfInstances; ++i)
        {
            d += sort<f>(this->vectors[i], 0, (this->lenOfEachInstance - 1));
        };

        return d;
    }

    duration<double> sortVector(T v[], int startInde, int EndInde, const char option)
    {
        duration<double> d;
        switch (option)
        {
        case 'A':
            d = sort<lomutoQuickSortWithAleatoryPivot>(v, startInde, EndInde);
            break;
        case 'Q':
            d = sort<lomutoQuickSort>(v, startInde, EndInde);
            break;
        case 'H':
            d = sort<HeapSort>(v, startInde, EndInde);
            break;
        case 'I':
            d = sort<introSortWithHeapSort>(v, startInde, EndInde);
        case 'S':
            d = sort<introSortWithInsertionSort>(v, startInde, EndInde);
        default:
            break;
        }
        return d;
    }

    bool isItSorted(T v[])
    {
        int *positionImLooking = v + (this->lenOfEachInstance - 1);
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