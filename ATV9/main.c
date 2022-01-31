#include<stdio.h>
#include<stdlib.h>
#include"util.h"
#include"tree.h"


void shuffle(int *vect, int size)
{
    int aux=0;
    for (int i = 0; i < size - 1; i++) 
    {
        int j = i + rand() / (RAND_MAX / (size - i) + 1);
        aux = vect[j];
        vect[j] = vect[i];
        vect[i] = aux;
    }
}

int main(){
    TREE *tree = createTree();
    int howMuchElements = 0, ordened = 1, number = 0, reader = 0;
    
    if(!scanf("%d", &howMuchElements)) return ERROR;
    int *vect = (int*)calloc(howMuchElements, sizeof(int));
    for(int i = 0; i < howMuchElements; i++) 
        if(!scanf("%d", &vect[i])) return ERROR;
    
    if(ordened)
        shuffle(vect, howMuchElements);
    
    for(int i = 0; i < howMuchElements; i++) 
        insertOnBinaryTree(tree, vect[i]);
    
    int howMuchSearches = 0;
    if(!scanf("%d", &howMuchSearches)) return ERROR;
    
    for(int i = 0; i < howMuchSearches; i++){
        if(!scanf("%d", &number)) return ERROR;
        searchOnBinaryTree(tree, number) == 1 ? printf("1\n") : printf("0\n");
    }
}