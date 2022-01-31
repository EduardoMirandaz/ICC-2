#include<stdio.h>
#include<stdlib.h>
#include"vetores.h"
#include"merge.h"
#include"insertion.h"
//receba o número Q de vetores
//deve ser lido o tamanho N de cada um dos Q vetores
//leia cada vetor

//imprimir o número de trocas e comparações
// M N T C método tamanho trocas e comparações

int main(void){
    int quantidadeDeVetores;
    if(!scanf("%d", &quantidadeDeVetores)) exit(1);//pego a quant de vetores e, caso o scanf dê erro, saio do programa
    int **vetorDeVetores = (int**) malloc (quantidadeDeVetores*sizeof(int*)); // dou malloc no meu VETOR de vetores
    int *tamanhoDosVetores = (int*) malloc (quantidadeDeVetores*sizeof(int)); // dou malloc no meu vetor auxiliar, que contém os tamanhos
    pegarTamanhoDosVetores(quantidadeDeVetores, tamanhoDosVetores);
    alocarVetoresNoVetor(quantidadeDeVetores, vetorDeVetores, tamanhoDosVetores);
    lerVetores(quantidadeDeVetores, vetorDeVetores, tamanhoDosVetores);
    ordenarVetores(vetorDeVetores, quantidadeDeVetores, tamanhoDosVetores);
}

