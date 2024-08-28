#ifndef STATICARR_H
#define STATICARR_H

#define MAX 10

 typedef struct {
     int items[MAX];
     int count;
 } List;
 
 void display(List l);
 List insertFront(List l, int data);
 List insertEnd(List l, int data);
 List insertINTO(List l, int data, int pos);
 List deleteAtPos(List l, int pos);
 List deleteOccurence(List l, int data);
 List deleteFront(List l);
 List deleteEnd(List l);
 
 #endif
