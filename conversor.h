#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <iostream>
#include "pilhaVetor.h"

extern pilha p;


void converterDecimalParaBase(int numero, int base, char resultado[]) {
    if (numero == 0) {
        resultado[0] = '0';
        resultado[1] = '\0';
        p.push('0');
        return;
    }

    pilha temp(10);
    int i = 0;

    while (numero > 0) {
        int resto = numero % base;
        char caractere = (resto < 10) ? resto + '0' : 'A' + (resto - 10);

        temp.push(caractere);
        p.push(caractere);
        numero /= base;
    }

    // Desempilha para formar o número na ordem correta
    while (!temp.isEmpty() && i < 10) {
        resultado[i++] = temp.pop();
    }
    resultado[i] = '\0'; // termina a string
}
#endif