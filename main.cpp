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
void createHeap(T v[], int startInde, int endInde) {
    int positionImLooking = startInde+1;
    fixInclusion(v, startInde, positionImLooking);
    while (positionImLooking <= endInde) {
        fixInclusion(v, startInde, positionImLooking);
        ++positionImLooking;
    }
}

template<typename T>
void HeapSort(T v[], int startInde, int endInde) {
    createHeap(v, startInde, endInde);
}

int main () {
    int vt[5] = {5,1,2,3,4};
    VectorElements<int, 5> testVector{vt};




    testVector.sort<createHeap<int>>(0, 4);

    for (int i = 0; i < 5; ++i) {
        cout << testVector.getV()[i] << '\n';
    }

}