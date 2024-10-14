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
	char gender;
}Stud;

typedef struct node{
    Stud student;
    struct node *next;
    struct node *prev;
} NodeType, *NodePtr;

typedef struct{
	NodePtr head;
	NodePtr tail;
}Queue;

//expected func
void initQueue(Queue *q);
Queue createQueue();
bool isEmpty(Queue q);
void displayQ(Queue q);
void makeNull(Queue *q);

bool enqueue(Queue *q, Stud s);
bool dequeue(Queue *q);
Stud front(Queue q);


int compareName(Name, Name);
void sortQ(Queue *q);
void insertSorted(Queue *q, Stud s);

//make
Stud makeStud(Name, int, char *, char);
Name makeName(char *, char *);

#endif
