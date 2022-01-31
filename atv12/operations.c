#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"

int quantidadeDeAmigos(NODE *ruas, int quantidadeDeRuas, int origem, int destino){
    for(int i = 0; i < quantidadeDeRuas; i++){
        if(ruas[i].origem == origem){
            if(ruas[i].destino == destino){ 
                return ruas[i].amigos; 
            }
        }
    }
    return 0;
}
int encontrarMelhorCaminho_(NODE *ruas, int quantidadeDeRuas, int origem, int destino, int linhas, int colunas){

    int direitaMelhor = 0;
    int baixoMelhor = origem >= destino - colunas + 1;
    for(int i = 0; i < linhas; i++){
        if(origem == colunas - 1 + i*colunas){
            direitaMelhor = 1;
            i = linhas+1;
        }
    }

    int direita = 0;
    if(!direitaMelhor){                                      // se o melhor estiver na direita, obviamente, pegamos o index+1  
        direita = encontrarMelhorCaminho_(ruas, quantidadeDeRuas, origem + 1, destino, linhas, colunas) + quantidadeDeAmigos(ruas, quantidadeDeRuas, origem, origem + 1);
    }
    int baixo = 0;
    if(!baixoMelhor){                              // se mandarmos buscar no "origem" + "colunas" é como se quebrassemos uma linha e fossemos para o elemento "de baixo"  
        baixo = encontrarMelhorCaminho_(ruas, quantidadeDeRuas, origem + colunas, destino, linhas, colunas) + quantidadeDeAmigos(ruas, quantidadeDeRuas, origem, origem + colunas);
    }

    if (baixo < direita)
        return direita;
    else
        return baixo;
}
int encontrarMelhorCaminho(NODE *ruas, int quantidadeDeRuas, int linhas, int colunas){
    return encontrarMelhorCaminho_(ruas, quantidadeDeRuas, 0, linhas*colunas-1, linhas, colunas);

}
