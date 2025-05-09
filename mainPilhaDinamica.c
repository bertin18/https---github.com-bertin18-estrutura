#include "pilhadinamica.h"
int main() {
    Pilha p;
    criarPilha(&p);

    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);

    char* resultado = imprimir(&p);
    if (resultado != NULL) {
        printf("Pilha atual: %s\n", resultado);
        free(resultado);
    }

    desempilhar(&p);
    desempilhar(&p);

    resultado = imprimir(&p);
    if (resultado != NULL) {
        printf("Pilha após desempilhar: %s\n", resultado);
        free(resultado);
    }

    liberarPilha(&p);

    return 0;
}