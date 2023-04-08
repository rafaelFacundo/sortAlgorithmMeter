#pragma once

template <typename T, int n>
class VectorElements {
    private:
        T* v;
        int len = n;
    public:
        VectorElements(){};
        
        VectorElements(int* numbers): v(numbers) {};
        T& operator[] (T i){};

        T teste(){return *(v);};

        int tamanho() {return len;}
};