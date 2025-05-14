#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Estrutura de um nó da pilha
typedef struct No {
    int dado;
    struct No* proximo;
} No;

// Estrutura da pilha
typedef struct {
    No* topo;
} Pilha;


void criarPilha(Pilha * P){
    P->topo = NULL;
}

int isEmpty(const Pilha* p) {
    return p->topo == NULL;
}

void empilhar(Pilha* p, int valor){
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao.\n");
        return;
    }
    novo->dado = valor;
    novo->proximo = p->topo; 
    p->topo = novo;
    
}

int desempilhar(Pilha *const p){
    if (isEmpty(p)) {
        printf("Pilha vazia.\n");
        return -1;
    }
    No* temp = p->topo;
    int valor = temp->dado;
    p->topo = temp->proximo;
    free(temp);
    
    return valor;
}


#define MAX_SIZE 100  // Definindo um tamanho máximo para a string de retorno

char* imprimir(const Pilha *const p) {
    // Alocando espaço para a string de saída
    char* resultado = (char*)malloc(MAX_SIZE * sizeof(char));
    if (resultado == NULL) {
        printf("Erro de alocação de memória.\n");
        return NULL;
    }

    // Inicializando a string
    resultado[0] = '\0';

    const No* atual = p->topo;
    while (atual != NULL) {
        // Adicionando o valor do nó à string
        char buffer[20];  // Usado para armazenar temporariamente o número convertido
        snprintf(buffer, sizeof(buffer), "%d ", atual->dado);  // Formata o número
        strcat(resultado, buffer);  // Concatena na string final
        atual = atual->proximo;
    }

    // Retorna a string com a representação da pilha
    return resultado;
}

void liberarPilha(Pilha* const p) {
    if (p == NULL) return; 

    No* atual = p->topo;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    p->topo = NULL; 
    printf("Pilha liberada com sucesso.\n");
}