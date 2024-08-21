#include <stdio.h>
#include <stdlib.h>
//#include "staticarr.h"
//#include "dynamicarr.h"
#include "single.h"

int main(){
//	List test;
//	test.count=0;
//	
//	display(test);
//	test=insertFront(test, 10);
//	test=insertFront(test, 20);
//	test=insertFront(test, 30);
//	test=insertEnd(test, 99);
//	test=insertINTO(test, 0, 2);
//	display(test);
//	test=deleteAtPos(test, 2);
//	test=insertFront(test, 30);
//	test=insertFront(test, 80);
//	test=insertFront(test, 30);
//	test=deleteOccurence(test, 30);
//	test=deleteFront(test);
//	test=deleteEnd(test);
//	display(test);

//	List test;
//	test.count=0;
//	DAdisplay(test);
//	test=DAinsertFRONT(test, 10);
//	test=DAinsertFRONT(test, 20);
//	test=DAinsertFRONT(test, 30);
//	test=DAinsertFRONT(test, 10);
//	test=DAinsertEND(test, 10);
//	test=DAinsertEND(test, 99);
//	test=DAinsertEND(test, 88);
//	test=DAinsertAtPos(test, 0, 2);
//	test=DAinsertAtPos(test, 10, 5);
//	test=DAdeleteAtPos(test, 3);
//	test=DAdeleteOccurence(test, 10);
//	test=DAdeleteFront(test);
//	test=DAdeleteEnd(test);
//	DAdisplay(test);
	
	
	List test=NULL;
	LLInsertEND(&test, 10);
	LLInsertEND(&test, 20);
	LLInsertEND(&test, 30);
	LLInsertFRONT(&test, 99);
	LLInsertFRONT(&test, 88);
	LLInsertFRONT(&test, 77);
	LLInsertINTO(&test, 0, 3);
	LLDeleteATPos(&test, 3);
	LLdisplay(test);
	
	
	
	return 0;
}
// typedef struct {
//     int items[MAX];
//     int count;
// } List;


// typedef struct {
//     int *items;
//     int count;
//     int max;
// } List;


// typedef struct node {
//     int item;
//     struct node *link;
// } NodeType, *NodePtr, *List;


// typedef struct node {
//     int item;
//     struct node *next, *prev;
// } NodeType, *NodePtr, *List;
