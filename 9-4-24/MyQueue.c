#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "MyData.h"
#include "MyQueue.h"

void initQueue(Queue *q){
	q->head=NULL;
	q->tail=NULL;
}

Queue createQueue(){
	Queue neww;
	neww.head = NULL;
	neww.tail = NULL;
	
	return neww;
}

bool isEmpty(Queue q){
	return q.head == NULL;
}

void makeNull(Queue *q){
	while(!isEmpty(*q)){
		NodeType *delitem;
		delitem = q->head;
		q->head=q->head->link;
		free(delitem);
	}
}

void display(Queue q){
	while(!isEmpty(q)){
		printf("%s ", q.head->elem.studName.lname);
		NodeType *delitem;
		delitem = q.head;
		q.head=q.head->link;
		free(delitem);
	}
	
}

void visualize(Queue q){
	while(q.head!=NULL){
		printf("%s ", q.head->elem.studName.lname);
		q.head=q.head->link;
	}
	
}

bool enqueue(Queue *q, Data d){

	NodePtr neww = malloc(sizeof(NodeType));
	neww->elem = d;
	neww->link=NULL;
	
	
	if(!isEmpty(*q)){
		q->tail->link=neww;
		q->tail=q->tail->link;
	}else{
		q->head = neww;
		q->tail = neww;
	}
		
	
}

bool dequeue(Queue *q){
	if(!isEmpty(*q)){
		NodeType *delitem;
		delitem = q->head;
		q->head=q->head->link;
		free(delitem);
	}
	
}

Data front(Queue q){
	return q.head->elem;
}

Name *getStudent(Queue q, char *program, char sex){
	
	Name *stud = malloc(10 * sizeof(Name));
	int i=0;
	
	if((strcmp(program, " ")!=0) && sex != ' '){
		while(q.head!=NULL){
			if(q.head->elem.sex == sex && strcmp(q.head->elem.program, program) == 0){
				stud[i] = q.head->elem.studName;
				i++;
			}
			dequeue(&q);
		}
	}
	
	
	if(strcmp(program, " ") == 0){
		while(q.head!=NULL){
			if(q.head->elem.sex == sex){
				stud[i]=q.head->elem.studName;
				i++;
			}
			dequeue(&q);
		}
	}else if(sex = ' '){
		while(q.head!=NULL){
			if(strcmp(q.head->elem.program, program) == 0){
				stud[i]=q.head->elem.studName;
				i++;
			}
			dequeue(&q);
		}
	} 
	
	strcpy(stud[i].fname, " ");
	strcpy(stud[i].lname, " "); 
	
	return stud;
}

bool insertSorted(Queue *q, Data d){
	Queue temp;
	initQueue(&temp);
	
	if(isEmpty(*q)){
		enqueue(q, d);
	}else{
		while(!isEmpty(*q) && strcmp(q->head->elem.studName.lname, d.studName.lname) < 0){
			if(strcmp(q->head->elem.studName.lname, d.studName.lname) < 0){
				enqueue(&temp, q->head->elem);
				dequeue(q);
			}
		}
		enqueue(&temp, d);
		
		while(!isEmpty(*q)){
			enqueue(&temp, q->head->elem);
			dequeue(q);
		}
		
		*q = temp;
	}
	

	
	
}
