#include <iostream>
#include <fstream>
#ifndef Imprime_h
#define Imprime_h
using namespace std;

inline void imprime(int* array, int n)
{
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

#endif