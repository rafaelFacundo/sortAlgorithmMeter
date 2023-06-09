#pragma once
#include <random>
#include <iostream>
using namespace std;

class RandomNumbers {
    random_device random_distribution;
    mt19937 generator{random_distribution()};
    
    uniform_int_distribution<> distribution{0,10000000};

    public:
        RandomNumbers(){};
        int generateAnumber() {
            return distribution(generator);
        }

        int generateAnumberInInterval(int maximun) {
            return distribution(generator) % maximun;
        }
};