#include <iostream>
#include <fstream>
#include "Imprime.hpp"
#ifndef Insertion_Sort_h
#define Insertion_Sort_h
using namespace std;

inline void insertion_sort(int* array, int n)
{
    int x, j;

    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        x = array[i];

        while (j > -1 && array[j] > x)
        {
            array[j + 1] = array[j];
            imprime(array, n);
            j--;
        }

        array[j + 1] = x;
        imprime(array, n);
    }
}

#endif