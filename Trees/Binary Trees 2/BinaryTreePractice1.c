#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}NodeType, *NodePtr, *BST;

void inorder(BST bst){
    if(bst!=NULL){
        inorder(bst->left);
        printf("%d ", bst->data);
        inorder(bst->right);
    }
}


void insert(BST *b, int val){
    
    //A temp value used to hold BST
    NodeType **hrf = &(*b);

    //Checks if the value inside hrf in not null, i.e., there is no address stored in it
    while(*hrf!=NULL){
        if((*hrf)->data > val){
            //means that hrf will now hold the address of struct node left
            //doing (*hrf)->left will hold the value stored inside struct node left which is wrong
            //we want to hold the address of struct node left instead
            hrf = &((*hrf)->left);
        }else{
            hrf = &((*hrf)->right);
        }
    }
    *hrf = calloc(1, sizeof(NodeType));
    (*hrf)->data = val;
}


void search(BST bst, int val){
    while(bst!=NULL && bst->data != val){
        if(bst->data > val){
            bst = (bst->left);
        }else{
            bst = (bst->right);
        }
    }

    if(bst==NULL){
        printf("\n%d does not exist", val);
    }else{
        printf("\n%d is present", val);
    }

}


BST findMin(BST b){
    NodePtr temp = b;

    while(temp->left != NULL){
        temp = temp->left;
    }

    return temp;
}

BST deleteR(BST b, int val){
    //base case
    if(b == NULL){
        return b;
    }
    
    //recursive steps
    if(b->data > val){
        b->left = deleteR(b->left, val); //allows the parents to be updated
    }else if(b->data < val){
        b->right = deleteR(b->right, val); //allows the parents to be updated
    }else{
        
        if(b->left == NULL && b->right == NULL){
            free(b);                                        //deletes leaves
            return NULL;
        }else if(b->left == NULL){
            NodePtr temp = b;                               //deletes nodes with a single child
            b = b->right;
            free(temp);
        }else if(b->right == NULL){
            NodePtr temp = b;
            b = b->left;
            free(temp);
        }else{
            NodePtr temp = findMin(b->right);
            b->data = temp->data;                           //deletes nodes with 2 children
            b->right = deleteR(b->right, temp->data);
        }

    }
    return b;
}







int main(){
    BST b = NULL;

    insert(&b, 10);
    insert(&b, 8);
    insert(&b, 100);
    insert(&b, 9);
    insert(&b, 5);
    insert(&b, 7);
    insert(&b, 58);
    inorder(b);
    search(b, 5);
    search(b,6);
    b = deleteR(b, 7);
    printf("\nAfter 7 delete\n");
    inorder(b); 
    deleteR(b, 5);
    printf("\nAfter 5 delete\n");
    inorder(b); 
    deleteR(b, 10);
    printf("\nAfter 8 delete\n");
    inorder(b); 
    return 0;
}