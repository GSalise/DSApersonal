#ifndef SINGLE_H
#define SINGLE_H

 typedef struct node {
     int item;
     struct node *link;
 } NodeType, *NodePtr, *List;

void LLdisplay(List hrf);
void LLInsertEND(List *hrf, int data);
void LLInsertFRONT(List *hrf, int data);
void LLInsertINTO(List *hrf, int data, int pos);
void LLDeleteATPos(List *hrf, int pos);
void LLDeleteOccurence(List *h, int data);
void LLdeleteFRONT(List *hrf);
void LLdeleteEND(List *hrf);

#endif
