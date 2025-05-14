#include "pilhadinamica.h"
#include <time.h> 

void ordenarComPilha(int vetor[], int tamanho) {
     if (vetor == NULL || tamanho <= 0) {
        printf("Erro: vetor invalido ou tamanho invalido.\n");
        return;
    }
    Pilha pilhaOriginal, pilhaAux;
    criarPilha(&pilhaOriginal);
    criarPilha(&pilhaAux);

    
    for (int i = 0; i < tamanho; i++) {
        empilhar(&pilhaOriginal, vetor[i]);
    }

    
    while (!isEmpty(&pilhaOriginal)) {
        int temp = desempilhar(&pilhaOriginal);

        
        while (!isEmpty(&pilhaAux) && pilhaAux.topo->dado < temp) {
            empilhar(&pilhaOriginal, desempilhar(&pilhaAux));
        }

        empilhar(&pilhaAux, temp);
    }

    
    for (int i = tamanho - 1; i >= 0; i--) {
        vetor[i] = desempilhar(&pilhaAux);
    }

    
    liberarPilha(&pilhaOriginal);
    liberarPilha(&pilhaAux);
}

int main() {
    int vetor[10];

    
    srand((unsigned int)time(NULL));

    printf("Vetor original: ");
    for (int i = 0; i < 10; i++) {
        vetor[i] = rand() % 100;  
        printf("%d ", vetor[i]);
    }
    printf("\n");

    ordenarComPilha(vetor, 10);

    printf("Vetor ordenado com pilha: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
