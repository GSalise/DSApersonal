#ifndef BST_H
#define BST_H

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}NodeType, *NodePtr, *BST;

void insert(BST *b, int data);
BST removeNode(BST b, int data);
BST getMin(BST b);
void search(BST b, int data);
void inOrder(BST b);
void postOrder(BST b);
void preOrder(BST b);

#endif