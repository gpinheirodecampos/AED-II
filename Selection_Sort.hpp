#include <iostream>
#include <fstream>
#include "Swap.hpp"
#include "Imprime.hpp"
#ifndef Selection_Sort_h
#define Selection_Sort_h
using namespace std;

inline void selection_sort(int* array, int n)
{
	int k;

	for (int i = 0; i < n - 1; i++)
	{
		k = i;

		for (int j = i + 1; j < n; j++)
		{
			if (array[j] < array[k])
				k = j;
		}

		if (k != i)
		{
			swap(&array[i], &array[k]);
			imprime(array, n);
		}
	}
}

#endif