#include "PilhaVetor.h"
#include <iostream>

int main() {
    int tamanho;
    std::cout << "Informe o tamanho da pilha: ";
    std::cin >> tamanho;

    pilha minhaPilha(tamanho);

    int opcao;
    char valor;

    do {
        std::cout << "\n===== MENU =====\n";
        std::cout << "1. Inserir (push)\n";
        std::cout << "2. Remover (pop)\n";
        std::cout << "3. Ver topo\n";
        std::cout << "4. Exibir pilha\n";
        std::cout << "5. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch(opcao) {
            case 1:
                std::cout << "Informe o caractere a ser inserido: ";
                std::cin >> valor;
                minhaPilha.push(valor);
                break;
            case 2:
                valor = minhaPilha.pop();
                if (valor != '\0') {
                    std::cout << "Valor removido: " << valor << std::endl;
                }
                break;
            case 3:
                valor = minhaPilha.top();
                if (valor != '\0') {
                    std::cout << "Topo da pilha: " << valor << std::endl;
                }
                break;
            case 4:
                minhaPilha.exibirPilha();
                break;
            case 5:
                std::cout << "Saindo do programa...\n";
                break;
            default:
                std::cout << "Opção inválida!\n";
        }
    } while(opcao != 5);

    return 0;
}
