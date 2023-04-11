#include "../include/VectorElements.h"
#include <iostream>
using namespace std;

template<typename T, int n>
VectorElements<T,n>::VectorElements(){};
        
template<typename T, int n>
VectorElements<T,n>::VectorElements(int* numbers): v(numbers) {};

/* T& operator[] (T i){
        
}; */

template<typename T, int n>
int* VectorElements<T,n>::getV() {
    return v;
}

template<typename T, int n>
bool VectorElements<T,n>::isItSorted() {
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

/* template<typename T, int n>
template<void f(T v[], int begin, int end)>
void VectorElements<T,n>::sort<f>(int startIndex, int endIndex) {
    f(this->v, startIndex, endIndex);
} */

template<typename T, int n>
void VectorElements<T,n>::printVector() {
    for(int* i = v; i != (v + this->len); ++i) {
        cout << *(i) << " ";
    }
    cout << '\n';
}