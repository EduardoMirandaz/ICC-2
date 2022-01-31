#include <stdio.h>
#include "insertion.h"

struct vetorInsertion_st{
  int tamanho;
  int comparacoes;
  int trocas;
};

void ordenaComInsertion(int *vetorParaInsertion, int tamanhoVetor){
  int i = 0, j = 0, aux = 0;
  int trocas = 0, comparacoes = 0;
  int *vetor = (int*) malloc(tamanhoVetor*sizeof(int));
    for(int i = 0; i < tamanhoVetor; i++){
        vetor[i] = vetorParaInsertion[i];
    }

  for(i = 1; i < tamanhoVetor; i++){
    aux = vetorParaInsertion[i];
    trocas++;
    /* *************************************** */
    for(j = i-1; aux < vetorParaInsertion[j]; j--){
      if(j >= 0){
        vetorParaInsertion[j+1] = vetorParaInsertion[j];
        trocas++;
      }
      comparacoes++;
    }
    if(aux >= vetorParaInsertion[j] && j >= 0){
      comparacoes++;
    }
     /* ****************************************** */
    vetorParaInsertion[j+1] = aux;
    trocas++;
    }
  printf("I %d %d %d\n", tamanhoVetor, trocas, comparacoes);  
}