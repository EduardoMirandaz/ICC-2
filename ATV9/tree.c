#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#include"util.h"
int flag = 0;

typedef struct node NODE;

struct tree{
    NODE *root;
    int depth;
};

struct node{
    int number;
    NODE *right;
    NODE *left;
};

TREE *createTree(){
    TREE *emptyTree = (TREE*) calloc (1, sizeof(TREE));
    if(emptyTree != NULL){
        emptyTree->root = NULL;
        emptyTree->depth = -1;
        return emptyTree;
    }
    else{
        return NULL;
    }
}

static NODE* createNode(int number)
{
    NODE *newNode = (NODE *) malloc(sizeof(NODE));
    if (newNode != NULL) {
        newNode->number = number;
        newNode->right = NULL;
        newNode->left = NULL;
    }
    return newNode;
}


NODE *recursiveInsertNode(NODE *root, int number){
    if (root == NULL)
        root = createNode(number);
    else if(root->number < number)
        root->right = recursiveInsertNode(root->right,number);
    else if(root->number > number)
        root->left = recursiveInsertNode(root->left,number);
    return root;
}

int insertOnBinaryTree(TREE *tree, int number){
    if (tree->root == NULL){
        tree->root = createNode(number);
        return(tree->root != NULL);
    }
    else{
        tree->root = recursiveInsertNode(tree->root, number);
        return( tree->root != NULL);
    }
}


int recursiveSearch(NODE *root, int number)
{
    if(root == NULL)
        return 0;
    if(number == root->number)
        return 1;
    if(number < root->number)
        return (recursiveSearch(root->left, number));
    else
        return (recursiveSearch(root->right, number));
}

int searchOnBinaryTree(TREE *tree, int number)
{
    return(recursiveSearch(tree->root, number));
}

void recursiveDeleteTree(NODE **root) {
    if (*root != NULL) {
        recursiveDeleteTree(&(*root)->left);
        recursiveDeleteTree(&(*root)->right);
        free(*root);
        *root = NULL;
    }
}
void deleteTree(TREE **tree) {
    recursiveDeleteTree(&(*tree)->root);
    free(*tree);
    *tree = NULL;
}