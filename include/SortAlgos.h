#pragma once
#include "./Instances.h"
#include <math.h>
#include <iostream>
using namespace std;

template <typename T>
void printV(T v[], int tam)
{
    for (int i = 0; i < tam; ++i)
    {
        cout << v[i] << " ";
    }
    cout << '\n';
}

template <typename T>
int takeMaximun(T v[], int indeOne, int indeTwo, int indeThree)
{
    if (v[indeOne] >= v[indeTwo] && v[indeOne] >= v[indeThree])
    {
        return indeOne;
    }
    else if (v[indeTwo] >= v[indeOne] && v[indeTwo] >= v[indeThree])
    {
        return indeTwo;
    }
    else
    {
        return indeThree;
    }
}

template <typename T>
void replaceOrNoFather(T v[], int positionImLooking, int lastInde)
{
    int indeOfMaxi;
    int tempoNumb;
    int fatherPosition = floor((positionImLooking - 1) / 2);
    int sonOnePosi = (2 * fatherPosition) + 1;
    int SonTwoPosi = (2 * fatherPosition) + 2;

    /* cout << "inclui " << v[positionImLooking] << '\n';
    cout << "calculo do pai " << fatherPosition << '\n';
    cout << "o pai dele é " << v[fatherPosition] << '\n'; */

    if (sonOnePosi <= lastInde && SonTwoPosi <= lastInde)
    {
        indeOfMaxi = takeMaximun(v, fatherPosition, sonOnePosi, SonTwoPosi);
        tempoNumb = v[fatherPosition];
        v[fatherPosition] = v[indeOfMaxi];
        v[indeOfMaxi] = tempoNumb;
    }
    else if (v[positionImLooking] > v[fatherPosition])
    {
        tempoNumb = v[fatherPosition];
        v[fatherPosition] = v[positionImLooking];
        v[positionImLooking] = tempoNumb;
    }
}

bool doesThisNodeHaveTwoSons(int fatherPosition, int lastInde)
{
    int sonOnePosi = (2 * fatherPosition) + 1;
    int SonTwoPosi = (2 * fatherPosition) + 2;
    if (sonOnePosi <= lastInde && SonTwoPosi <= lastInde)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
void fixInclusion(T v[], int startInde, int endInde)
{
    int positionImLooking = endInde;
    int fatherPosition = floor((positionImLooking - 1) / 2);
    /*  cout << "na inclusa --- \n";
     cout << "start " << startInde << '\n';
     cout << "end  " << endInde << '\n';
     cout << "inser " << v[positionImLooking] << "na posi " << positionImLooking << '\n';
     cout << "ant \n";
     printV(v, endInde); */
    while (positionImLooking != startInde && v[positionImLooking] > v[fatherPosition])
    {
        replaceOrNoFather(v, positionImLooking, endInde);
        positionImLooking = fatherPosition;
        fatherPosition = floor((positionImLooking - 1) / 2);
    }
    /*  cout << "dep \n";
     printV(v, endInde);
     cout << "saindo --\n"; */
}

template <typename T>
void fixRemotion(T v[], int startInde, int endInde)
{
    int indeBiggest = startInde;
    int indeFather = startInde;
    int sonOne = 2 * indeFather + 1;
    int sonTwo = 2 * indeFather + 2;
    int tempoNum;

    if (sonOne < (endInde + 1) && v[indeBiggest] < v[sonOne])
    {
        indeBiggest = sonOne;
    }
    if (sonTwo < (endInde + 1) && v[indeBiggest] < v[sonTwo])
    {
        indeBiggest = sonTwo;
    }

    if (indeBiggest != indeFather)
    {
        tempoNum = v[indeFather];
        v[indeFather] = v[indeBiggest];
        v[indeBiggest] = tempoNum;
        fixRemotion(v, indeBiggest, endInde);
    }
}

template <typename T>
void createHeap(T v[], int startInde, int endInde)
{
    int positionImLooking = startInde + 1;
    /* cout << "---\n";
    cout << "start " << startInde << '\n';
    cout << "end  " << endInde << '\n';
    cout << "ant \n";
    printV(v, endInde);
    cout << "durante --- \n"; */
    fixInclusion(v, startInde, positionImLooking);
    /* cout << "acavou --- \n";
    cout << "dep \n";
    printV(v, endInde); */
    while (positionImLooking <= endInde)
    {
        fixInclusion(v, startInde, positionImLooking);
        ++positionImLooking;
    }
}

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

template <typename T>
void copyVector(T v1[], T v2[], int start, int end, int jStart)
{
    for (int j = jStart, i = start; i <= end; ++i, ++j)
    {
        v2[j] = v1[i];
    }
}

template <typename T>
void HeapSort(T v[], int startInde, int endInde, int limit = 0)
{

    if (startInde > 0)
    {
        T vec2[(endInde - startInde) + 1];
        copyVector(v, vec2, startInde, endInde, 0);
        HeapSort(vec2, 0, (endInde - startInde));
        copyVector(vec2, v, 0, (endInde - startInde), startInde);
    }
    else
    {
        createHeap(v, startInde, endInde);
        T tempoNum;
        while (startInde != endInde)
        {
            tempoNum = v[endInde];
            v[endInde] = v[startInde];
            v[startInde] = tempoNum;
            fixRemotion(v, startInde, endInde - 1);
            --endInde;
        }
    }
}

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

int pivo(int inicio, int fim)
{
    return (inicio + floor((fim - inicio) / 2));
}

int pivoAletory(int fim)
{
    return generateAnumberInInterval(fim);
}

template <typename T>
int lomutoPartition(T v[], int start, int end, int pivotIndex)
{
    T pivot = v[pivotIndex];
    v[pivotIndex] = v[end];
    v[end] = pivot;
    int biggers = start - 1;
    int smallers = start - 1;
    T tempNum;
    while (biggers < end)
    {
        if (v[biggers + 1] >= pivot)
        {
            ++biggers;
        }
        else
        {
            tempNum = v[biggers + 1];
            v[biggers + 1] = v[smallers + 1];
            v[smallers + 1] = tempNum;
            ++smallers;
            ++biggers;
        }
    }
    tempNum = v[smallers + 1];
    v[smallers + 1] = v[end];
    v[end] = tempNum;
    return (smallers + 1);
}

template <typename T>
void lomutoQuickSort(T v[], int start, int end, int limit = 0)
{
    int pivot = pivo(start, end);
    if (((end - start) + 1) > 1)
    {
        int newPivotInde = lomutoPartition(v, start, end, pivot);
        lomutoQuickSort(v, start, newPivotInde - 1);
        lomutoQuickSort(v, newPivotInde + 1, end);
    }
}

template <typename T>
void lomutoQuickSortWithAleatoryPivot(T v[], int start, int end, int limit = 0)
{
    int pivot = pivoAletory(end);
    if (((end - start) + 1) > 1)
    {
        int newPivotInde = lomutoPartition(v, start, end, pivot);
        lomutoQuickSort(v, start, newPivotInde - 1);
        lomutoQuickSort(v, newPivotInde + 1, end);
    }
}

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

template <typename T>
void InsertionSort(T v[], int start, int end, int stopLimit = 0)
{
    int j;
    T value;
    for (int i = 1; i <= end; ++i)
    {
        value = v[i];
        j = i - 1;
        while (j >= start && v[j] > value)
        {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = value;
    }
}

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

template <typename T, void f(T v[], int start, int end, int stopLimit)>
void introSortRecursion(T v[], int start, int end, double limit, int N)
{
    int pivot = pivo(start, end);
    if (((end - start) + 1) > 1 && limit == N)
    {

        f(v, start, end, limit);
    }

    if (((end - start) + 1) > 1 && N < limit)
    {
        int newPivotInde = lomutoPartition(v, start, end, pivot);

        introSortRecursion<T, f>(v, start, newPivotInde - 1, limit, N + 1);
        introSortRecursion<T, f>(v, newPivotInde + 1, end, limit, N + 1);
    }

    /* if (((end-start) + 1) > 1 && N < limit) {
        int newPivotInde = lomutoPartition(v,start,end,pivot);
        introSortRecursion<T,f>(v,start, newPivotInde-1,limit,N+1);
        introSortRecursion<T,f>(v,newPivotInde+1, end, limit, N+1);
    }else if (((end-start) + 1) > 1 && limit >= N) {
        f(v,start,end, limit);
    } */
}

template <typename T, void f(T v[], int start, int end, int stopLimit)>
void introSortRecursionWithInsertion(T v[], int start, int end, double limit, int N)
{
    int pivot = pivo(start, end);

    if (((end - start) + 1) <= 30)
    {
        InsertionSort(v, start, end, limit);
    }

    else if (((end - start) + 1) > 1 && limit >= N)
    {

        f(v, start, end, limit);
    }

    if (((end - start) + 1) > 1 && N < limit)
    {
        int newPivotInde = lomutoPartition(v, start, end, pivot);
        introSortRecursion<T, f>(v, start, newPivotInde - 1, limit, N + 1);
        introSortRecursion<T, f>(v, newPivotInde + 1, end, limit, N + 1);
    }
}

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

template <typename T>
void introSortWithHeapSort(T v[], int start, int end, int limit = 0)
{
    introSortRecursion<T, HeapSort>(v, start, end, limit, 0);
}

template <typename T>
void introSortWithInsertionSort(T v[], int start, int end, int limit = 0)
{
    introSortRecursionWithInsertion<T, HeapSort>(v, start, end, limit, 0);
}