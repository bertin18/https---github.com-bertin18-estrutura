#include "ListaVetor.h"



int main() {
    TLista lista;
    criarLista(10, &lista);

    inserirOrdenadoLista(&lista, 20);
    inserirOrdenadoLista(&lista, 5);
    inserirOrdenadoLista(&lista, 15);
    inserirOrdenadoLista(&lista, 10);

    printf("Apos insercoes ordenadas:\n");
    exibirLista(&lista);

    if (removerElementoLista(&lista, 5)) {
        printf("Elemento removido.\n");
    } else {
        printf("Nao foi possivel remover o elemento.\n");
    }

    printf("Apos remocao:\n");
    exibirLista(&lista);

    liberarLista(&lista);
    return 0;
}