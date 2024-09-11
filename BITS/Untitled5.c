#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MyBits.h"

int main(){
	Set A, B, C, D, E, F, G;
	
	A=createSet();
	addElement(&A, 5);//
	addElement(&A, 6);
	addElement(&A, 3);
	addElement(&A, 2);
	addElement(&A, 0);
	addElement(&A, 13);//
	displaySet(A);
	B=createSet();
	addElement(&B, 5);//
	addElement(&B, 10);
	addElement(&B, 7);
	addElement(&B, 8);
	addElement(&B, 9);
	addElement(&B, 13);//
	addElement(&B, 1);
	printf("\n");
	displaySet(B);
	
	
	C=unionSet(A, B);
	printf("\n");
	displaySet(C);
	
	D=intersectionSet(A,B);
	printf("\n");
	displaySet(D);
	
	E=differenceSet(A,B);
	printf("\n");
	displaySet(E);
	
	F=differenceSet(B,A);
	printf("\n");
	displaySet(F);
	
	G=symmetricDifferenceSet(A,B);
	printf("\n");
	displaySet(G);
	
	
	printf("\n");
	printf("\n");
	printf("\n");
	
	printf("%d - A cardinality\n%d - B cardinality", cardinality(A), cardinality(B));
	
	printf("\n");
	printf("\n");
	printf("\n");
	
	printf("Is %d present? %d", 10, isElement(B, 10));
	
		
	
	
	
	return 0;
}
