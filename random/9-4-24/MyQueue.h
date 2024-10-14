#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

typedef Student Data;

typedef struct node{
	Data elem;
	struct node *link;
}NodeType, *NodePtr;

typedef struct{
	NodePtr head, tail;
}Queue;

void initQueue(Queue *q);
Queue createQueue();
bool isEmpty(Queue q);
bool isFull(Queue q);
void makeNull(Queue *q);
void display(Queue q);
void visualize(Queue q);

bool enqueue(Queue *q, Data d);
bool dequeue(Queue *q);
Data front(Queue q);

Name *getStudent(Queue q, char *program, char sex);
bool insertSorted(Queue *q, Data d);

#endif
