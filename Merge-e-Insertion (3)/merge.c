#include<stdio.h>
#include<stdlib.h>
#include"merge.h"
int comparacoes,trocas;
struct vetor_merge_st{
  int tamanho;
  int comparacoes;
  int trocas;
};

void merge_vetores(int *vetor, int inicio1, int fim1, int inicio2, int fim2, int *copiaVetor){

    int i1 = inicio1;
    int i2 = inicio2;
    int j = 0;

    while(i1<=fim1 && i2<=fim2){
        if(vetor[i1]<=vetor[i2]){
            comparacoes++;
            trocas++;
            copiaVetor[j] = vetor[i1];
            j++;
            i1++;
        }
        else{
            comparacoes++;
            copiaVetor[j] = vetor[i2];
            trocas++;
            j++;
            i2++;
        }

    }

    while(i1<=fim1){
        copiaVetor[j] = vetor[i1];
        trocas++;
        j++;
        i1++;
    }

    while(i2<=fim2){
        copiaVetor[j] = vetor[i2];
        trocas++;
        j++;
        i2++;
    }

    j=0;

    for(int i=inicio1;i<=fim2;i++,j++){
        vetor[i] = copiaVetor[j];
        trocas++;
    }
}

void merge_sort2(int *vetor, int inicio, int f, int *copiaVetor){

    if(inicio >= f){
        return;
    }

    int meio = (inicio+f)/2;

    merge_sort2(vetor, inicio, meio, copiaVetor);
    merge_sort2(vetor, meio+1, f, copiaVetor);
    merge_vetores(vetor, inicio, meio, meio+1, f, copiaVetor);
}

void ordenaComMerge(int *vetor, int tamanhoVetor){
    comparacoes=0;
    trocas=0;
    int *copiaVetor = (int*)malloc(tamanhoVetor*sizeof(int));

    MERGE *merge = (MERGE*) malloc(1*sizeof(MERGE));

    if(vetor == NULL){
        printf("ERRO");
        exit(-1);
    }

    merge_sort2(vetor, 0, tamanhoVetor-1, copiaVetor);
    printf("M %d %d %d\n", tamanhoVetor, trocas,comparacoes);
    free(copiaVetor);
}