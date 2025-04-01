#include <iostream>
#include "fila.h"

int main(){
    std::setlocale(LC_ALL, "en_US.UTF-8");
    fila f;
    criarFila(&f, 3);
   
    char* elemento = mostraFila(&f);
    
    std::cout << elemento << "\n";
    liberarFila(&f);
    return 0;
}