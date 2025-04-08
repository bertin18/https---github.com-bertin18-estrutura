#include <iostream>
#include "fila.h" // Se você salvou suas funções em um .h/.cpp separado
// Ou simplesmente inclua todas as funções diretamente acima do main

int main() {
    fila filaTeste;

    // Primeiro teste
    std::cout << "\nFila Declarada\n";
    mostrarDadosFila(&filaTeste);

    criarFila(&filaTeste, 4);
    std::cout << "\nFila Criada e Inicializada\n";
    mostrarDadosFila(&filaTeste);

    char *str = mostraFila(&filaTeste);
    std::cout << "\n" << str << "\n";
    delete[] str;

    // Segundo teste
    inserirElemento(&filaTeste, 105);
    inserirElemento(&filaTeste, 205);
    inserirElemento(&filaTeste, 305);
    inserirElemento(&filaTeste, 405);
    inserirElemento(&filaTeste, 505); // Deve dar mensagem de fila cheia

    std::cout << "\nFila com dados incluídos\n";
    mostrarDadosFila(&filaTeste);
    str = mostraFila(&filaTeste);
    std::cout << "\n" << str << "\n";
    delete[] str;

    // Remoção de elementos
    desenfileirar(&filaTeste);
    desenfileirar(&filaTeste);
    desenfileirar(&filaTeste);

    inserirElemento(&filaTeste, 550);
    inserirElemento(&filaTeste, 660);

    str = mostraFila(&filaTeste);
    std::cout << "\n" << str << "\n";
    delete[] str;

    std::cout << "\nFila com dados incluídos/excluídos\n";
    mostrarDadosFila(&filaTeste);

    liberarFila(&filaTeste);

    return 0;
}
