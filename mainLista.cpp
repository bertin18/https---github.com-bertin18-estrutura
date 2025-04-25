#include "ListaVetor.h"

void exibirLista(TLista const *lista) {
    printf("Lista: ");
    for (int i = 0; i < lista->quantidadeDeElementos; i++) {
        printf("%d ", lista->array[i]);
    }
    printf("\n");
}

int main() {
    TLista lista;
    criarLista(10, &lista);

    inserirOrdenadoLista(&lista, 20);
    inserirOrdenadoLista(&lista, 5);
    inserirOrdenadoLista(&lista, 15);
    inserirOrdenadoLista(&lista, 10);

    printf("Apos insercoes ordenadas:\n");
    exibirLista(&lista);

    if (removerElementoLista(&lista, 2)) {
        printf("Elemento removido da posicao 2.\n");
    } else {
        printf("Nao foi possivel remover o elemento.\n");
    }

    printf("Apos remocao:\n");
    exibirLista(&lista);

    liberarLista(&lista);
    return 0;
}