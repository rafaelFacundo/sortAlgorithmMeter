#pragma once
#include "./RandomNumbers.h"
#include <iostream>
#include <math.h>
using namespace std;

template <typename T, int n>
class VectorElements {
    private:
        T* v;
        int len = n;
        RandomNumbers randon{};

        
    public:
        VectorElements(){};
        
        VectorElements(int* numbers): v(numbers) {};
        
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


        void gerar_pior_caso(T *v, int len) {
            int pivotIndex = floor((fim)/2);
            
        }

        void generateAscendingOrder(T v[], int len) {
            int randomNum = randon.generateAnumber();
            cout << "len é: " << len << '\n';
            for (int i = 0; i < len; ++i) {
                v[i] = ++randomNum;

            }
        }

        void generateDescendingOrder(T v[], int len){
            int randomNum = randon.generateAnumber();
            for (int i = 0; i < len; ++i) {
                v[i] = --randomNum;

            }
        }

        void randomInstance(T *v, int len) {
            for (int i = 0; i < len; ++i) {
                v[i] = randon.generateAnumber();
            }
        }        


        void generateInstances(const char option) {
            switch (option)
            {
            case 'A':
                randomInstance(this->v,this->len);
                break;
            case 'C':
                generateAscendingOrder(this->v,this->len);
                break;
            case 'D':
                generateDescendingOrder(this->v,this->len);
                break;
            case 'P':
                gerar_pior_caso(this->v, this->len);
                break;
            
            default:
                break;
            }
        }




};