#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
#include "operations.h"
#define ERRO_LEITURA -32000


int main(){
    int linhas = 0, colunas = 0;
    if(!scanf("%d %d", &linhas, &colunas)){
        printf("Erro de leitura :((((((");
        return ERRO_LEITURA;
    }

    int quantidadeDeRuas = (linhas - 1)*colunas + (colunas - 1)*linhas;

    NODE *rua = (NODE *)calloc(quantidadeDeRuas, sizeof(NODE));

    for(int i = 0; i < quantidadeDeRuas; i++){ 
        if(!scanf("%d %d %d", &rua[i].origem, &rua[i].destino, &rua[i].amigos)){
            printf("Erro de leitura :((((((");
            return ERRO_LEITURA;
        };
    }

    int qtdadeAmigosMelhorCaminho = encontrarMelhorCaminho(rua, quantidadeDeRuas, linhas, colunas);
    printf("%d\n", qtdadeAmigosMelhorCaminho);

    free(rua);
    return 0;
}