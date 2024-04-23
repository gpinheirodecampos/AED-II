#include <iostream>
#include <fstream>
#include "Imprime.hpp"
#include "Swap.hpp"
#include "Selection_Sort.hpp"
#include "Bubble_Sort.hpp"
#include "Insertion_Sort.hpp"
using namespace std;

int main()
{
    int size;

    ifstream input("input.txt");

    if (!input.is_open()) {
        cout << "Erro ao abrir o arquivo de entrada." << endl;
        return 1;
    }

    input >> size; // Lê o tamanho do array

    // Cria novo array
    int *array = new int[size];

    // Lê os valores do array do arquivo de entrada
    for (int i = 0; i < size; i++) {
        input >> array[i];
    }

    cout << "Array antes da ordenação" << endl;

    // Faz o processamento necessário
    // Neste exemplo, apenas imprime o array
    imprime(array, size);

    selection_sort(array, size);

    cout << "Array depois da ordenação" << endl;

    imprime(array, size);

    // Fecha o arquivo de entrada
    input.close();

    return 0;
}

