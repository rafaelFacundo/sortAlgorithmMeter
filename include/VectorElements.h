#pragma once
#include <iostream>
using namespace std;

template <typename T, int n>
class VectorElements {
    private:
        T* v;
        int len = n;
    public:
        VectorElements(){};
        
        VectorElements(int* numbers): v(numbers) {};
        
        /* T& operator[] (T i){
             
        }; */

        int* getV() {
            return v;
        }

        bool isItSorted() {
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

        template<void f(T v[], int begin, int end)>
        void sort(int startIndex, int endIndex) {
            f(this->v, startIndex, endIndex);
        }

        void printVector() {
            for(int* i = v; i != (v + this->len); ++i) {
                cout << *(i) << " ";
            }
            cout << '\n';
        }




};