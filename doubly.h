#ifndef DOUBLY_H
#define DOUBLY_H

 typedef struct node {
     int item;
     struct node *next, *prev;
 } NodeType, *NodePtr, *List;
 
 void DDdisplay(List *hrf);
 void DDInsertEND(List *hrf, List *trf, int data);
 void DDInsertFRONT(List *hrf, List *trf, int data);
 void DDInsertINTO(List *hrf, int data, int pos);
 
#endif
