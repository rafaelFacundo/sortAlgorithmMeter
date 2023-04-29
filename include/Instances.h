#pragma once
#include <iostream>
#include <math.h>
#include "./RandomNumbers.h"
using namespace std;

RandomNumbers randon{};

int pivo2(int inicio, int fim)
{
    return (inicio + floor((fim - inicio) / 2));
}

template <typename T>
void piorCasoRecur(T v[], int start, int end, int &num)
{
    int pivotIndex = pivo2(start, end);
    v[pivotIndex] = num;
    ++num;
    if ((end - start + 1) > 1)
    {
        piorCasoRecur(v, start, pivotIndex - 1, num);
        piorCasoRecur(v, pivotIndex + 1, end, num);
    }
}

template <typename T>
void gerar_pior_caso(T *v, int len)
{
    int num = 1;
    piorCasoRecur(v, 0, len - 1, num);
}

template <typename T>
void generateAscendingOrder(T v[], int len)
{
    int randomNum = randon.generateAnumber();
    for (int i = 0; i < len; ++i)
    {
        v[i] = ++randomNum;
    }
}

template <typename T>
void generateDescendingOrder(T v[], int len)
{
    int randomNum = randon.generateAnumber();
    for (int i = 0; i < len; ++i)
    {
        v[i] = --randomNum;
    }
}

template <typename T>
void randomInstance(T *v, int len)
{
    for (int i = 0; i < len; ++i)
    {
        v[i] = randon.generateAnumber();
    }
}

int generateAnumberInInterval(int limit)
{
    return randon.generateAnumberInInterval(limit);
}

template <typename T>
void generateAInstace(T *v, int len, const char option)
{
    switch (option)
    {
    case 'A':
        randomInstance(v, len);
        break;
    case 'C':
        generateAscendingOrder(v, len);
        break;
    case 'D':
        generateDescendingOrder(v, len);
        break;
    case 'P':
        gerar_pior_caso(v, len);
        break;
    default:
        cout << "Entrada inválida\n";
        break;
    }
}

template <typename T>
void copyArray(T v1[], T v2[], int arrayLen)
{
    for (int i = 0; i < arrayLen; ++i)
    {
        v2[i] = v1[i];
    }
}