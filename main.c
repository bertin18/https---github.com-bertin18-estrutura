#include <stdio.h>
#include <string.h>
#include "tratamentoDeArquivo.h"
int main()
{
    // Struct com os dados do professor
    TProfessor prof;
    //Comando que declar um ponteiro para um arquivo em C
    FILE *arquivo = NULL;
    //Nome do arquivo no computador
    char *nomeDoArquivo = "dados.txt";
    //String para coletar dados do teclado
    char string[250];
    //indicador de linha
    int linha = 0;
    int repetir = 1;
    int opcao = 0;
    do{
        printf("MENU DE TRATAMENTO DE ARQUIVO\n");
        printf("Trabalhando com arquivo texto para ESCRITA\n");
        printf("1 - Criar um arquivo vazio e incluir um texto \n");
        printf("2 - Acrescentar dados no fim do arquivo\n");
        printf("3 - Mostrar os dados do arquivo\n");
        printf("4 - Mostrar os dados do arquivo separadamente\n");
        printf("Opcao:");
        //Limpando o buffer do teclado
        fflush(stdin);
        scanf("%d",&opcao);
        switch(opcao){
        case 1:
            //Comando que cria o arquivo texto
            arquivo = fopen(nomeDoArquivo, "w");
            printf("Frase: ");
            //Limpando o buffer do teclado
            fflush(stdin);
            //Comando para ler um string inteira de forma segura
            fgets(string,250,stdin);
            //Comando que escreve em um arquivo texto
            fputs(string,arquivo);
            //Comando que fecha um arquivo texto
            fclose(arquivo);
            break;
        case 2:
            //Comando que cria o arquivo texto
            arquivo = fopen(nomeDoArquivo, "a");
            printf("Frase: ");
            //Limpando o buffer do teclado
            fflush(stdin);
            //Comando para ler um string inteira de forma segura
            fgets(string,250,stdin);
            //Comando que escreve em um arquivo texto
            fputs(string,arquivo);
            //Comando que fecha um arquivo texto
            fclose(arquivo);
            break;
        case 3:
            //Comando que abre um arquivo texto existente
            arquivo = fopen(nomeDoArquivo, "r");
            linha = 1;
            printf("\nMOSTRANDO OS DADOS DO ARQUIVO \n");
            while(!feof(arquivo)){
                if(fgets(string,250,arquivo)) printf("Linha %d - %s",linha,string);
                linha++;
            }
            //Comando que fecha um arquivo texto
            fclose(arquivo);
            break;
        case 4:
            //Comando que abre um arquivo texto existente
            arquivo = fopen(nomeDoArquivo, "r");
            linha = 1;
            printf("\nMOSTRANDO OS DADOS DO ARQUIVO \n");
            char *pt = NULL;
            while(!feof(arquivo)){
                if(fgets(string,250,arquivo)){
                    pt = strtok(string,";");
                    strcpy(prof.matricula,pt);

                    pt = strtok(NULL,";");
                    strcpy(prof.nome,pt);

                    pt = strtok(NULL,";");
                    strcpy(prof.escola,pt);

                    pt = strtok(NULL,";");
                    strcpy(prof.titulacao,pt);

                    pt = strtok(NULL,";");
                    strcpy(prof.tipoDeContrato,pt);

                    mostrarDadosProfessor(&prof);
                }
                linha++;
            }
            //Comando que fecha um arquivo texto
            fclose(arquivo);
            break;

        }

        printf("\nDeseja executar novamente[1-Sim 2-Não]:");
        //Limpando o buffer do teclado
        fflush(stdin);
        scanf("%d",&repetir);
    }while(repetir == 1);


}
