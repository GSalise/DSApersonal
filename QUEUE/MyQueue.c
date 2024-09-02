#include <stdio.h>
#include <stdlib.h>
#include "MyQueue.h"

void initQueue(Queue *q){
	q->front=1;
	q->rear=0;
}

Queue createQueue(){
	Queue neww;
	neww.front=1; 
	neww.rear=0;
	return neww;
}

bool isEmpty(Queue q){
	return q.front == (q.rear + 1) % MAX;
}

bool isFull(Queue q){
	return q.front == (q.rear + 2) % MAX;
}

void displayQ(Queue q){
	while(!isEmpty(q)){
		printf("%d ", front(q)); 
		dequeue(&q);
	}
}

bool enqueue(Queue *q, int item){
	if(!isFull(*q)){
		q->rear = (q->rear + 1) % MAX;
		q->elems[q->rear] = item;
	}
}

bool dequeue(Queue *q){
	if(!isEmpty(*q)){
		q->front = (q->front + 1) % MAX;
	}
}
 
int front(Queue q){
	return q.elems[q.front];
}

