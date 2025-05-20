#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Codigo de uma LLSE Dinamica
// Struct que representa o No da LLSE
typedef struct No{
	int dado;
	struct No *proximo;
}TNo;
// Struct que representa a LLSE
typedef struct{
   struct No *inicio;
	int tamanho;
}TLLSE;
/********************
 * Funções da Lista Linear Simplesmente Encadeada
 ********************/
// Função que cria e inicializa um no para a LLSE
TNo *criarNoLLSE(int elemento){
	TNo * no = (TNo*)malloc(sizeof(TNo));
	if(no == NULL) return NULL;
	no->dado = elemento;
	no->proximo = NULL;
	return no;
} 
//  Função que inicializa a LLSE 
void inicializarLLSE(TLLSE * const lista){
	lista->inicio = NULL;
	lista->tamanho = 0;
}
// Função que verifica se a LLSE esta vazia
int estaVazia(TLLSE const * const lista){
	return  (lista->inicio == NULL);
}

void liberarLLSE(TLLSE *const lista){
    if(estaVazia(lista)) return;
    TNo *atual = lista->inicio;
    while(atual != NULL){
        lista->inicio = atual->proximo;
        free(atual);
        atual = lista->inicio;
    }
    lista->tamanho = 0;
    return;
}
char *mostrarLLSE(TLLSE const * const lista){
    if(estaVazia(lista)){
        char *str = (char *)malloc(100*sizeof(char));
        if(str == NULL) return NULL;
        strcpy(str, "{VAZIA}");
        return str;
    }
    TNo *atual = lista->inicio;
    char *str = (char *)malloc(100*sizeof(char));
    if(str == NULL) return NULL;
    str[0] = '\0';
    strcat(str, "LLSE = {");
    while(atual != NULL){
        char buffer[20];
        snprintf(buffer, sizeof(buffer), "%d ", atual->dado);
        strcat(str, buffer);
        atual = atual->proximo;
    }
    strcat(str, "}");
    return str;
}
int inserirInicioLLSE(int elemento, TLLSE * const lista){
    TNo *no = criarNoLLSE(elemento);
    if(no == NULL) return 0;
    no->proximo = lista->inicio;
    lista->inicio = no;
    lista->tamanho++;
    return 1;
}
int acessarInicioLLSE(TLLSE const * const lista){
    if(estaVazia(lista)) return 0;
    return lista->inicio->dado;
}
int retirarInicioLLSE(TLLSE * const lista){
    if(estaVazia(lista)) return 0;
    TNo *temp = lista->inicio;
    lista->inicio = temp->proximo;
    free(temp);
    lista->tamanho--;
    return 1;
}
