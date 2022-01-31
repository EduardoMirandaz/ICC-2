#include <stdio.h>
#include <stdlib.h>

#define prinft printf

typedef struct {
    int chaveIndex;
    int valor;
}Numero;


int funcaoHash(int , int );
void inserirNaTabela(int , int , Numero *);
void imprimirTabela(Numero *, int );
void buscarNaTabela(int valorASerBuscado, int capacidade, Numero *);
void deletarDaTabela(int valorASerBuscado, int capacidade, Numero *vetor);

int main() {  
  int capacidadeTabela = 0;
  int totalInsercoes = 0;
  int numero;
  
  
  if(!scanf("%d", &capacidadeTabela)){
    return 0;
  }

//N -> Total de inserções
  if(!scanf("%d", &totalInsercoes)){
    return 0;
  }  
  Numero * tabela = calloc(capacidadeTabela, sizeof(Numero));


  for(int i = 0; i < capacidadeTabela; i++){
    tabela[i].valor = -1;
    tabela[i].chaveIndex = -1;
  
  }
  
  for(int i = 0; i < totalInsercoes; i++){
      //ler e inserir os numeros na tabela
      scanf("%d", &numero);
      inserirNaTabela(numero, capacidadeTabela, tabela);
  }
  //imprimirTabela(tabela, capacidadeTabela);

//D -> total de remocoes
  int totalDeRemocoes = 0;

  if(!scanf("%d", &totalDeRemocoes)){
    return 0;
  }
  int chaveRemocao;
  for(int i = 0; i < totalDeRemocoes; i++){
    //buscar e imprimir index de onde está o elemento na tabela
    scanf("%d", &chaveRemocao);
    deletarDaTabela(chaveRemocao, capacidadeTabela, tabela);
    //se nao for encontrado imprime -1

  }
  
//B -> total de buscas
//
  int totalDeBuscas = 0;

  if(!scanf("%d", &totalDeBuscas)){
    return 0;
  }

int chaveDeBusca;
  for(int i = 0; i < totalDeBuscas; i++){
      //buscar e imprimir index de onde está o elemento na tabela
      scanf("%d", &chaveDeBusca);
      buscarNaTabela(chaveDeBusca, capacidadeTabela, tabela);
      //se nao for encontrado imprime -1

  }
}


int funcaoHash(int valorASerInserido, int capacidade){
  return valorASerInserido % capacidade;
}

void inserirNaTabela(int valorASerInserido, int capacidade, Numero *vetor){
  
  for(int i = 0; i < capacidade; i++){
    if(vetor[i].valor == valorASerInserido) return;
  }
  int sondagem = funcaoHash(valorASerInserido, capacidade);
  int i = 0;

  while(vetor[sondagem].valor != -1){
    i++;
    sondagem = funcaoHash(valorASerInserido + i, capacidade);
  }
  vetor[sondagem].valor = valorASerInserido;
  vetor[sondagem].chaveIndex = sondagem;

}

void buscarNaTabela(int valorASerBuscado, int capacidade, Numero * vetor){

 for (int i=0; i<capacidade; i++) {
        if (vetor[i].valor == valorASerBuscado) {
            printf("%d ", vetor[i].chaveIndex);
            return;
        }
    }
  printf("-1 ");
}

void deletarDaTabela(int valorASerBuscado, int capacidade, Numero *vetor){

 for (int i=0; i<capacidade; i++) {
        if (vetor[i].valor == valorASerBuscado) {
            vetor[i].valor = -1;
            vetor[i].chaveIndex = -1;
            return;
        }
    }
}


void imprimirTabela(Numero *vetor, int tam){
    printf("\n");

   for(int i = 0; i < tam; i++){
    printf("%d | ", vetor[i].valor);
  }
    printf("\n");

}