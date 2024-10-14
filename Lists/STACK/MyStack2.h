#ifndef MY_STACK2_H
#define MY_STACK2_H

#include <stdbool.h>
#include <string.h>
#define MAX 5

typedef char String[20];

typedef struct{
	String fname, mname, lname;
}Name;

typedef struct{
	int studID;
	Name studName;
	String program;
	int year;
}Student;

typedef struct{
	Student elems[MAX];
	int count;
}Stack2;


void InitStack(Stack2 *s);
Stack2 CreateStack();
bool IsEmpty(Stack2 s);
bool IsFull(Stack2 s);
void visualize(Stack2 s);

bool Push(Stack2 *s, Student stud);
bool Pop(Stack2 *s);
String *Peek(Stack2 s, bool type);

bool IsFound(Stack2 s, String lastname);
Name *getStudentInProgram(Stack2 s, String program);

Name createName(String fname, String mname, String lname);
Student createStudent(int studID, Name studName, String program, int year);


#endif
