#include "filaDinamica.h"
int main(void)
{
    fila filaTeste;
    
    //Primeiro teste
    printf("\nFila Declarada");
    inicializarFila(&filaTeste);
    char *str = mostrarFila(&filaTeste);
    printf("\n%s\n", str);
    free(str);

    //Segundo teste
    for(int contador = 0; contador < 10; contador++){
        if(enfileirar(contador*10, &filaTeste))
            printf("Elemento %d incluido na Fila\n",contador*10);
        else printf("Elemento %d Não incluido na Fila\n",contador*10);
    }
    printf("\nFila com dados incluidos");
    str = mostrarFila(&filaTeste);
    printf("\n%s\n", str);
    free(str);    
}