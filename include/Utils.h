#pragma once
#include <iostream>
#include <math.h>
using namespace std;

int pivo2(int inicio, int fim) {
    return ( inicio + floor((fim-inicio)/2) );
}

template<typename T>
void piorCasoRecur(T v[], int start, int end, int& num) {
    int pivotIndex = pivo2(start, end);
    v[pivotIndex] = num;
    ++num;
    if ((end - start + 1) > 1) {
        piorCasoRecur(v, start, pivotIndex-1, num);
        piorCasoRecur(v, pivotIndex+1, end, num);
    }
}


template<typename T>
void gerar_pior_caso(T *v, int len) {
    int num = 1;
    piorCasoRecur(v, 0, len-1, num);
}

template<typename T>
void generateAscendingOrder(T v[], int len) {
    int randomNum = randon.generateAnumber();
    cout << "len é: " << len << '\n';
    for (int i = 0; i < len; ++i) {
        v[i] = ++randomNum;

    }
}

template<typename T>
void generateDescendingOrder(T v[], int len){
    int randomNum = randon.generateAnumber();
    for (int i = 0; i < len; ++i) {
        v[i] = --randomNum;

    }
}

template<typename T>
void randomInstance(T *v, int len) {
    for (int i = 0; i < len; ++i) {
        v[i] = randon.generateAnumber();
    }
}        


template<typename T, void f(T* vector, int lenght)>
void generateInstances(int numberOfInstances) {
    for (int i = 0; i <= numberOfInstances; ++i) {
        f(v[i], this->len);
    }
}