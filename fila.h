#include <iostream>
#include <cstring>

struct fila{
    int tamanho;
    int inicio;
    int fim;
    int quantidadeDeElementos;
    int *array;
};

void criarFila(fila *const f, int tamanho) {
    f->tamanho = tamanho;
    f->inicio = 0;
    f->fim = -1;
    f->quantidadeDeElementos = 0;
    f->array = new int[tamanho];
}

void liberarFila(fila *const f) {
    delete[] f->array;
}

bool filaVazia(fila const * const f) {
    return f->quantidadeDeElementos == 0;
}

bool filaCheia(fila const * const f) {
    return f->quantidadeDeElementos == f->tamanho;
}

void inserirElemento(fila *const f, int elemento){
    if (filaCheia(f)) {
        std::cout << "Fila cheia\n";
        return;
    }
    
    f->fim = (f->fim + 1) % f->tamanho;
    f->array[f->fim] = elemento;
    f->quantidadeDeElementos++;

}
char* mostraFila(fila const * const f) {
    char *elementos = new char[256]; // Alocação dinâmica
    if (f->quantidadeDeElementos == 0) {
        sprintf(elementos, "fila:{%c}", char(248));
    } else {
        strcpy(elementos, "fila:{");
        char buffer[20];
        for (int i = 0; i < f->quantidadeDeElementos; i++) {
            sprintf(buffer, "%d", f->array[(f->inicio + i) % f->tamanho]);
            strcat(elementos, buffer);
            if (i < f->quantidadeDeElementos - 1) {
                strcat(elementos, ",");
            }
        }
        strcat(elementos, "}");
    }
    return elementos;
}

void mostrarDadosFila(fila const * const f) {
    std::cout << "Tamanho da fila: " << f->tamanho << "\n";
    std::cout << "Início: " << f->inicio << "\n";
    std::cout << "Fim: " << f->fim << "\n";
    std::cout << "Quantidade de elementos: " << f->quantidadeDeElementos << "\n";
    
    std::cout << "Elementos na fila: ";
    for (int i = 0; i < f->quantidadeDeElementos; i++) {
        std::cout << f->array[(f->inicio + i) % f->tamanho] << " ";
    }
    std::cout << "\n";
}
