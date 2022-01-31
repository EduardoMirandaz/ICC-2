#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
    float x;
    float y;
}ponto;

int main(){
    int quantidadeDePontos = 0;
    if(!scanf("%d", &quantidadeDePontos)){
        exit(1);
    }
    ponto *vetorDePontos = (ponto*) malloc((quantidadeDePontos)*sizeof(ponto));
    float menor = -1;
    float distance = -1;
    for(int i = 0; i < quantidadeDePontos; i++){
        scanf("%f", &vetorDePontos[i].x);
        scanf("%f", &vetorDePontos[i].y); 
        if(i != 0){
            for(int j = 0; j < i; j++){
                distance = sqrt(( (vetorDePontos[i].x - vetorDePontos[j].x) * (vetorDePontos[i].x - vetorDePontos[j].x) )+( (vetorDePontos[i].y - vetorDePontos[j].y) * (vetorDePontos[i].y - vetorDePontos[j].y) ));
                if(distance < 0){
                    distance*=-1;
                }
                if(distance < menor){
                    menor = distance;
                }
                else if(menor == -1){
                    menor = distance;
                }
            }
        }
    }
    printf("%f\n", menor);

}