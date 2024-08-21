#include <stdio.h>
#include <stdlib.h>
#include "single.h"

// typedef struct node {
//     int item;
//     struct node *link;
// } NodeType, *NodePtr, *List;

void LLdisplay(List hrf){
	NodeType *curr=hrf;
	
	while(curr!=NULL){
		printf("%d ", curr->item);
		curr=curr->link;
	}
	
}

void LLInsertEND(List *hrf, int data){
	NodeType *neww=malloc(sizeof(NodeType));
	neww->item=data;
	neww->link=NULL;
	
	while(*hrf != NULL){
		hrf=&(*hrf)->link;
	}
	
	*hrf=neww;
	
}

void LLInsertFRONT(List *hrf, int data){
	NodeType *neww=malloc(sizeof(NodeType));
	neww->item=data;
	
	neww->link=*hrf;
	*hrf=neww;
	
}

void LLInsertINTO(List *hrf, int data, int pos){
	NodeType *neww=malloc(sizeof(NodeType));
	neww->item=data;
	
	int count=1;
	
	if(pos==1){
		LLInsertFRONT(hrf, data);
		return;
	}
	
	while(*hrf != NULL && count!=pos-1){
		count++;
		hrf=&(*hrf)->link;
	}
	
	neww->link = (*hrf)->link;
	(*hrf)->link=neww;
	
}

void LLDeleteATPos(List *hrf, int pos){
    int count=1;
    
//    if(pos==1){
//        (*hrf)->link = (*hrf)->link->link;
//    }
    
    while(*hrf != NULL && count!=pos-1){
        count++;
        hrf=&(*hrf)->link;
    }
    
    List delitem = (*hrf)->link;
    
    
    (*hrf)->link=(*hrf)->link->link;
    free(delitem);
}

void LLDeleteOccurence(List *h, int data){
	while(*hrf!=NULL && (*hrf)->data)
}
