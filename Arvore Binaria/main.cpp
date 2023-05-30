#include "Fila.h"
#include <iostream>

class Arvore {
private:
  // Propriedade
  Node *raiz;

public:
  // Construtor
  Arvore() { raiz = nullptr; }

  // Prototipo de metodos e funcoes
  Node *pegarRaiz() { return raiz; }
  void criarArvore();
  void insereRaiz(Fila *aux);
  void insereNoEsquerdo(Fila *aux, Node *p);
  void insereNoDireito(Fila *aux, Node *p);
  void PreOrder(){ PreOrder(raiz); } // Passando parametro privado no construtor
  void PreOrder(Node *p);
  void PostOrder(){ PostOrder(raiz); } // Passando parametro privado no construtor
  void PostOrder(Node *p);
  void InOrder(){ InOrder(raiz); } // Passando parametro privado no construtor
  void InOrder(Node *p);
};

void Arvore::criarArvore()
{
  Node *p;
  Fila fila(25);
  int x;

  insereRaiz(&fila);

  while(!fila.vazia())
  {
    p = fila.remove();
    
    insereNoEsquerdo(&fila, p);

    insereNoDireito(&fila, p); 
  }  
}

void Arvore::insereRaiz(Fila *aux)
{
  int x;
  raiz = new Node;

  cout << "Insira o valor da raiz: " << flush;
  cin >> x;

  raiz->valor = x;
  raiz->lchild = nullptr;
  raiz->rchild = nullptr;

  aux->insere(raiz);
}

void Arvore::insereNoEsquerdo(Fila *aux, Node *p)
{
  int x;
  Node *t;

  cout << "Insira o valor do filho esquerdo de " << p->valor << ": " << flush;
  cin >> x;

  if (x != -1)
  {
    t = new Node;
    t->valor = x;
    t->lchild = nullptr;
    t->rchild = nullptr;
    p->lchild = t;
    aux->insere(t);
  }
}

void Arvore::insereNoDireito(Fila *aux, Node *p)
{
  int x;
  Node *t;

  cout << "Insira o valor do filho direito de " << p->valor << ": " << flush;
  cin >> x;

  if (x != -1)
  {
    t = new Node;
    t->valor = x;
    t->lchild = nullptr;
    t->rchild = nullptr;
    p->rchild = t;
    aux->insere(t);
  }
}

void Arvore::PreOrder(Node *p)
{
  if(p)
  {
    cout << p->valor << ", " << flush;
    PreOrder(p->lchild);
    PreOrder(p->rchild);
  }
}

void Arvore::InOrder(Node *p)
{
  if(p)
  {
    InOrder(p->lchild);
    cout << p->valor << ", " << flush;
    InOrder(p->rchild);
  }
}

void Arvore::PostOrder(Node *p)
{
  if(p)
  {
    PostOrder(p->lchild);
    PostOrder(p->rchild);
    cout << p->valor << ", " << flush;
  }
}

int main()
{
  // Criando Arvore Binaria
  Arvore arvoreBinaria;
  arvoreBinaria.criarArvore();

  // Imprimindo arvore binaria
  cout << "PreOrder: " << flush;
  arvoreBinaria.PreOrder();
  cout << endl;

  cout << "InOrder: " << flush;
  arvoreBinaria.InOrder();
  cout << endl;

  cout << "PostOrder: " << flush;
  arvoreBinaria.PostOrder();
  cout << endl;
  return 0;
}