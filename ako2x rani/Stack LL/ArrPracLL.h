#ifndef ARRPRACLL_H
#define ARRPRACLL_H

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
    struct node *link;
} NodeType, *NodePtr, *Stack;

void initS(Stack *S);
void push(Stack *, Stud s);
void pop(Stack *);
bool isEmpty(Stack S);
void display(Stack);
Stud peek(Stack);
Stack createS();

void insertSorted(Stack *, Stud s);

int compareName(Name, Name);
Stud makeStud(Name, int, char *, char);
Name makeName(char *, char *);

#endif
