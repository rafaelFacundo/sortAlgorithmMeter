#include "../include/SortAlgos.h"
#include <iostream>
#include <math.h>
using namespace std;


template<typename T>
void fixInclusion(T v[], int startInde, int endInde) {
    int positionImLooking = endInde;
    int fatherPosition = floor((positionImLooking - 1)/2);
    cout << "o pai é: " << v[fatherPosition] << '\n';
}

template<typename T>
void createHeap(T v[], int startInde, int endInde) {
    int positionImLooking = startInde+1;
    while (positionImLooking <= endInde) {
        fixInclusion(v, startInde, positionImLooking);
        ++positionImLooking;
    }
}

template<typename T>
void HeapSort(T v[], int startInde, int endInde) {

}