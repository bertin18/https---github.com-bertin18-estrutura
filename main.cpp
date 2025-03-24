#include <iostream>
#include "conversor.h"

pilha p(10);  

int main() {
    int numero, opcao, repetir;
    char resultado[11]; 

    do {
        std::cout << "===== CONVERSOR DE BASES =====" << std::endl;
        std::cout << "Digite um numero decimal: ";
        std::cin >> numero;

        std::cout << "Escolha a base para conversao:\n";
        std::cout << "1 - Binario (base 2)\n";
        std::cout << "2 - Octal (base 8)\n";
        std::cout << "3 - Hexadecimal (base 16)\n";
        std::cout << "Opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                converterDecimalParaBase(numero, 2, resultado);
                std::cout << "Numero Binario: " << resultado << std::endl;
                break;
            case 2:
                converterDecimalParaBase(numero, 8, resultado);
                std::cout << "Numero Octal: " << resultado << std::endl;
                break;
            case 3:
                converterDecimalParaBase(numero, 16, resultado);
                std::cout << "Numero Hexadecimal: " << resultado << std::endl;
                break;
            default:
                std::cout << "Opcao invalida!" << std::endl;
        }

        std::cout << "\nDeseja converter outro numero? (1 - Sim | 0 - Nao): ";
        std::cin >> repetir;
        std::cout << std::endl;

    } while (repetir == 1);

    std::cout << "\nRestos armazenados na pilha ao longo das conversoes: ";
    p.exibirPilha();

    std::cout << "Programa encerrado." << std::endl;
    return 0;
}