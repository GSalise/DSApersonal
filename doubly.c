#include <stdio.h>
#include <stdlib.h>
#include "doubly.h"

// typedef struct node {
//     int item;
//     struct node *next, *prev;
// } NodeType, *NodePtr, *List;

void DDdisplay(List *hrf){
	printf("Forward\n");
	while(*hrf!=NULL){
		printf("%d ", (*hrf)->item);
		if((*hrf)->next==NULL){
			printf("\n\n");
			printf("Backward\n");
			while(*hrf!=NULL){
				printf("%d ", (*hrf)->item);
				hrf=&(*hrf)->prev;
			} 
			return;
		}
		hrf=&(*hrf)->next;
	}
//	printf("\n\nBackward\n");
//	while(*hrf!=NULL){
//		printf("%d ", (*hrf)->item);
//		hrf=&(*hrf)->prev;
//	}
}

void DDInsertEND(List *hrf, List *trf, int data){
    NodeType *neww=malloc(sizeof(NodeType));
    neww->item=data;
    neww->next=NULL;
    neww->prev=NULL;
    List *temp;
    
    while(*hrf!=NULL){
        *temp=(*hrf);
        hrf=&(*hrf)->next;
    }
    neww->prev=*temp;
    *trf=neww;
    *hrf=neww;



	
    
    
}

void DDInsertFRONT(List *hrf, List *trf, int data){
	NodeType *neww=malloc(sizeof(NodeType));
	neww->item=data;
	neww->prev=NULL;
	neww->next=*hrf;
	(*hrf)->prev=neww;
	*hrf=neww;
}

void DDInsertINTO(List *hrf, int data, int pos){
	NodeType *neww=malloc(sizeof(NodeType));
	neww->item=data;
	neww->next=NULL;
	neww->prev=NULL;
	int count=1;
	while(*hrf!=NULL && count!=pos-1){
		hrf=&(*hrf)->next;
		count++;
	}
//	printf("[[%d]]", ((*hrf)->next->item));
	neww->next=((*hrf)->next);
	neww->prev=*hrf;
	(*hrf)->next->prev=neww;
	(*hrf)->next=neww;
	
	
}

