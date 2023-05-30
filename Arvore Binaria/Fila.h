/* Estrutura de fila adaptada para receber nós de arvores binarias */

#include <iostream>
#ifndef Fila_h
#define Fila_h

using namespace std;

class Node {
public:
  Node *lchild;
  Node *rchild;
  int valor;
};

class Fila {
private:
  // Propriedades
  int tamanho;
  int primeiro;
  int ultimo;
  Node **Q;

public:
  // Construtor
  Fila(int tamanho);

  // Desalocar fila
  ~Fila();

  // Prototipo de funcoes e metodos
  bool cheia();
  bool vazia();
  void insere(Node *x);
  Node *remove();
};

Fila::Fila(int tamanho) {
  this->tamanho = tamanho;
  primeiro = -1;
  ultimo = -1;
  Q = new Node *[tamanho];
}

Fila::~Fila() { delete[] Q; }

bool Fila::cheia() {
  if (ultimo == tamanho - 1)
    return true;
  else
    return false;
}

bool Fila::vazia() {
  if (primeiro == ultimo)
    return true;
  else
    return false;
}

void Fila::insere(Node *x) {
  if (cheia())
    cout << "Fila cheia" << endl;
  else {
    ultimo++;
    Q[ultimo] = x;
  }
}

Node *Fila::remove() {
  Node *x = nullptr;
  if (vazia())
    cout << "Fila vazia" << endl;
  else {
    primeiro++;
    x = Q[primeiro];
  }
  return x;
}

#endif