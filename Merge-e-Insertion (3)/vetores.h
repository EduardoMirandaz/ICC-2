#ifndef VETORES_H
#define VETORES_H 

// typedef struct vetorMerge_st MERGE;

void pegarTamanhoDosVetores(int quantidadeDeVetores, int *tamanhoDosVetores);
void alocarVetoresNoVetor(int quantidadeDeVetores, int **vetorDeVetores, int *tamanhoDosVetores);
void lerVetores(int quantidadeDeVetores, int **vetorDeVetores, int *tamanhoDosVetores);
void ordenarVetores(int **vetorDeVetores, int quantidadeDeVetores, int *tamanhoDosVetores);

#endif //VETORES_H