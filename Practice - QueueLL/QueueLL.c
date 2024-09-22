#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "QueueLL.h"

//typedef struct node{
//    Stud student;
//    struct node *head;
//    struct node *tail;
//} NodeType, *NodePtr, Queue;

void initQueue(Queue *q){
	q->head = NULL;
	q->tail = NULL;
}

Queue createQueue(){
	Queue neww;
	initQueue(&neww);
	return neww;
}

bool isEmpty(Queue q){
	return q.head == NULL;
}


void displayQ(Queue q){
	printf("\n-------------\n");
	while(!isEmpty(q)){
		printf("Name: %s %s\n", front(q).studName.fname, front(q).studName.lname);
		printf("Course and Year: %s-%d\n\n", front(q).course, front(q).year);
		dequeue(&q);
	}
	printf("-------------\n");
}

void makeNull(Queue *q){
	while(!isEmpty(*q)){
		dequeue(q);
	}
}

bool enqueue(Queue *q, Stud s){
	NodePtr neww = malloc(sizeof(NodeType));
	neww->student = s;
	neww->next = NULL;
	neww->prev = NULL;
	
	if(isEmpty(*q)){
		q->head = neww;
		q->tail = neww;
	}else{
		q->tail->next = neww;
		neww->prev = q->tail;
		q->tail = neww;
	}
	
	
}

bool dequeue(Queue *q){
	q->head = q->head->next;
}

Stud front(Queue q){
	return q.head->student;
}

int compareName(Name n1, Name n2){
	int res;
	res = strcasecmp(n1.lname, n2.lname);
	return (res != 0) ? res : strcasecmp(n1.fname, n2.fname);
	
}


// pending
void sortQ(Queue *q){
	
	
}


void insertSorted(Queue *q, Stud s){
	Queue temp;
	initQueue(&temp);
	NodePtr neww = malloc(sizeof(NodeType));
	neww->student = s;
	neww->next = NULL;
	neww->prev = NULL;
	
	
	if(!isEmpty(*q)){
		
		/* 
			- Placing the first item in the temp queue -
			
			checks first if the s.studName is alphabetically higher
			if true then temp.head/tail will be neww
			else temp.head/tail will be q->head
		*/
		
		if(compareName(q->head->student.studName, s.studName) > 0){
			temp.head = neww;
			temp.tail = neww;
		}else{
			temp.head = q->head;
			temp.tail = q->head;
			q->head = q->head->next;
			temp.head->next = NULL;
		}
		
		/*
			Continously enqueues q->head to temp.tail
			until q->head is alphabetically lower than neww or q->head is empty
			once found places neww at the tail
			and finishes the rest of the q->head if it's not empty
		*/

		while(!isEmpty(*q) && compareName(q->head->student.studName, s.studName) < 0){
			temp.tail->next = q->head;
			q->head->prev = temp.tail;
			temp.tail = q->head;
			q->head = q->head->next;				
		}
		
		temp.tail->next = neww;
		neww->prev = temp.tail;
		temp.tail = neww;
		
		while(!isEmpty(*q)){
			temp.tail->next = q->head;
			q->head->prev = temp.tail;
			temp.tail = q->head;
			q->head = q->head->next;				
		}
		
		*q = temp;
		
	}else{
		q->head = neww;
		q->tail = neww;
	}
	
	
}

Stud makeStud(Name studname, int year, char *course, char gender){
	Stud neww;
	neww.year = year;
	neww.studName = studname;
	strcpy(neww.course, course);
	neww.gender = gender;
	
	return neww;
}

Name makeName(char *F, char *L){
	Name neww;
	strcpy(neww.fname, F);
	strcpy(neww.lname, L);
	
	return neww;
}
