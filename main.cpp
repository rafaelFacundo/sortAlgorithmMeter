#include "./include/VectorElements.h"
#include <iostream>
using namespace std;

int main () {
    int vt[5] = {1,2,3,4,5};
    VectorElements<int, 5> testVector{vt};

    cout << "primeiro: " << testVector.teste() << '\n';

    cout << "tamanho: " << testVector.tamanho() << '\n';
}