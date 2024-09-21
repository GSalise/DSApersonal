#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Queue.h"


int main(){
	Name a;
	Name b;
	Name c;
	Name d;
	Name e;
	
	strcpy(a.fname, "George");
	strcpy(a.lname, "AA");
	
	strcpy(b.fname, "Adriane");
	strcpy(b.lname, "CC");
	
	strcpy(c.fname, "Mark");
	strcpy(c.lname, "FF");
	
	strcpy(d.fname, "Joel");
	strcpy(d.lname, "BB");
	
	strcpy(e.fname, "Test");
	strcpy(e.lname, "EE");

	//abcde
	NQueue A;
	initNQueue(&A);
	printf("Is A Empty? %d\n", isEmpty(A));
	printf("Is A Full? %d\n", isFull(A));
//	enqueue(&A, a);
//	enqueue(&A, b);
//	enqueue(&A, c);
//	enqueue(&A, d);
//	enqueue(&A, e);
	insertSorted(&A, a);
	displayQueue(A);
	insertSorted(&A, b);
	displayQueue(A);
	insertSorted(&A, c);
	displayQueue(A);
	insertSorted(&A, d);
	displayQueue(A);
	insertSorted(&A, e);
	displayQueue(A);
	
//	Name *filtered = filterNames(&A, "Salise");
//	
//	printf("\n--------------------------\n");
//	for(int i = 0; strcmp(filtered[i].fname, " ") != 0; i++){
//		printf("%s %s\n", filtered[i].fname, filtered[i].lname);
//	}
//	printf("--------------------------\n");
	
//	printf("\n\n\n");
//	insertSorted(&A, e);
//	displayQueue(A);
	
	
	return 0;
}
