#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Queue.h"

//Queue is FIRST IN, FIRST OUT

//typedef struct {
//    Name elems[MAX];
//    int front;
//    int rear;
//} NQueue;

void initNQueue(NQueue *nq){
	nq->front = 1;
	nq->rear = 0;
}

bool isEmpty(NQueue nq){
	return ((nq.rear + 1) % MAX == nq.front) ? true : false;
}

bool isFull(NQueue nq){
	return ((nq.rear + 2) % MAX == nq.front) ? true : false;
}

void displayQueue(NQueue nq){
	printf("\n--------------------------\n");
	while(!isEmpty(nq)){
		printf("%s %s\n", front(nq).fname, front(nq).lname);
		dequeue(&nq);
	}
	printf("--------------------------\n");
}

bool enqueue(NQueue *nq, Name n){
	if(!isFull(*nq)){
		nq->rear = (nq->rear + 1) % MAX;
		nq->elems[nq->rear]=n;
	}
}

bool dequeue(NQueue *nq){
	if(!isEmpty(*nq)){
		nq->front = (nq->front + 1) % MAX;
	}
}

Name front(NQueue nq){
	return nq.elems[nq.front];
}

/*Removes the names that matches the filterString to the lastname. 
  Returns the removed names. Use the concept of adding a sentinel
  at the end indicating the last item in list as empty strings for
  fname and lname. If there are no names that will match then the
  function should return the sentinel.*/
Name *filterNames(NQueue *nq, char *filterString){
	Name *filter = malloc(sizeof(Name) * MAX);
	int i = 0;
	
	while(!isEmpty(*nq)){
		if(strcmp(nq->elems[nq->front].lname, filterString) == 0){
			strcpy(filter[i].fname, nq->elems[nq->front].fname);
			strcpy(filter[i].lname, nq->elems[nq->front].lname);
			++i;
		}
		dequeue(&(*nq));
	}
	
	strcpy(filter[i].fname, " ");
	strcpy(filter[i].lname, " ");
	
	return filter;
}

/*Insert soreted base on lastname. Rember to use the property 
  of the queue but without using the functions (enqueue, dequeue, front)*/
bool insertSorted(NQueue *nq, Name n){
	NQueue temp;
	initNQueue(&temp);
	
	bool isInserted = false; 
	
	if(!isEmpty(*nq)){
		while(!isEmpty(*nq)){
		if(!isInserted && strcmp(nq->elems[nq->front].lname , n.lname) > 0 ){
			temp.rear = (temp.rear + 1) % MAX;
			temp.elems[temp.rear] = n;
			isInserted = true;
		}
			temp.rear = (temp.rear + 1) % MAX;
			temp.elems[temp.rear] = nq->elems[nq->front];
			nq->front = (nq->front + 1) % MAX;
		}
		
		if(!isInserted){
			temp.rear = (temp.rear + 1) % MAX;
			temp.elems[temp.rear] = n;
		}
		
		*nq = temp;
	}else{
		nq->rear = (nq->rear + 1) % MAX;
		nq->elems[nq->rear]=n;
	}
	
}
