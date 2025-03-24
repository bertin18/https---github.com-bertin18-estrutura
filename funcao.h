#ifndef FUNCAO_H
#define FUNCAO_H
#include <iostream>
#include <stdio.h>
#include<ctime>


class Conjunto
{
public:
    Conjunto() : array(nullptr), tamanho(0){};
    ~Conjunto();
    int obterTamanhoConjunto();
    void gerarConjunto(Conjunto*const pconjunto, int tamanho);
    void mostrarConjunto(Conjunto const *const pconjunto);
    int buscarSequencialAprimorada( int elemento);
    void ordenacaoSelectionSort();
    int buscaBinaria(int elemento);
    int* array;
    int tamanho;

};
Conjunto::~Conjunto(){
    delete[] array;
}

int Conjunto::obterTamanhoConjunto(){
    int tamanho =0;
    do{
        std::cout << "Digite o tamanho do conjunto: ";
        std::cin >> tamanho;
        if(tamanho <= 0 ){
            std::cout<<"Erro: o tamanho deve ser maior que 0.";
        }
        }while(tamanho <= 0);
        return tamanho;
    
}

void Conjunto::gerarConjunto(Conjunto*const pconjunto, int tamanho){
    pconjunto->tamanho = tamanho;
    delete[] pconjunto->array;
    pconjunto->array = new int[tamanho];
    srand(time(0));
    for (int i = 0; i < tamanho; i++)
    {
        pconjunto->array[i] = rand() % 1001;
    }
}

void Conjunto::mostrarConjunto(Conjunto const *const pconjunto){
    std::cout<<"conjunto gerado: [";
    for (int i = 0; i < pconjunto->tamanho; i++){
        std::cout<<pconjunto->array[i]<<", ";
    }
    std::cout<<"]"<<std::endl;
}

int Conjunto::buscarSequencialAprimorada(int elemento){
    ordenacaoSelectionSort();
    for (int i = 0; i < tamanho; i++)
    {
        if (array[i] > elemento )
        {
            break;
        }
        if (array[i]== elemento)
        {
            return i;
        }
        
    }
    return -1;
    
}

void Conjunto::ordenacaoSelectionSort(){
    for(int i = 0; i < tamanho - 1; i++ ){
        int menor = i;
        for (int j = i + 1; j < tamanho; j++)
        {
            if (array[j] < array[menor])
            {
                menor = j;
            }
            
        }
        std::swap(array[i], array[menor]);
    }
    
}

int Conjunto::buscaBinaria(int elemento){
    ordenacaoSelectionSort();
    int low = 0;
    int high = tamanho - 1;
    while (low <= high)     
    {
        int mid =(low + high)/2;
        if(array[mid]== elemento){
            return mid;
        }
        if(array[mid] < elemento){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
    
}
#endif