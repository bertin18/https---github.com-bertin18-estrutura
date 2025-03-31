#include <iostream>
#include "fila.h"

int main(){
    fila f;
    criarFila(&f, 5);
    mostrarDadosFila(&f);
    
    
    char* elemento = mostraFila(&f);
    std::cout << elemento << "\n";
    liberarFila(&f);
    return 0;
}