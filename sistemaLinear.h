#ifndef SISTEMALINEAR_H
#define SISTEMALINEAR_H

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Função para resolver um sistema triangular superior por substituição retroativa
vector<double> substituicaoRetroativa(vector<vector<double>> A, vector<double> b) {
    int n = A.size();
    vector<double> x(n, 0);

    for (int i = n - 1; i >= 0; i--) {
        double soma = 0.0;
        for (int j = i + 1; j < n; j++) {
            soma += A[i][j] * x[j];
        }
        x[i] = (b[i] - soma) / A[i][i];
    }
    return x;
}

// Função para triangularizar a matriz usando eliminação de Gauss
void eliminacaoGauss(vector<vector<double>> &A, vector<double> &b) {
    int n = A.size();
    
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            double m = A[i][k] / A[k][k];
            for (int j = k; j < n; j++) {
                A[i][j] -= m * A[k][j];
            }
            b[i] -= m * b[k];
        }
    }
}

// Função para resolver um sistema linear qualquer via eliminação de Gauss
vector<double> resolverSistemaGauss(vector<vector<double>> A, vector<double> b) {
    eliminacaoGauss(A, b);
    return substituicaoRetroativa(A, b);
}

// Função para exibir um sistema linear
void exibirSistema(vector<vector<double>> A, vector<double> b) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(8) << A[i][j] << " ";
        }
        cout << " | " << setw(8) << b[i] << endl;
    }
    cout << endl;
}

// Função para exibir uma solução
void exibirSolucao(vector<double> x) {
    cout << "Solucao:\n";
    for (size_t i = 0; i < x.size(); i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
    cout << endl;
}

#endif