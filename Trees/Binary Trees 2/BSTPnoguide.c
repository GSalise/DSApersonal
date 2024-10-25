#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}NodeType, *NodePtr, *BST;


BST insert(BST b, int val){
    if(b == NULL){
        b = calloc(1, sizeof(NodeType));
        b->data = val;
        return b;
    }else{
        if(b->data > val){
            b->left = insert(b->left, val); 
            //assins the new insert to the parents thus maintaining
            // the bst structure. It is imperative that you do not foreget this
        }else{
            b->right = insert(b->right, val);
        }

    }

    return b; // there is always a return
}


BST findMin(BST b){
    NodePtr curr = b;
    while(curr->left!=NULL){
        curr = curr->left;
    }
    return curr;
}

BST delete(BST b, int val){
    if(b==NULL){
        return b;
    }

    if(b->data > val){
        b->left = delete(b->left, val);
    }else if(b->data < val){
        b->right = delete(b->right, val);
    }else{
        if(b->left == NULL && b->right == NULL){
            free(b);
            return NULL;
        }else if(b->left == NULL){
            NodePtr temp = b;
            b = b->right;
            free(temp);
        }else if(b->right == NULL){
            NodePtr temp = b;
            b = b->left;
            free(temp);
        }else{
            NodePtr temp = findMin(b->right);
            b->data = temp->data;
            b->right = delete(b->right, temp->data);
        }
    }



    return b; // there is always a return
}

void inorder(BST b){
    if(b!=NULL){
        inorder(b->left);
        printf("%d ", b->data);
        inorder(b->right);
    }
}

int main(){
    BST b = NULL;

    b=insert(b, 10);
    b=insert(b, 8);
    b=insert(b, 100);
    b=insert(b, 9);
    b=insert(b, 5);
    b=insert(b, 7);
    b=insert(b, 58);
    
    inorder(b);

    delete(b, 10);
    printf("\n");
    inorder(b);

}