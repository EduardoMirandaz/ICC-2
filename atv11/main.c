#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 200

int montagem (char *string_1, char *string_2);

int main(){
    int quantidadeDeReads = 3;
    // if(!scanf("%d", &quantidadeDeReads)){
    //     exit(1);
    // }
    for(int i = 0; i < quantidadeDeReads; i++){
        for(int j = 0; j < quantidadeDeReads; j++){
            if(i != j){
                printf("i == %d j == %d\n", i,j);
            }
        }   
    }
    char reads[][max] = {"atccat", "ctgatc", "ccatg"};
    int overlap = 0, aux_overlap = 0;
    
}

int montagem (char *string_1, char *string_2){
}