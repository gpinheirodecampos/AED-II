#include <iostream>
#include <fstream>
#include "Swap.hpp"
#include "Imprime.hpp"
#ifndef Bubble_Sort_h
#define Bubble_Sort_h
using namespace std;

inline void bubble_sort(int* array, int n)
{
    bool flag;

    for (int i = 0; i < n - 1; i++)
    {
        flag = false;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                imprime(array, n);

                flag = true;
            }
        }

        if (!flag)
            break;
    }
}

#endif