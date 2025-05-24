#include "filaDinamica.h"
#include <time.h>

#define TAMANHO 7

int main() {
    srand(time(NULL));

    int vetor[TAMANHO];
    fila f;
    inicializarFila(&f);

    printf("Vetor original: ");
    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = rand() % 10 + 1; 
        printf("%d ", vetor[i]);
        enfileirar(vetor[i], &f);
    }
    printf("\n");

    char* filaAntes = mostrarFila(&f);
    printf("Fila antes da ordenação: %s\n", filaAntes);
    free(filaAntes);

    ordenarFilaRotacionando(&f);

    char* filaDepois = mostrarFila(&f);
    printf("Fila depois da ordenação: %s\n", filaDepois);
    free(filaDepois);

    printf("Vetor ordenado: ");
    for (int i = 0; i < TAMANHO; i++) {
        desenfileirar(&f, &vetor[i]);
        printf("%d ", vetor[i]);
    }
    printf("\n");

    liberarFila(&f);
    return 0;
}