#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"shell.h"


int shellSort(int vetor[], int n){
    int *vetorCopia = (int*) malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++){
        vetorCopia[i] = vetor[i];
    }
  
  int gap = 1;
  while(gap<=n)
  {
    gap *=2;
  }
    gap= gap/2-1;

   
    int operacoes = 0;
    while(gap>0)
    {

        int i = 0, j = 0, aux = 0;

        for(i = gap; i < n; i++){
            aux = vetorCopia[i];
            operacoes++;                                                      //copia
            j = i-gap;
            while(j>=0 && vetorCopia[j]> aux)
            {
                operacoes++;                                                  //compara
                vetorCopia[j+gap]=vetorCopia[j];
                operacoes++;                                                     //copia
                j-=gap;
                
            }
            if(j >= 0 && aux >= vetorCopia[j] )
            {   //Olha o curto circuito j  mais importante
                operacoes++;                                                  //compara
            }
            
            vetorCopia[j+gap] = aux;
            operacoes++;                                                      //copia
        }

    
        gap/=2;
    }

   // printf("\n");
    //printf("Shell: ");
     /*for(int i = 0; i < n; i++)
     {
         printf("%d ", vetorCopia[i]);
     }*/

    free(vetorCopia);
    return operacoes;
}