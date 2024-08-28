#include <stdio.h>
#include <stdbool.h>
#include "MyStack.h"

int main(){
	
	Stack A;
	initStack(&A);
	
	printf("Is this empty? %d\n", isEmpty(A));
	printf("Is this full? %d\n", isFull(A));
	push(&A, 1);
	push(&A, 2);
	push(&A, 3);
	push(&A, 4);
	push(&A, 5);
	push(&A, 0);
	
	printf("\n");
	visual(A);
	printf("\n\n\n");
	
//	pop(&A);
//	pop(&A);
//	pop(&A);
//	push(&A, 99);
//	push(&A, 88);

	

//	int x=0;
//	printf("Is %d present? %d\n", x, isFound(A, x)); 

	Stack EVEN;
	initStack(&EVEN);
	
	EVEN=removeEven(&A);
	printf("\n");
	visual(EVEN);
	printf("\n");
	
	printf("\n");
	visual(A);
	printf("\n");
	
	return 0;
}
