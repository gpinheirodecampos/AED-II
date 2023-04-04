/*
  Algoritmo que analisa dois vetores, o primeiro indica a quantidade de
  microrganismos presente em cada paciente infectado,e o segundo indica a
  potencia de cada dose de remedio. Depois de ordenar os dois vetores com Bubble
  Sort, é realizado uma comparação para poder concluir se a potencia de cada
  dose sera suficiente para curar os infectados.

  Autor: Gabriel Pinheiro de Campos
*/

// ------------- Bibliotecas -------------

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ------------- Prototipos -------------

void bubble_sort(int a[], int tam);
bool compara(int a[], int b[], int tam);

// ------------- Funcao principal -------------

int main(void) {
  // escaneando numero de doses disponiveis
  int n;
  scanf("%d", &n);

  // escaneando quantidade de microrganismos em cada paciente
  int *microrganismos = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    scanf("%d", &microrganismos[i]);

  // escaneando a potencia de cada dose fabricada
  int *potencia = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    scanf("%d", &potencia[i]);

  // ordenando vetor de quantidade de microrganismos
  bubble_sort(microrganismos, n);

  // ordenando vetor de potencia de cada dose fabricada
  bubble_sort(potencia, n);

  // chamando funcao para comparar os dois vetores
  // e criando e inicializando variavel para armazenar o retorno da funcao
  bool suficiente = false;
  suficiente = compara(microrganismos, potencia, n);
  if (suficiente)
    printf("sim\n");
  else
    printf("nao\n");

  return 0;
}

// ------------- Funcao de ordenacao -------------

void bubble_sort(int a[], int tam) {
  int i = 0;
  bool trocou = false;
  do {
    trocou = false;
    for (int j = 0; j < (tam - 1 - i); j++) {
      if (a[j] > a[j + 1]) {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        trocou = true;
      }
    }
    i++;
  } while (trocou);
}

//------------- Funcao de comparacao -------------

// retorna true caso as doses existentes sejam suficientes
// retorna false caso as doses existentes nao sejam suficientes
bool compara(int a[], int b[], int tam) {
  int contador = 0;
  bool suficiente = false;
  for (int i = 0; i < tam; i++) {
    // caso a potencia da dose seja maior ou igual que o numero de
    // microrganismos presentes no corpo do paciente, adicionamos 1 ao contador
    if (b[i] >= a[i])
      contador++;
  }

  // caso o contador seja igual ao tamanho de numero de doses e pacientes (n),
  // entao as doses serao suficientes, logo a funcao retorna true
  // caso contrario, retornar false
  if (contador == tam)
    return true;
  else
    return false;
}

// ------------- Fim -------------