#include <stdio.h>
#include <stdlib.h>
#include "vetores.h"
#include "insertion.h"
#include "merge.h"
void pegarTamanhoDosVetores(int quantidadeDeVetores, int *tamanhoDosVetores){
    for(int i = 0; i < quantidadeDeVetores; i++){
        if(!scanf("%d", &tamanhoDosVetores[i])) exit(1);
            // pego os valores do vetor de  tamanhos (TAMANHO DOS VETORES)
    }
}
void alocarVetoresNoVetor(int quantidadeDeVetores, int **vetorDeVetores, int *tamanhoDosVetores){
    for(int i = 0; i < quantidadeDeVetores; i++){
        vetorDeVetores[i] = (int*)malloc(tamanhoDosVetores[i]*sizeof(int));
    }
}
void lerVetores(int quantidadeDeVetores, int **vetorDeVetores, int *tamanhoDosVetores){
    for(int i = 0; i < quantidadeDeVetores; i++){
        for(int j = 0; j < tamanhoDosVetores[i]; j++){
            if(!scanf("%d", &vetorDeVetores[i][j])) exit(1);
        }
    }
}

void ordenarVetores(int **vetorDeVetores, int quantidadeDeVetores, int *tamanhoDosVetores){
    for(int i = 0; i < quantidadeDeVetores; i++){
        ordenaComInsertion(vetorDeVetores[i], tamanhoDosVetores[i]);
        ordenaComMerge(vetorDeVetores[i], tamanhoDosVetores[i]);
    }
}
