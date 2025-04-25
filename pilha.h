#include <iostream>

#include "nodeInt.h"
class pilha
{
private:
    Node *top = nullptr;
public:
    pilha();
    ~pilha();
    void push(pilha *const p, int valor);
    int pop(pilha *const p);
    char * mostrarPliha(pilha const * const p);
};

pilha::pilha()
{
}

pilha::~pilha()
{
    free(dado);
    free(top);
}

void push(pilha *const p, int valor)
{
  if(p->top == nullptr){
    p->top = new Node(valor);
  }
  else{
    Node *novo = new Node(valor, p->top);
    p->top = novo;
   
  }
}

int pop(pilha *const p)
{
    if (p->top == nullptr)
    {
        std::cout << "Pilha vazia\n";
        return -1;
    }
    else
    {
        int valor = *(p->dado + *(p->top));
        *(p->top) -= 1;
        return valor;
    }
}