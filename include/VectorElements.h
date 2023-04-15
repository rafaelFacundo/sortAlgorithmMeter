#pragma once
#include "./RandomNumbers.h"
#include "./SortAlgos.h"
#include <iostream>
#include <math.h>
using namespace std;

template <typename T, int n>
class VectorElements {
    private:
        T** v;
        int len = n;
        int currentInclusionIndex = 0;
        RandomNumbers randon{};

        
    public:
        VectorElements(){};
        

        void insertVector(T* numberVector) {
            v[currentInclusionIndex] = numberVector;
            ++currentInclusionIndex;
        }
        
        void printVector(T* v) {
            for(int* i = v; i != (v + this->len); ++i) {
                cout << *(i) << " ";
            }
            cout << '\n';
        }

        void printVectors() {
            int *vectorToPrint;
            for(int i = 0; i < currentInclusionIndex; ++i) {
                printVector(v[i]);
                cout << '\n';
            }
        }

        void piorCasoRecur(T v[], int start, int end, int& num) {
            int pivotIndex = pivo(start, end);
            v[pivotIndex] = num;
            ++num;
            if ((end - start + 1) > 1) {
                piorCasoRecur(v, start, pivotIndex-1, num);
                piorCasoRecur(v, pivotIndex+1, end, num);
            }
        }

        void gerar_pior_caso(T *v, int len) {
            int num = 1;
            piorCasoRecur(v, 0, len-1, num);
        }

        void generateAscendingOrder(T v[], int len) {
            int randomNum = randon.generateAnumber();
            cout << "len é: " << len << '\n';
            for (int i = 0; i < len; ++i) {
                v[i] = ++randomNum;

            }
        }

        void generateDescendingOrder(T v[], int len){
            int randomNum = randon.generateAnumber();
            for (int i = 0; i < len; ++i) {
                v[i] = --randomNum;

            }
        }

        void randomInstance(T *v, int len) {
            for (int i = 0; i < len; ++i) {
                v[i] = randon.generateAnumber();
            }
        }        


        void generateInstances(int numberOfInstances, void (*f)(T*, int)) {
            for (int i = 0; i <= numberOfInstances; ++i) {
                f(v[i], this->len);
            }
        }

        void generateInstances(const char option, int numberOfInstances) {
            switch (option) {
                case 'A':
                    generateInstances(numberOfInstances, );
                    break;
                /* case 'C':
                    generateInstances<generateAscendingOrder>(numberOfInstances);
                    break;
                case 'D':
                    generateInstances<generateDescendingOrder>(numberOfInstances);
                    break;
                case 'P':
                    generateInstances<gerar_pior_caso>(numberOfInstances);
                    break; */
                
                default:
                    break;
            }
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

        template<void f(T v[], int begin, int end)>
        void sort(int startIndex, int endIndex) {
            f(this->v, startIndex, endIndex);
        }

        void printVector() {
            for(int* i = v; i != (v + this->len); ++i) {
                cout << *(i) << " ";
            }
            cout << '\n';
        }

         */




};