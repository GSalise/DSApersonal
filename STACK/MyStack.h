#ifndef MY_STACK_H
#define MY_STACK_H

#include <stdbool.h>
#define MAX 5


typedef struct {
	int elems[MAX];
	int count;
}Stack;


void initStack(Stack *s);
Stack createStack();
bool isEmpty(Stack s);
bool isFull(Stack s);

bool push(Stack *s, int data);
bool pop(Stack *s);
int peek(Stack s);

bool isFound(Stack s, int data);
Stack removeEven(Stack *s);

void visual(Stack s);

#endif
