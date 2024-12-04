#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

int main(){
    BST b = NULL;

    insert(&b,10);
    insert(&b,11);
    insert(&b, 5);
    insert(&b, 4);
    insert(&b, 3);

    inOrder(b);
    printf("\n\n");
    postOrder(b);
    printf("\n\n");
    preOrder(b);

    printf("\n");
    return 0;
}