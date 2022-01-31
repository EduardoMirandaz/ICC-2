#include <stdio.h>
#include <stdlib.h>
#include "quick_Sort.h"

int busca_Binaria(int *vector, int inicio, int finalVetor, int valor_procurar);

int main()
{
  int vet_size;
  if(!scanf("%d", &vet_size))
  {
    exit(-1);
  }
  int* vet = (int *) calloc(vet_size, sizeof(int));
  if(vet == NULL)
  {
    exit(-1);
  }

  for(int i = 0; i < vet_size; i++)
  {
    if(!scanf("%d", &vet[i])){
      exit(1);
    }
  }
  int numero_buscas = 0;
  if(!scanf("%d", &numero_buscas))
  {
    exit(-1);
  }
  // verificar se está ordenado:
  for(int i = 0; i < vet_size; i++){
    if(vet[i] > vet[i+1]){
      quick_Sort(vet, vet_size);
      break;
    }
  }
  
  int valor_procurar = 0;
  for (int i=0; i < numero_buscas; i++){
    if(!scanf("%d", &valor_procurar)){
      exit(1);
    }
  
    if(i == numero_buscas-1){
      if(busca_Binaria(vet, 0, vet_size-1, valor_procurar) == -1)
      {
        printf("0");
      }
      else{
        printf("1");
      }
    }
    else{
      if( busca_Binaria(vet, 0, vet_size-1, valor_procurar) == -1 )
      {
        printf("0\n");
      }
      else{
        printf("1\n");
      }
    }
  }
}

int busca_Binaria(int *vector, int inicio, int finalVetor, int valor_procurar)
{
    int m = (inicio + finalVetor) / 2;

    if (inicio > finalVetor) {
        return -1;
    }

    if (vector[m] == valor_procurar) {
        return m;
    }

    if (vector[m] < valor_procurar) {
        return busca_Binaria(vector, m + 1, finalVetor, valor_procurar);

    } else {
        return busca_Binaria(vector, inicio, m - 1, valor_procurar);
    }
}