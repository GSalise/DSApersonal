#include <stdio.h>
#include <stdlib.h>
//#include "staticarr.h"
//#include "dynamicarr.h"
//#include "single.h"
#include "doubly.h"

int main(){
	
	//STATIC ARRAY
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

	//DYNAMIC ARRAY 
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
	
	//Singly LL
//	List test=NULL;
//	LLInsertEND(&test, 10);
//	LLInsertEND(&test, 20);
//	LLInsertEND(&test, 30);
//	LLInsertFRONT(&test, 99);
//	LLInsertFRONT(&test, 88);
//	LLInsertFRONT(&test, 77);
//	LLInsertINTO(&test, 0, 3);
//	LLInsertINTO(&test, 0, 2);
//	LLInsertINTO(&test, 0, 5);
//	LLInsertEND(&test, 0);
//	LLInsertFRONT(&test, 1);
//	LLDeleteATPos(&test, 1);
//	LLDeleteOccurence(&test, 0);
//	LLdeleteFRONT(&test);
//	LLdeleteEND(&test);
//	LLdisplay(test);
	
	//Doubly LL
	List head=NULL;
	List tail=NULL;
	DDInsertEND(&head, &tail, 10);
	DDInsertEND(&head, &tail, 20);
	DDInsertEND(&head, &tail, 30);
	DDInsertFRONT(&head, &tail, 0);
	DDInsertFRONT(&head, &tail, 1);
	DDInsertFRONT(&head, &tail, 2);
	DDInsertEND(&head, &tail, 0);
	DDInsertINTO(&head, &tail, 99, 5);
	DDInsertINTO(&head, &tail, 88, 4);
	DDInsertINTO(&head, &tail, 0, 3);
	DDInsertINTO(&head, &tail, 0, 7);
	DDInsertINTO(&head, &tail, 0, 5);
	DDInsertFRONT(&head, &tail, 0);
	DDDeleteAtPos(&head, &tail, 6);
	DDdeleteOccurence(&head, &tail, 0);
	DDdeleteFRONT(&head);
	DDdeleteEND(&tail);
	DDInsertINTO(&head, &tail, 100, 2);
	DDdisplay(&head, &tail);
	
	
	return 0;
}

