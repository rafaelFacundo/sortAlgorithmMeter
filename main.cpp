#include "./include/VectorElements.h"
#include "./include/SortAlgos.h"
#include <math.h>
#include <iostream>
using namespace std;

template<typename T>
int takeMaximun(T v[], int indeOne, int indeTwo, int indeThree) {
    if (v[indeOne] >= v[indeTwo] && v[indeOne] >= v[indeThree]) {
        return indeOne;
    }else if (v[indeTwo] >= v[indeOne] && v[indeTwo] >= v[indeThree]) {
        return indeTwo;
    }else {
        return indeThree;
    }
}

template<typename T>
void replaceOrNoFather( T v[], int positionImLooking, int lastInde) {
    int indeOfMaxi;
    int tempoNumb;
    int fatherPosition = floor((positionImLooking - 1)/2);
    int sonOnePosi = (2 * fatherPosition) + 1;
    int SonTwoPosi = (2 * fatherPosition) + 2;

    if (sonOnePosi <= lastInde && SonTwoPosi <= lastInde) {
        indeOfMaxi = takeMaximun(v, fatherPosition, sonOnePosi, SonTwoPosi);
        tempoNumb = v[fatherPosition];
        v[fatherPosition] = v[indeOfMaxi];
        v[indeOfMaxi] = tempoNumb; 
    }else if ( v[positionImLooking] > v[fatherPosition]) {
        tempoNumb = v[fatherPosition];
        v[fatherPosition] = v[positionImLooking];
        v[positionImLooking] = tempoNumb;
    }
    
}

bool doesThisNodeHaveTwoSons(int fatherPosition, int lastInde) {
    int sonOnePosi = (2 * fatherPosition) + 1;
    int SonTwoPosi = (2 * fatherPosition) + 2;
    if (sonOnePosi <= lastInde && SonTwoPosi <= lastInde) {
        return true;
    }else {
        return false;
    }
}

template<typename T>
void fixInclusion(T v[], int startInde, int endInde) {
    int positionImLooking = endInde;
    int fatherPosition = floor((positionImLooking - 1)/2);
    while(v[positionImLooking] != v[startInde] && v[positionImLooking] > v[fatherPosition]) {
        replaceOrNoFather(v, positionImLooking, endInde);
        positionImLooking = fatherPosition;
        fatherPosition = floor((positionImLooking - 1)/2);
    }
}

template<typename T>
void fixRemotion(T v[],int startInde, int endInde ) {
    int indeBiggest = startInde;
    int indeFather = startInde;
    int sonOne = 2 * indeFather + 1;
    int sonTwo = 2 * indeFather + 2;
    int tempoNum;
    

    if (sonOne < (endInde+1) && v[indeBiggest] < v[sonOne]) {
        indeBiggest = sonOne;
    }
    if (sonTwo < (endInde+1) && v[indeBiggest] < v[sonTwo]) {
        indeBiggest = sonTwo;
    }

    if (indeBiggest != indeFather) {
        tempoNum = v[indeFather];
        v[indeFather] = v[indeBiggest];
        v[indeBiggest] = tempoNum;
        fixRemotion(v, indeBiggest, endInde);
    }
}

template<typename T>
void createHeap(T v[], int startInde, int endInde) {
    int positionImLooking = startInde+1;
    fixInclusion(v, startInde, positionImLooking);
    while (positionImLooking <= endInde) {
        fixInclusion(v, startInde, positionImLooking);
        ++positionImLooking;
    }
}

template<typename T>
void printV(T v[], int tam) {
    for (int i = 0; i < tam; ++i) {
        cout << v[i] << " ";
    }
    cout << '\n';
}

template<typename T>
void HeapSort(T v[], int startInde, int endInde) {
    createHeap(v, startInde, endInde);
    T tempoNum;
    while(startInde != endInde) {
        tempoNum = v[endInde];
        v[endInde] = v[startInde];
        v[startInde] = tempoNum;
        fixRemotion(v,startInde, endInde-1);
        --endInde;
    }
}

int pivo(int inicio, int fim) {
    return floor((fim-inicio)/2);
}

template<typename T>
void lomutoPartition(T v[], int start, int end, int pivotIndex) {
    T pivot = v[pivotIndex];
    v[pivotIndex] = v[end];
    v[end] = pivot;
    int biggers = start-1;
    int smallers = start-1;
    T tempNum;
    while (biggers < end) {
        if (v[biggers+1] >= pivot) {
            ++biggers;
        }else {
            tempNum = v[biggers + 1];
            v[biggers+1] = v[smallers+1];
            v[smallers+1] = tempNum;
            ++smallers;
            ++biggers;
        }
    }
    tempNum = v[smallers + 1];
    v[smallers+1] = v[end];
    v[end] = tempNum;
}

template<typename T>
void lomutoQuickSort(T v[], int start, int end) {
    int pivot = pivo(start, end);
    if (end-start > 1)
        lomutoPartition(v,start,end,pivot);
        lomutoQuickSort(v,start, pivot-1);
        lomutoQuickSort(v,pivot+1, end);
}


int main () {
    int vt[7] = {5,1,2,3,4,10,5};
    VectorElements<int, 7> testVector{vt};

    /* testVector.sort<HeapSort<int>>(0, 6); */

    lomutoQuickSort(vt,0,6);

    testVector.printVector();

}