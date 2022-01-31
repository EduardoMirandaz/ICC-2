// RADIX
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void radix(unsigned long int *vet, int n, int e){
  int b = 1 << e;
  int *contadores = (int*) malloc(sizeof(int)*b);
  unsigned long int *temp = (unsigned long int*) malloc(sizeof(unsigned long int)*n);
  unsigned long int *aux = (unsigned long int*) malloc(sizeof(unsigned long int)*n);

  int record = 0;
  for(int i = 0; i < n; i++){
    if(vet[i] > record){
      record = vet[i];
    }
  }

  int times = 0;
  while(record > 0){
    record /= b;
    times++;
  }

  for(int j = 0; j < times; j++){

    for(int i = 0; i < b; i++){
      contadores[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
      int x = vet[i];
      for(int k = 0; k < j; k++){
        x /= b;
      }
      x = x % b;
      contadores[x]++;
      aux[i] = x;
    }


    int acum = 0;
    for(int i = 0; i < b; i++){
      if(contadores[i] != 0){
        int a = contadores[i];
        contadores[i] = acum;
        acum += a;
      }
    }

    
    for(int i = 0; i < n; i++){
      int x = vet[i];
      int y = aux[i];
      temp[contadores[y]] = x;
      contadores[y]++;
    }

    for(int i = 0; i < n; i++){
      vet[i] = temp[i];
      printf("%ld ", vet[i]);
    }
    printf("\n");
  }

  free(temp);
  free(aux);
  free(contadores);
}

int main() {
  int e;
  int n;
  
  scanf("%d %d", &e, &n);
  unsigned long int *vet = (unsigned long int*) malloc(sizeof(unsigned long int)*n);

  for(int i = 0; i < n; i++){
    if(!scanf("%ld", &vet[i])){
      exit(1);
    }
  }

  radix(vet, n, e);

  free(vet);
  
  return 0;
}
// 3 5 4185 5874 8684 475 7628
// 4185 5874 475 8684 7628 
// 7628 4185 475 8684 5874 
// 4185 5874 7628 475 8684 
// 4185 475 8684 5874 7628 
// 475 4185 5874 7628 8684 