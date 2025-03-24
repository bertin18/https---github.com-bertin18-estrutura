#include <iostream>
#include"funcao.h"

int main(){
    Conjunto teste;
    int opcao;
    int tamanho = 0;
    do
    {
        std::cout<<"======= MENU ======"<<std::endl;
        std::cout<<"1 - Obter tamanho"<<std::endl;
        std::cout<<"2 - gerar conjunto"<<std::endl;
        std::cout<<"3 - Mostar conjunto"<<std::endl;
        std::cout<< "4 - Buscar elemento (sequencial)"<<std::endl;
        std::cout<<"5 - ordenar Conjunto"<<std::endl;
        std::cout<<"6 - Busca binaria"<<std::endl;
        std::cout<<"7 - encerrar"<<std::endl;
        std::cout<<"digite uma opcao:"<<std::endl;
        std::cin>> opcao;
        switch (opcao){
            case 1:
            tamanho = teste.obterTamanhoConjunto();
            std::cout<<"tamanho definido"<<std::endl;
            break;

            case 2:
            if(tamanho>0){
                teste.gerarConjunto(&teste, tamanho);
                std::cout<<"conjunto gerado com sucesso"<<std::endl;
            }else{
                std::cout<<"tamanho invalido"<<std::endl;
            }
            break;

            case 3:
            if(tamanho>0){
                teste.mostrarConjunto(&teste);
            }else{
                std::cout<<"sem conjunto gerado"<<std::endl;
            }
            break;

            case 4:
            if(tamanho > 0){
                int elemento;
                std::cout<<"digite elemento de busca: "<<std::endl;
                std::cin>>elemento;
                int posicao = teste.buscarSequencialAprimorada(elemento);
                if(posicao != -1){
                    std::cout<<"elemento na posicao: "<<posicao<<"\n";
                }else{
                    std::cout<<"elemento nao encontrado\n";
                }
            }
            break;

            case 5:
            if(tamanho > 0 ){
                teste.ordenacaoSelectionSort();
                std::cout<<"Conjunto Ordenado com sucesso ";
            }else{std::cout<<"Nenhum conjunto definido\n";}
            break;

            case 6:
            if(tamanho > 0){
                int elemento;
                std::cout<<"digite elemento de busca:"<<std::endl;
                std::cin>>elemento;
                int posicao = teste.buscaBinaria(elemento);
                if (posicao != -1) 
                {
                    std::cout<<"Elemento na posicao:"<<posicao<<"\n";
                }else{std::cout<<"Elemento não encontrado \n";}
                
            }else{std::cout<<"Nenhum conjunto gerado";}
            break;

            case 7:
            std::cout<<"encerrando programa"<<std::endl;
            break;

            default:
            std::cout<<"Erro: Opção invalida";
        }
    } while (opcao!=7);
    
   
}