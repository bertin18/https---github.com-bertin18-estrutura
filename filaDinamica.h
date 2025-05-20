#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct fila {
    struct No* inicio;
    struct No* fim;
    int tamanho;
    
    
} fila;

void inicializarFila(fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

No * criarNo(int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memoria para o novo no.\n");
        exit(1);
    }
    novoNo->dado = dado;
    novoNo->proximo = NULL;
    return novoNo;
}

int estaVazia(fila const * const f) {
    return f->inicio == NULL;
}

int enfileirar(int dado, fila *const f) {
    No* novoNo = criarNo(dado);
    if (novoNo == NULL) {
        return 0; // Falha 
    }
    if (estaVazia(f)) {
        f->inicio = novoNo;
        f->fim = novoNo;
    f->tamanho++;
        return 1; // Sucesso
    } 

    f->fim->proximo = novoNo;
    
    f->fim = novoNo;
    f->tamanho++;
    return 1; // Sucesso
}

int desenfileirar(fila* f, int* valorRemovido) {
    if (estaVazia(f)) return 0;
    No* temp = f->inicio;
    *valorRemovido = temp->dado;
    f->inicio = f->inicio->proximo;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(temp);
    f->tamanho--;
    return 1;
}

char* mostrarFila( fila const * const f) {
    char* str = (char*)malloc(1024);
    if (str == NULL) {
        printf("Erro ao alocar memória para a string.\n");
        exit(1);
    }

    
    if (estaVazia(f)) {
        snprintf(str, 1024, "{VAZIA}");
        return str;
    }

    snprintf(str, 1024, "%d  Elementos: {", f->tamanho);

    No* atual = f->inicio;
    while (atual != NULL) {
        char buffer[32];
        snprintf(buffer, sizeof(buffer), "%d ", atual->dado);
        strcat(str, buffer);
        atual = atual->proximo;
    }
    strcat(str, "}");
    return str;
}

void liberarFila(fila* f) {
    No* atual = f->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}
void ordenarFilaRotacionando(fila* f) {
    if (estaVazia(f)) return;

    int n = f->tamanho;

    for (int i = 0; i < n; i++) {
        int aux = INT_MAX;
        int atual;

        
        for (int j = 0; j < n; j++) {
            desenfileirar(f, &atual);

            
            if (j < n - i && atual < aux) {
                aux = atual;
            }

            
            enfileirar(atual, f);
        }

        
        int encontrado = 0;
        for (int j = 0; j < n; j++) {
            desenfileirar(f, &atual);

            if (atual == aux && !encontrado && j < n - i) {
                encontrado = 1; 
            } else {
                enfileirar(atual, f);
            }
        }

        enfileirar(aux, f);
    }

    // Rotacionar para que os menores fiquem no início
    for (int i = 0; i < n; i++) {
        int temp;
        desenfileirar(f, &temp);
        enfileirar(temp, f);
    }
}
