#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int tamanho;
    int quantidadeDeElementos;
    int *array;
} TLista;


void criarLista(int tamanho, TLista *const lista) {
    lista->tamanho = tamanho;
    lista->quantidadeDeElementos = 0;
    lista->array = (int *) malloc(tamanho * sizeof(int));
}


void liberarLista(TLista *const lista) {
    free(lista->array);
    lista->array = NULL;
    lista->tamanho = 0;
    lista->quantidadeDeElementos = 0;
}


int listaEstaVazia(TLista const *const lista) {
    return lista->quantidadeDeElementos == 0;
}


int listaEstaCheia(TLista const *const lista) {
    return lista->quantidadeDeElementos == lista->tamanho;
}


int inserirFimLista(TLista *const lista, int elemento) {
    if (listaEstaCheia(lista)) return 0;
    lista->array[lista->quantidadeDeElementos++] = elemento;
    return 1;
}


int removerFimLista(TLista *const lista) {
    if (listaEstaVazia(lista)) return 0;
    lista->quantidadeDeElementos--;
    return 1;
}


int inserirInicioLista(TLista *const lista, int elemento) {
    if (listaEstaCheia(lista)) return 0;
    for (int i = lista->quantidadeDeElementos; i > 0; i--) {
        lista->array[i] = lista->array[i - 1];
    }
    lista->array[0] = elemento;
    lista->quantidadeDeElementos++;
    return 1;
}


int removerInicioLista(TLista *const lista) {
    if (listaEstaVazia(lista)) return 0;
    for (int i = 0; i < lista->quantidadeDeElementos - 1; i++) {
        lista->array[i] = lista->array[i + 1];
    }
    lista->quantidadeDeElementos--;
    return 1;
}


int removerElementoLista(TLista *const lista, int elemento) {
    if (listaEstaVazia(lista)) return 0;

    int posicao = -1;
    for (int i = 0; i < lista->quantidadeDeElementos; i++) {
        if (lista->array[i] == elemento) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) return 0; 

    for (int i = posicao; i < lista->quantidadeDeElementos - 1; i++) {
        lista->array[i] = lista->array[i + 1];
    }

    lista->quantidadeDeElementos--;
    return 1;
}

// Função que insere um elemento de forma ordenada na lista
int inserirOrdenadoLista(TLista *const lista, int elemento) {
    if (listaEstaCheia(lista)) {
        return 0; 
    }

    int i = lista->quantidadeDeElementos - 1;

    // Desloca os elementos maiores que o novo para frente
    while (i >= 0 && lista->array[i] > elemento) {
        lista->array[i + 1] = lista->array[i];
        i--;
    }

    // Insere o novo elemento na posição correta
    lista->array[i + 1] = elemento;
    lista->quantidadeDeElementos++;
    return 1; 
}

void exibirLista(TLista const *lista) {
    printf("Lista: ");
    for (int i = 0; i < lista->quantidadeDeElementos; i++) {
        printf("%d ", lista->array[i]);
    }
    printf("\n");
}