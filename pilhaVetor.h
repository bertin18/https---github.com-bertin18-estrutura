#ifndef PILHAVETOR_H
#define PILHAVETOR_H
#include<iostream>

struct No{
    int dado;
    No* prox;

};

class pilha
{
public:
   pilha(int tamanho);
   ~pilha();
   void push(int valor);
   int pop();
   void exibirPilha();
   int top();
   bool isEmpty();
   bool isFull();

private:
   int *dados;
   int topo;
   int capacidade;
};

pilha::pilha(int tamanho){
    capacidade = tamanho;
    topo = -1;
    dados = new int[tamanho];
    if(dados == nullptr){
        std::cout<< "Memória insuficiente para alocar a pilha." <<std::endl;
    }
}
pilha::~pilha(){
    delete[] dados;
}
void pilha::push(int valor){
    if(isFull()){
        std::cout<< "Pilha cheia!" <<std::endl;
        return;
    }
    dados[++topo] = valor;
    std::cout<<"empilhado"<<std::endl;
    return;
}
int pilha::pop(){
    if(isEmpty()){
        std::cout<< "Pilha vazia!" <<std::endl;
        return -1;
    }
    return dados[topo--];
}
void pilha::exibirPilha(){
    if(topo == -1){
        std::cout<< "Pilha vazia!" <<std::endl;
        return;
    }
    std::cout<<"Elementos da pilha:";
    for(int i = topo; i >= 0; i--){
        std::cout<<dados[i]<<" ";
    }
    std::cout<<std::endl;

}
bool pilha::isEmpty(){
    return topo == -1;
}
bool pilha::isFull(){
    return topo == capacidade - 1;
}
int pilha::top(){
    if(isEmpty()){
        std::cout<< "Pilha vazia!" <<std::endl;
    }
    return dados[topo];
}
#endif