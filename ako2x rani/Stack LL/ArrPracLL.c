#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ArrPracLL.h"

void initS(Stack *S){
	*S = NULL;
}

void push(Stack *S, Stud s){
	NodePtr neww = malloc(sizeof(NodeType));
	neww->link = NULL;
	neww->student = s;
	
	neww->link = *S;
	*S = neww;
	
}

void pop(Stack *S){
	if(!isEmpty(*S)){
		*S = (*S)->link;
	}
}

bool isEmpty(Stack S){
	return S == NULL;
}

void display(Stack S){
	printf("\n------------\n");
	while(!isEmpty(S)){
		printf("Name: %s %s\n", peek(S).studName.fname, peek(S).studName.lname);
		pop(&S);
	}
	printf("------------\n");
}

Stud peek(Stack S){
	return S->student;
}

Stack createS(){
	Stack neww;
	neww->link = NULL;
	return neww;
}

void insertSorted(Stack *S, Stud s){
	Stack temp;
	initS(&temp);
	NodePtr neww = malloc(sizeof(NodeType));
	neww->student = s;
	NodePtr hold;
	

	
	if(!isEmpty(*S)){
		if(compareName((*S)->student.studName, s.studName) > 0){
			neww->link = *S;
			*S = neww;
			
		}else{
			
			while(!isEmpty(*S) && compareName((*S)->student.studName, s.studName) < 0){
				hold = *S;
				*S = (*S)->link;
				hold->link = temp;
				temp = hold;
			}
			
			neww->link = *S;
			*S = neww;
			
			while(!isEmpty(temp)){
				hold = temp;
				temp = temp->link;
				hold->link = *S;
				*S = hold;
			}
			
		}
		
		
	}else{
		neww->link = *S;
		*S = neww;
	}
	
	
	
	
}

int compareName(Name n1, Name n2){
	int res = strcasecmp(n1.lname, n2.lname);
	
	return (res != 0) ? res : strcasecmp(n1.fname, n2.fname);
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
