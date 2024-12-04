#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void insert(BST *b, int data){

    while(*b!=NULL){
        if((*b)->data > data){
            b = &((*b)->left);
        }else{
            b = &((*b)->right);
        }
    }

    *b = calloc(1, sizeof(NodeType));
    (*b)->data = data;
}

BST removeNode(BST b, int data){
    if(b == NULL){
        return b;
    }

    if(b->data > data){
        b->left = removeNode(b->left, data);
    }else if(b->data < data){
        b->right = removeNode(b->right, data);
    }else{
        if(b->left == NULL && b->right == NULL){
            free(b);
            return NULL;
        }else if(b->left == NULL){
            BST temp = b->right;
            b = temp;
            free(temp);
        }else if(b->right == NULL){
            BST temp = b->left;
            b = temp;
            free(temp);
        }else{

        }
    }

}

BST getMin(BST b){
    while(b!=NULL){
        b = b->left;
    }

}

void search(BST b, int data){

}

void inOrder(BST b){
    if(b!=NULL){
        inOrder(b->left);
        printf("%d ",b->data);
        inOrder(b->right);
    }
}

void postOrder(BST b){
    if(b!=NULL){       
        postOrder(b->left);
        postOrder(b->right);
        printf("%d ",b->data);     
    }
}

void preOrder(BST b){
    if(b!=NULL){
        printf("%d ",b->data);        
        preOrder(b->left);
        preOrder(b->right);
    }
}