/*
  Programa que utiliza busca binaria para encontrar um
  determinado valor em um vetor de inteiros alocado dinamicamente

  Autor: Gabriel Pinheiro de Campos
*/

/*------------ Bibliotecas Externas ------------*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
  Prototipo de funcao que recebe como parametros o vetor ordenado,
  o elemento a ser pesquisado, o index do primeiro elemento a esquerda,
  e o index do ultimo elemento a direita
*/
bool busca_binaria(int a[], int e, int l, int r, int *count);

/**/
int main(void) {
  // variavel do elemento a ser pesquisado
  int elemento;

  // variavel para verificarmos se o valor a ser pesquisado existe
  bool achou = false;

  // recebendo o tamanho do vetor
  int tamanho;
  scanf("%d", &tamanho);

  // alocando dinamicamente o vetor
  int *ordenada = (int *)malloc(tamanho * sizeof(int));

  // variavel usada para controlar quantas vezes a funcao recursiva sera usada
  int contador = 0;

  // recebendo os valores do vetor
  for (int i = 0; i < tamanho; i++)
    scanf("%d", &ordenada[i]);

  // recebendo o valor a ser pesquisado no vetor
  scanf("%d", &elemento);

  achou = busca_binaria(ordenada, elemento, 0, 4, &contador);

  if (achou)
    printf("%d\n", contador);
  else
    printf("%d nao foi encontrado\n", elemento);

  return 0;
}

bool busca_binaria(int a[], int e, int l, int r, int *count) {
  int meio = l + (r - l) / 2;

  /*
    caso o valor a ser pesquisado no vetor nao exista, chegara um momento que
    o lado esquerdo do vetor sera maior que o direito, e se isso acontecer
    vamos retornar false
  */
  if (l > r)
    return false;

  if (a[meio] == e) {
    return true;
  } else if (a[meio] > e) {
    (*count)++;
    return busca_binaria(a, e, l, meio - 1, count);
  } else {
    (*count)++;
    return busca_binaria(a, e, meio + 1, r, count);
  }
}