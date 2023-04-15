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
class VectorElements {
    private:
        T** vectors;
        int numberOfInstances;
        int lenOfEachInstance;
        int limit;
    public:
        VectorElements(){};
        VectorElements(int nOfIns, int instLen) : numberOfInstances(nOfIns), lenOfEachInstance(instLen){
            setLimit();
            this->vectors = (int**)(malloc(numberOfInstances * sizeof(int*)));
            for (int i = 0; i < numberOfInstances; ++i) {
                this->vectors[i] = new int[lenOfEachInstance];
            }
        }
        VectorElements(T** vec, int nOfIns, int instLen) : vectors(vec), numberOfInstances(nOfIns), lenOfEachInstance(instLen) {}

        void copyArray(T** vec) {
            for (int j = 0; j < numberOfInstances; ++j) {
                for(int k = 0; k < lenOfEachInstance; ++k) {
                    this->vectors[j][k] = vec[j][k];
                }
            }
        }

        void setLimit() {
            int n = this->lenOfEachInstance;
            this->limit = 0;
            while (n > 1) {
                n = n >> 1;
                ++this->limit;
            }
        }
        
        void printVector(T* v) {
            for(int* i = v; i != (v + this->lenOfEachInstance); ++i) {
                cout << *(i) << " ";
            }
            cout << '\n';
        }

        void printVectors() {
            for(int i = 0; i < this->numberOfInstances; ++i) {
                printVector(this->vectors[i]);
            }
        }

        template<void f(T* vector, int lenght)>
        void generateEachInstances() {
            for (int i = 0; i < this->numberOfInstances; ++i) {
                f(this->vectors[i], this->lenOfEachInstance);
            }
        }

        void generateInstances(const char option) {
            switch (option) {
                case 'A':
                    generateEachInstances<randomInstance>();
                    break;
                case 'C':
                    generateEachInstances<generateAscendingOrder>();
                    break;
                case 'D':
                    generateEachInstances<generateDescendingOrder>();
                    break;
                case 'P':
                    generateEachInstances<gerar_pior_caso>();
                    break;
                
                default:
                    break;
            }
        }

        template<void f(T v[], int begin, int end)>
        duration<double> sort(T vec[], int startIndex, int endIndex) {
            auto begin = steady_clock::now();
            f(vec, startIndex, endIndex);
            auto finish = steady_clock::now();
            return  finish - begin;
        }

        template<void f(T v[], int begin, int end)>
        duration<double> sortEachInstance() {
            duration<double> d;
            for(int i = 0; i < this->numberOfInstances; ++i) {
                d += sort<f>(this->vectors[i], 0, (this->lenOfEachInstance-1));
                
            };
            
            return d;
        }

        duration<double> sortVectors(const char option) {
            duration<double> d;
            switch (option)
            {
            case 'Q':
                d = sortEachInstance<lomutoQuickSort>();
                break;
            case 'H':
                d = sortEachInstance<HeapSort>();
                break;
            case 'I':
                d = sortEachInstance<introSortWithHeapSort>();
            case 'S':
                d = sortEachInstance<introSortWithInsertionSort>();
            default:
                break;
            }
            return d;
        }

        /* bool isItSorted() {
            int *positionImLooking = this->v + (this->len - 1);
            while (positionImLooking != this->v) {
                if (*(positionImLooking-1) > *(positionImLooking))
                    break;
                --positionImLooking;
            }
            if((this->v - positionImLooking) == 0)
                return true;
            else
                return false;
        }
        */



};