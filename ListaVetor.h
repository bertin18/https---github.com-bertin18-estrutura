#include<iostream>
#include<cstring>


typedef struct {
    int tamanho;
    int quantidadeDeElementos;
    int *array;
} ListaVetor;

void mostrarDadosLista(ListaVetor const *const lista) {
    std::cout << "Tamanho: " << lista->tamanho << "\n";
    std::cout << "Quantidade de Elementos: " << lista->quantidadeDeElementos << "\n";
    std::cout << "Elementos: {";
    for (int i = 0; i < lista->quantidadeDeElementos; i++) {
        std::cout << lista->array[i];
        if (i < lista->quantidadeDeElementos - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";
}

void criarListaVetor(ListaVetor *const lista, int tamanho) {
    lista->tamanho = tamanho;
    lista->quantidadeDeElementos = 0;
    lista->array = (int*)malloc(tamanho * sizeof(int));
}

void liberarListaVetor(ListaVetor *const lista) {
    free(lista->array);
    lista->array = nullptr;
    lista->tamanho = 0;
    lista->quantidadeDeElementos = 0;
}

int listaVazia(ListaVetor const *const lista) {
    return lista->quantidadeDeElementos == 0;
}

int listaCheia(ListaVetor const *const lista) {
    return lista->quantidadeDeElementos == lista->tamanho;
}

int inserirFimLista(ListaVetor *const lista, int elemento) {
    if (listaCheia(lista)) {
        std::cout << "Lista cheia\n";
        return 0;
    }
    
    lista->array[lista->quantidadeDeElementos] = elemento;
    lista->quantidadeDeElementos++;
    return 1;
}

int inserirInicioLista(ListaVetor *const lista, int elemento) {
    if (listaCheia(lista)) {
        std::cout << "Lista cheia\n";
        return 0;
    }
    
    for (int i = lista->quantidadeDeElementos; i > 0; i--) {
        lista->array[i] = lista->array[i - 1];
    }
    
    lista->array[0] = elemento;
    lista->quantidadeDeElementos++;
    return 1;
}
 char * mostraLista(ListaVetor const *const lista) {
    char *elementos = (char*)malloc(256); // Alocação dinâmica
    if (lista->quantidadeDeElementos == 0) {
        return const_cast<char*>("lista:{\u2205}");
    } else {
        strcpy(elementos, "lista:{");
        char buffer[20];
        for (int i = 0; i < lista->quantidadeDeElementos; i++) {
            sprintf(buffer, "%d", lista->array[i]);
            strcat(elementos, buffer);
            if (i < lista->quantidadeDeElementos - 1) {
                strcat(elementos, ",");
            }
        }
        strcat(elementos, "}");
    }
    elementos[strlen(elementos)] = '\0';
    return elementos;
}

//pesquisar sobre snprintf