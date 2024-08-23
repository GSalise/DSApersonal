#ifndef DOUBLY_H
#define DOUBLY_H

 typedef struct node {
     int item;
     struct node *next, *prev;
 } NodeType, *NodePtr, *List;
 
 void DDdisplay(List *hrf, List *trf);
 void DDInsertEND(List *hrf, List *trf, int data);
 void DDInsertFRONT(List *hrf, List *trf, int data);
 void DDInsertINTO(List *hrf, List *trf, int data, int pos);
 void DDDeleteAtPos(List *hrf, List *trf, int pos);
 void DDdeleteOccurence(List *hrf, List *trf, int data);
 void DDdeleteFRONT(List *hrf);
 void DDdeleteEND(List *trf);
 
#endif
