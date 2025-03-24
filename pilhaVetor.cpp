#include "pilhaVetor.h"
#include <iostream>
using namespace std;
int main(){
    int tamanho, opcao, valor;
    cout<<"Digite o tamanho da pilha:";
    cin>>tamanho;

    pilha p(tamanho);
    
        do {
            cout << "\nMenu:\n";
            cout << "1 - Empilhar\n";
            cout << "2 - Desempilhar\n";
            cout << "3 - Exibir pilha\n";
            cout << "0 - Sair\n";
            cout << "Escolha uma opção: ";
            cin >> opcao;
    
            switch (opcao) {
                case 1:
                    cout << "Digite o valor a empilhar: ";
                    cin >> valor;
                    p.push(valor);
                    break;
                case 2:
                    valor = p.pop();
                    if (valor != -1) {
                        cout << "Elemento " << valor << " desempilhado.\n";
                    }
                    break;
                case 3:
                    p.exibirPilha();
                    break;
                case 0:
                    cout << "Encerrando programa...\n";
                    break;
                default:
                    cout << "Opção inválida! Tente novamente.\n";
            }
        } while (opcao != 0);
    
        return 0;
    
  
    
}