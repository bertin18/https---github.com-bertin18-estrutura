#include "LLSE.h"
int main(void){
   const int tam = 8;
   char *str = NULL;
   TLLSE lista;
   int array[] = {1,3,5,7,9,2,4,6};
   inicializarLLSE(&lista);
   //Inserindo elementos na lista 
   for(int pos = 0; pos < tam; pos++){
      if(inserirInicioLLSE(array[pos], &lista))
            printf("Elemento %d incluido na Fila\n",array[pos]);
   }
   //Mostrando a lista criada
   str = mostrarLLSE(&lista);
   printf("\n%s\n", str);
   free(str); 

   // Mostrar o dado do inicio da lista
   printf("Primeiro elemento da lista: %d\n",acessarInicioLLSE(&lista));
   retirarInicioLLSE(&lista);
   retirarInicioLLSE(&lista);

   //Mostrando a lista
   str = mostrarLLSE(&lista);
   printf("\n%s\n", str);
   free(str); 
   liberarLLSE(&lista);
}