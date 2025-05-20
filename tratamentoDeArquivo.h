#include<stdio.h>
typedef struct
{
    char matricula[10];
    char nome[60];
    char escola[30];
    char titulacao[30];
    char tipoDeContrato[30];
}TProfessor;
void mostrarDadosProfessor(TProfessor const * const pessoa){
    printf("\nMatricula: %s ",pessoa->matricula);
    printf("Nome: %s ",pessoa->nome);
    printf("Escola: %s ",pessoa->escola);
    printf("Titulação: %s ",pessoa->titulacao);
    printf("Tipo de Contrato: %s",pessoa->tipoDeContrato);
};