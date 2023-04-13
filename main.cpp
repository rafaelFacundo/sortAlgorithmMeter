#include "./include/VectorElements.h"
#include "./include/SortAlgos.h"
#include <math.h>
#include <iostream>
using namespace std;




int main () {
    int vt[7] = {5,1,2,3,4,10,5};
    VectorElements<int, 7> testVector{vt};

    testVector.sort<introSortWithHeapSort<int>>(0, 6);

    /* lomutoQuickSort(vt,0,6,0); */    

    testVector.generateInstances('C');

    testVector.printVector();

}