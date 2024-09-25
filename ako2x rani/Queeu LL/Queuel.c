#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Queuel.h"

//expected func
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
	printf("\n------------\n");
	while(!isEmpty(q)){
		printf("Name: %s %s\n", front(q).studName.fname, front(q).studName.lname);
		dequeue(&q);
	}
	printf("------------\n");
}

void makeNull(Queue *q){
	
}

bool enqueue(Queue *q, Stud s){
	NodePtr neww = malloc(sizeof(NodeType));
	neww->student = s;
	neww->link = NULL;
	
	if(isEmpty(*q)){
		q->head = neww;
		q->tail = neww;
	}else{
		q->tail->link = neww;
		q->tail = neww;
	}
}

bool dequeue(Queue *q){
	q->head = q->head->link;	
}

Stud front(Queue q){
	return q.head->student;
}


int compareName(Name n1, Name n2){
	int res = strcasecmp(n1.lname, n2.lname);
	
	return (res != 0) ? res : strcasecmp(n1.fname, n2.fname);
}

void sortQ(Queue *q){
	
}

void insertSorted(Queue *q, Stud s){
	Queue temp;
	initQueue(&temp);
	
	NodePtr neww = malloc(sizeof(NodeType));
	neww->link = NULL;
	neww->student = s;

	//DO NOT FUCKING USE NODEPTR HOLD, q->head->link does the job itself
	
	if(!isEmpty(*q)){
		if(compareName(q->head->student.studName, s.studName) > 0){
			temp.head = neww;
			temp.tail = neww;
						
			while(!isEmpty(*q)){
				temp.tail->link = q->head;
				temp.tail = q->head;
				q->head = q->head->link;
			}
		}else{
			temp.head = q->head;
			temp.tail = q->head;
			q->head = q->head->link;
			
			while(!isEmpty(*q) && compareName(q->head->student.studName, s.studName) < 0){
				
				temp.tail->link = q->head;
				temp.tail = q->head;
				q->head = q->head->link;
			}
			
			temp.tail->link = neww;
			temp.tail = neww;
			
			while(!isEmpty(*q)){
				temp.tail->link = q->head;
				temp.tail = q->head;
				q->head = q->head->link;
			}
			
		}
			
			
			
			
			
			
			*q = temp;
		
	}else{
		q->head = neww;
		q->tail = neww;
	}
	
	
	
}

Name *findStudent(Queue *q, char* name){
	
}

//make
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
