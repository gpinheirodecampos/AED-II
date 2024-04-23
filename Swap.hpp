#include <iostream>
#include <fstream>
#ifndef Swap_h
#define Swap_h
using namespace std;

inline void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

#endif