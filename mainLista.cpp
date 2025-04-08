#include "ListaVetor.h"

int main(void){
    ListaVetor listaTeste;
    // Primeiro teste sujeira
    mostrarDadosLista(&listaTeste);
    // Criar lista
    criarListaVetor(&listaTeste, 5);
    mostrarDadosLista(&listaTeste);
    for (int cont = 0; cont <= 5; cont++)
    {
        if (inserirFimLista(&listaTeste, cont))
        {
            std::cout << "Elemento inserido: " << "\n";
        }
        else
        {
            std::cout << "Erro ao inserir elemento: " << cont * 10 << "\n";
        }
    }
    
    liberarListaVetor(&listaTeste);
   
}