#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Queue.h"

void initNQueue(NQueue *nq){
	nq->front = 1;
	nq->rear = 0;
}

bool isEmpty(NQueue nq){
	return (nq.rear + 1) % MAX	== nq.front;
}

bool isFull(NQueue nq){
	return (nq.rear + 2) % MAX == nq.front;
}

void displayQueue(NQueue nq){
	printf("\n---------------\n");
	while(!isEmpty(nq)){
		printf("%s - %s\n", front(nq).fname, front(nq).lname);
		dequeue(&nq);
	}
	printf("---------------\n");
}

bool enqueue(NQueue *nq, Name n){
	if(!isFull(*nq)){
		nq->rear = (nq->rear + 1) % MAX;
		nq->elems[nq->rear] = n;
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
	Name *neww = malloc(sizeof(Name) * 5);
	
	int i=0;
	
	while(!isEmpty(*nq)){
		if(strcmp(front(*nq).lname, filterString) == 0){
			neww[i] = front(*nq);
			i++;
		}
		dequeue(nq);
	}
	
	
	strcpy(neww[i].fname, "Sentinel");
	strcpy(neww[i].lname, "Sentinel");
	
	return neww;
}

/*Insert soreted base on lastname. Rember to use the property 
  of the queue but without using the functions (enqueue, dequeue, front)*/
bool insertSorted(NQueue *nq, Name n){
	NQueue temp;
	initNQueue(&temp);
	
	if(!isEmpty(*nq)){
		while(!isEmpty(*nq) && strcmp(nq->elems[nq->front].lname, n.lname) < 0){
			temp.rear = (temp.rear + 1) % MAX;
			temp.elems[temp.rear] = nq->elems[nq->front];
			nq->front = (nq->front + 1) % MAX;
		}
		
		temp.rear = (temp.rear + 1) % MAX;
		temp.elems[temp.rear] = n;
		
		while(!isEmpty(*nq)){
			temp.rear = (temp.rear + 1) % MAX;
			temp.elems[temp.rear] = nq->elems[nq->front];
			nq->front = (nq->front + 1) % MAX;
		}	
		
		*nq = temp;
	}else{
		nq->rear = (nq->rear + 1) % MAX;
		nq->elems[nq->rear] = n; 
	}
	
	
}
