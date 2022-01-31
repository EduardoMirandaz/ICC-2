#ifndef TREE_H
#define TREE_H

typedef struct tree TREE;
typedef struct node NODE;


TREE *createTree();
int insertOnBinaryTree(TREE *tree, int number);
int searchOnBinaryTree(TREE *tree, int number);
void deleteTree(TREE **tree);


#endif //TREE_H