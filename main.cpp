#include "./include/VectorElements.h"
#include "./include/SortAlgos.h"
#include <math.h>
#include <iostream>
using namespace std;




int main () {
    int* vt[3];
    VectorElements<int, 3> testVector{};

    testVector.generateInstances('A', 10);

    testVector.printVectors();

    /* testVector.sort<introSortWithHeapSort<int>>(0, 6); */

    /* lomutoQuickSort(vt,0,6,0); */    

    /* testVector.generateInstances('P');

    testVector.printVector(); */

}