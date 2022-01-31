#ifndef MERGE_H
#define MERGE_H 

#include <stdlib.h>

typedef struct vetor_merge_st MERGE;

void merge_vetores(int *vetor, int inicio1, int fim1, int inicio2, int fim2, int *copiaVetor);
void merge_sort2(int *vetor, int inicio, int f, int *copiaVetor);
void ordenaComMerge(int *vetorParaMerge, int tamanhoVetor);


#endif //MERGE_H