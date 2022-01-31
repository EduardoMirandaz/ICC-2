#include<stdio.h>
#include<stdlib.h>
#include"shell.h"
#include"quick.h"


int main(){
    int howMuchElements = 0, operacoesShell = 0;// operacoesQuick = 0;  
    if(!scanf("%d", &howMuchElements)) exit(1);

    //printf("\n[%d]\n", howMuchElements);

    int *vector = NULL;
    vector = malloc(howMuchElements*(sizeof(int)));
    int *vetorQuick  = NULL;
        vetorQuick  = malloc(howMuchElements*(sizeof(int)));
    for(int i = 0; i < howMuchElements; i++){
        if(!scanf("%d", &vector[i])){
            exit(1);
        }
       
    }
    
    for(int tamanhodoSubVetor=1; tamanhodoSubVetor< howMuchElements+1;tamanhodoSubVetor++)
    {
        // Contador do Quick
        int operacoesQuick = 0, *operacoesQuick_function;
        operacoesQuick_function = &operacoesQuick;

        // vetor do quick
        //int *vetorQuick = (int*) malloc(sizeof(int)*tamanhodoSubVetor);
        //printf("\n vetorQuick: ");
        for(int i = 0; i < tamanhodoSubVetor; i++)
        {
            vetorQuick[i] = vector[i];
            
            //printf("%d ", vetorQuick[i]);
        }
        

        //operacoes
        operacoesShell = shellSort(vector, tamanhodoSubVetor);
        _quick(vetorQuick, 0, (tamanhodoSubVetor-1), operacoesQuick_function);

        //printf("\n s:%d ; q:%d \n",operacoesShell,operacoesQuick);
        

        // Resposta
        if(operacoesQuick > operacoesShell)
        {
            
            printf("S ");
        }
        if(operacoesQuick < operacoesShell)
        {
            printf("Q ");
        }
        if(operacoesQuick == operacoesShell)
        {
            printf("- ");
        }
        
    }
}
