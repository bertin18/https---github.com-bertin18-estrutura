#include <iostream>
#include <cstring>
#include <locale>
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
    if(filaVazia(f)){
        f->inicio = 0;
    }
    f->array[f->fim] = elemento;
    f->quantidadeDeElementos++;

}
char* mostraFila(fila const * const f) {
    char *elementos = new char[256]; // Alocação dinâmica
    if (f->quantidadeDeElementos == 0) {
        strcpy(elementos, "fila:{\u2205}");
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
    elementos[strlen(elementos)] = '\0';
    return elementos;
}

void mostrarDadosFila(fila const * const f) {
    std::cout << "Tamanho da fila: " << f->tamanho << "\n";
    std::cout << "Início: " << f->inicio << "\n";
    std::cout << "Fim: " << f->fim << "\n";
    std::cout << "Quantidade de elementos: " << f->quantidadeDeElementos << "\n";
    
    
    std::cout << "\n";
}
void desenfileirar(fila *const f) {
    if (filaVazia(f)) {
        std::cout << "Erro: Fila vazia, não é possível desenfileirar.\n";
        return;
    }

    int elementoRemovido = f->array[f->inicio]; 
    f->inicio = (f->inicio + 1) % f->tamanho;  // Atualiza o índice do início de forma circular
    f->quantidadeDeElementos--;                

}

int acessar(fila const *const f){
    if(filaVazia(f)) {
        std::cout << "Erro: Fila vazia, não é possível acessar o elemento.\n";
        return -1; 
    }
    return f->array[f->inicio]; // Retorna o elemento no início da fila
}
