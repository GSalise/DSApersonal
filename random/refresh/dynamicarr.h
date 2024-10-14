#ifndef DYANMICARR_H
#define DYNAMICARR_H

 typedef struct {
     int *items;
     int count;
     int max;
 } List;
 
 void DAdisplay(List l);
 List DAinsertFRONT(List l, int data);
 List DAinsertEND(List l, int data);
 List DAinsertAtPos(List l, int data, int pos);
 List DAdeleteAtPos(List l, int pos);
 List DAdeleteOccurence(List l, int data);
 List DAdeleteFront(List l);
 List DAdeleteEnd(List l);
 
 #endif
