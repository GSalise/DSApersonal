#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node *right;
    struct node *left;
}NodeType, *NodePtr, *BST;

void insertBST(BST *bst , int data){
    NodePtr *hrf = &(*bst);
    
    while(*hrf!=NULL){
        if((*hrf)->data > data){
            hrf = &((*hrf)->left);
        }else{
            hrf = &((*hrf)->right);
        }
 
    }
    
    *hrf = calloc(1, sizeof(NodeType));
    (*hrf)->data = data;
    
    
    
    
}

void inorder(BST bst){
    if(bst!=NULL){
        inorder(bst->left);
        printf("%d ", bst->data);
        inorder(bst->right);
    }
}

int main(){
    BST a = NULL;
    insertBST(&a, 10);
    insertBST(&a, 8);
    insertBST(&a, 100);
    insertBST(&a, 9);
    insertBST(&a, 5);
    insertBST(&a, 7);
    
    inorder(a);
    
    return 0;
}
