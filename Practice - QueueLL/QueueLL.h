#ifndef QUEUELL_H
#define QUELELL_H


typedef struct {
    char fname[30];
    char lname[30];
} Name;

typedef struct{
	Name studName;
	int year;
	char course[10];
	bool gender;
}Stud;

typedef struct node{
    Stud student;
    struct node *head;
    struct node *tail;
} NodeType, *NodePtr, Queue;

void initQueue(Queue *q);
Queue createQueue();
bool isEmpty(Queue q);
bool isFull(Queue q);
void displayQ(Queue q);

bool enqueue(Queue *q, Stud s);
bool dequeue(Queue *q);
int front(Queue q);

#endif
