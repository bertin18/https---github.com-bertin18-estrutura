#include <iostream>
#include "sistemaLinear.h"

using namespace std;

int main() {
    int escolha;
    cout << "Escolha o método:\n";
    cout << "1 - Resolver sistema triangular superior (Substituição Retroativa)\n";
    cout << "2 - Resolver sistema geral via eliminação de Gauss\n";
    cin >> escolha;

    if (escolha == 1) {
        
        vector<vector<double>> A = {
            {1, -2, 3, 1},
            {0, 3, 1, 0},
            {0, 0, 1, 1},
            {0, 0, 0, 1}
        };
        vector<double> b = {4, 3, 2, 1};

        cout << "Sistema Triangular Superior:\n";
        exibirSistema(A, b);

        vector<double> solucao = substituicaoRetroativa(A, b);
        exibirSolucao(solucao);
    } else if (escolha == 2) {
        // Definição do sistema linear geral da questão 2.24
        vector<vector<double>> A = {
            {2, 3, 1, -1},
            {-1, -1, -4, 1},
            {1, -1, 2, 2},
            {4, -5, -2, -1}
        };
        vector<double> b = {6.9, -6.6, 10.2, -12.3};

        cout << "Sistema Linear Geral:\n";
        exibirSistema(A, b);

        vector<double> solucao = resolverSistemaGauss(A, b);
        exibirSolucao(solucao);
    } else {
        cout << "Opção inválida.\n";
    }

    return 0;
}