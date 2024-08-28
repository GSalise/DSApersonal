#include <stdio.h>
#include <stdbool.h>
#include "MyStack.h"

void initStack(Stack *s){
	(*s).count=0;
}

Stack createStack(){
	Stack neww;
	neww.count=0;
}

bool isEmpty(Stack s){
	if(s.count==0){
		return true;
	}
	return false;
}

bool isFull(Stack s){
	if(s.count==MAX){
		return true;
	}
	return false;
}

bool push(Stack *s, int data){
	if(!isFull(*s)){
		(*s).elems[(*s).count]=data;
		(*s).count++;
	}
	
	
}

bool pop(Stack *s){
	if(!isEmpty(*s)){
		(*s).count--;
	}
}

int peek(Stack s){
	return s.elems[(s.count)-1];
}

bool isFound(Stack s, int data){
	while(!isEmpty(s)){
		if(peek(s) == data){
			return true;
		}
		pop(&s);
	}
	return false;
}

Stack removeEven(Stack *s){
	Stack even;
	initStack(&even);
	Stack temp;
	initStack(&temp);
	
	while(!isEmpty(*s)){
		if(peek(*s)%2==0){
			push(&even, peek(*s));
		}else{
			push(&temp, peek(*s));
		}
		pop(s);
	}
	
	while(!isEmpty(temp)){
		push(s, peek(temp));
		pop(&temp);
	}
	
	
	return even;
}

void visual(Stack s){
	for(int i=0; i<s.count; i++){
		printf("%d ", s.elems[i]);
	}
}
