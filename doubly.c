#include <stdio.h>
#include <stdlib.h>
#include "doubly.h"

// typedef struct node {
//     int item;
//     struct node *next, *prev;
// } NodeType, *NodePtr, *List;

void DDdisplay(List *hrf, List *trf){
	NodeType *curr=*hrf;
	printf("Forward:\n");
	while(curr!=NULL){
		printf("%d ", curr->item);
		curr=curr->next;
	}
	curr=*trf;
	printf("\n\nBackward:\n");
	while(curr!=NULL){
		printf("%d ", curr->item);
		curr=curr->prev;
	}
	printf("\n\n");
	
	
}

void DDInsertEND(List *hrf, List *trf, int data){
	NodeType *neww=malloc(sizeof(NodeType));
	neww->item=data;
	neww->next=NULL;
	neww->prev=NULL;
	
	if(*hrf==NULL && *trf==NULL){
		*hrf=neww;
		*trf=neww;
	}else{
		(*trf)->next=neww;
		neww->prev=*trf;
		*trf=neww;
	}


	
    
    
}

void DDInsertFRONT(List *hrf, List *trf, int data){
	NodeType *neww=malloc(sizeof(NodeType));
	neww->item=data;
	neww->prev=NULL;
	neww->next=NULL;
	
	if(*hrf==NULL && *trf==NULL){
		*hrf=neww;
		*trf=neww;
	}else{
		(*hrf)->prev=neww;
		neww->next=*hrf;
		*hrf=neww;
	}
	
	
}

void DDInsertINTO(List *hrf, List *trf, int data, int pos){
	NodeType *neww=malloc(sizeof(NodeType));
	neww->item=data;
	neww->next=NULL;
	neww->prev=NULL;
	int count=1;
	
	if(*hrf==NULL && *trf==NULL){
		*hrf=neww;
		*trf=neww;
	}else{
//		while(*hrf!=NULL && count!=pos-1){
//			hrf=&(*hrf)->next;
//			count++;
//		}
//		neww->next=((*hrf)->next);
//		neww->prev=*hrf;
//		(*hrf)->next->prev=neww;
//		(*hrf)->next=neww;

		if(pos==1){
			neww->next=*hrf;
			(*hrf)->prev=neww;
			*hrf=neww;
		}else{
			while(*hrf!=NULL && count!=pos-1){
				hrf=&(*hrf)->next;
				count++;
			}
			if(*hrf==*trf){
				neww->prev=*trf;
				(*trf)->next=neww;
				*trf=neww;
			}else{
				neww->next=((*hrf)->next);
				neww->prev=*hrf;
				(*hrf)->next->prev=neww;
				(*hrf)->next=neww;
			}
		}
		
		
		
		
	}
	
	
}

void DDDeleteAtPos(List *hrf, List *trf, int pos){
	int count=1;
	List delitem;
	
	while(*hrf!=NULL && count!=pos){
		hrf=&(*hrf)->next;
		count++;
	}

	if(pos==1){
		delitem=*hrf;
		*hrf=delitem->next;
		(*hrf)->prev=NULL;
		free(delitem);
	}else if(*hrf==*trf){
		delitem=*trf;
		*trf=delitem->prev;
		(*trf)->next=NULL;
		free(delitem);
	}else{
		delitem=*hrf; 
		delitem->prev->next=delitem->next;
		delitem->next->prev=delitem->prev;
		free(delitem);
	}

	
	
}

void DDdeleteOccurence(List *hrf, List *trf, int data){
	NodeType *delitem;
	List F=*hrf;
	
	while(*hrf!=NULL){
		if((*hrf)->item == data){
			if(F==*hrf){
				delitem = (*hrf);
				(*hrf)=delitem->next;
				(*hrf)->prev=NULL;
				free(delitem);
			}else if(*hrf==*trf){
				delitem = (*trf);
				(*trf)=delitem->prev;
				(*trf)->next=NULL;
				free(delitem);
			}else{
				delitem = (*hrf);
				delitem->next->prev=delitem->prev;
				delitem->prev->next=delitem->next;
				free(delitem);
			}
		}else{
			hrf=&(*hrf)->next;
		}
		
	}
}

void DDdeleteFRONT(List *hrf){
	List delitem;
	delitem=*hrf;
	*hrf=delitem->next;
	(*hrf)->prev=NULL;
	free(delitem);
}

void DDdeleteEND(List *trf){
	List delitem;
	delitem=*trf;
	*trf=delitem->prev;
	(*trf)->next=NULL;
	free(delitem);
}



