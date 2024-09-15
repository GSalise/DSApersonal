#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

//typedef struct node{
//    Person data;
//    struct node *link;
//} NodeType, *NodePtr, *Stack;

void initStack(Stack *s){
	*s = NULL;
}

bool isEmpty(Stack s){
	return (s==NULL) ? true : false;
}

void displayStack(Stack s){
	printf("\n\n----------------------\n");
	while(!isEmpty(s)){
		printf("%s - %c - %d\n", peek(s).name, peek(s).sex, peek(s).age);
		pop(&s);
	}
	printf("----------------------\n");
}

bool push(Stack *s, Person p){
	NodePtr neww = malloc(sizeof(NodeType));
	neww->data = p;
	neww->link = NULL;
	
	if(!isEmpty(*s)){
		neww->link = *s;
		*s = neww;
	}else{
		*s = neww;
	}
}

bool pop(Stack *s){
	if(!isEmpty(*s)){
		*s = (*s)->link;
	}
}

Person peek(Stack s){
	return s->data;
}

/*Insert sorted base on lastname. Rember to use the property 
  of the stack using push, pop, and peek functions.*/
bool insertSorted1(Stack *s, Person p){
	Stack temp;
	temp=NULL;
	
	if(!isEmpty(*s)){
		if(strcmp(peek(*s).name, p.name) < 0){
			
			while(!isEmpty(*s) && strcmp(peek(*s).name, p.name) < 0){
				push(&temp, peek(*s));
				pop(s);
			}
			push(s, p);
			while(!isEmpty(temp)){
				push(s, temp->data);
				pop(&temp);
			}	
		}else{
			push(s, p);
		}
	}else{
		push(s, p);
	}
	
}

/*Insert sorted base on lastname. Rember to use the property 
  of the stack but without using push, pop, and peek functions.*/
bool insertSorted2(Stack *s, Person p){
	Stack temp;
	initStack(&temp);
	
	NodePtr holder;
	
	if(!isEmpty(*s)){
		
		if(strcmp((*s)->data.name, p.name) < 0){
			
			while(!isEmpty(*s) && strcmp((*s)->data.name, p.name) < 0){
				
				holder = malloc(sizeof(NodeType));
				holder->data = (*s)->data;
				holder->link=NULL; 

				if(isEmpty(temp)){
					temp = holder;
				}else{
					holder->link = temp;
					temp = holder;
				}
				
				holder = NULL;
				*s = (*s)->link;
				
			}
			
			holder = malloc(sizeof(NodeType));
			holder->data = p;
			holder->link = *s;
			*s = holder;
			
			
			while(!isEmpty(temp)){
				holder = NULL;
				holder = malloc(sizeof(NodeType));

				holder->data=temp->data;
				holder->link = *s;
				
				*s = holder;
				temp = temp->link;
			}	
			
		}else{
			holder = malloc(sizeof(NodeType));
			holder->data = p;
			holder->link = *s;
			*s = holder;
		}
	
	}else{
		holder = malloc(sizeof(NodeType));
		holder->data = p;
		holder->link = NULL;
		*s = holder;
	}
	
	
}

/*Sort the values based on name. Use flag for ascending 
  or descending. */
void sortStack(Stack *s, bool flag){
	Stack temp;
	temp=NULL;
//	(flag == 1) ? (strcmp(peek(*s).name, peek(temp).name) < 0 : (strcmp(peek(*s).name, peek(temp).name) > 0
	
	push(&temp, peek(*s));
	pop(s);

	while(!isEmpty(*s)){
		
		if(((flag == 1) ? (strcmp(peek(*s).name, peek(temp).name)) < 0 : (strcmp(peek(*s).name, peek(temp).name)) > 0)){
			Person DD = peek(*s);
			pop(s);
			while(!isEmpty(temp) && ((flag == 1) ? (strcmp(DD.name, peek(temp).name)) < 0 : (strcmp(DD.name, peek(temp).name)) > 0)){
				push(s, peek(temp));
				pop(&temp);
			}
			push(&temp, DD);
		}else{
			push(&temp, peek(*s));
			pop(s);
		}
		
	}
	
	*s = temp;
	
	
	
	
	
	
	
	
}












