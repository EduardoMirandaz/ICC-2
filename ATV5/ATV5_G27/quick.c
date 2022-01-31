#include<stdio.h>
#include<stdlib.h>

int _quick(int *vetor, int inicio, int fim, int *operacoesQuick)
{
     
    if(inicio >= fim){
        return 0;
    }

    int posicaoPivo = (inicio+fim)/2;
    
    int valorPivo = vetor[posicaoPivo];
    (*operacoesQuick)++;                                        // copia
    int i = inicio;
    int j = fim;

    while(1)
    {
        while(vetor[i] < valorPivo)
        {
        (*operacoesQuick)++;                                       // comparacao
            i++;
        }
        //vetor[i] >= valorPivo
        (*operacoesQuick)++;                                       // comparacao
       
        // vetor[i] aqui já é maior ou igual
        while(vetor[j] > valorPivo)
        {
            (*operacoesQuick)++;                                    // comparacao
            j--;
        }
        //vetor[j] <= valorPivo
        (*operacoesQuick)++;                                       // comparacao

        // vetor[j] aqui já é menor ou igual
        if(j <= i){ //se o da direita passou ou ta no mesmo lugar que o da direita
            break;            
        }
            int temp = vetor[i];
            (*operacoesQuick)++;                                    // copia
            vetor[i] = vetor[j];
            (*operacoesQuick)++;                                    // copia
            vetor[j] = temp;
            (*operacoesQuick)++;                                    // copia
        i++;
        j--;
    }
    _quick(vetor, inicio, j, operacoesQuick);
    _quick(vetor, j+1, fim, operacoesQuick);

   /* printf("\n");
            printf("Quick: ");
            for(int i = inicio; i < fim; i++)
            {
                printf("%d ", vetor[i]);
            }     */   
     
    return 1;

    
}   