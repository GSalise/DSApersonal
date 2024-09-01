#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "MyStack2.h"


//typedef struct{
//	String fname, mname, lname;
//}Name;
//
//typedef struct{
//	int studID;
//	Name studName;
//	String program;
//	int year;
//}Student;
//
//typedef struct{
//	Student elems[MAX];
//	int count;
//}Stack;


void InitStack(Stack2 *s){
	(*s).count=0;
}

Stack2 CreateStack(){
	Stack2 neww;
	neww.count=0;
	
	return neww;
}

bool IsEmpty(Stack2 s){
	if(s.count == 0){
		return true;
	}
	return false;
}

bool IsFull(Stack2 s){
	if(s.count >= MAX){
		return true;
	}
	return false;
}

void visualize(Stack2 s){
	for(int i=0; i<s.count; i++){
		printf("| %d - %s - %s ", s.elems[i].studID, s.elems[i].studName.fname, s.elems[i].studName.lname);
	}
}

bool Push(Stack2 *s, Student stud){
	if(!IsFull(*s)){
		s->elems[s->count]=stud;
		s->count++;
	}
}

bool Pop(Stack2 *s){
	if(!IsEmpty(*s)){
		s->count--;
	}
}

String *Peek(Stack2 s, bool type){
	String *find = malloc(sizeof(String));
	(type == false) ?  strcpy(*find, s.elems[s.count - 1].program) : strcpy(*find, s.elems[s.count - 1].studName.lname);
	return find;
}

bool IsFound(Stack2 s, String lastname){
	while(!IsEmpty(s)){
		
		String *peeklname = Peek(s, true);
	
		if(strcmp ( *peeklname , lastname ) == 0){
			free(peeklname);
			return true; 
		}
		free(peeklname);
		Pop(&s);
	}
	
	
	return false;
}

Name *getStudentInProgram(Stack2 s, String program){
	Name *student = malloc(sizeof(Name)); 
	
	
	
	while(!IsEmpty(s)){
		String *peekcourse = Peek(s, false);
		if(strcmp ( *peekcourse, program ) == 0){
			free(peekcourse);
			*student = s.elems[s.count-1].studName;
			return student;
		}
		free(peekcourse);
		Pop(&s);
	}
}

Name createName(String fname, String mname, String lname){
	Name neww;
	strcpy(neww.fname, fname);
	strcpy(neww.mname, mname);
	strcpy(neww.lname, lname);
	return neww;
}

Student createStudent(int studID, Name studName, String program, int year){
	Student neww;
	neww.studName = studName;
	neww.studID = studID;
	neww.year = year;
	strcpy(neww.program, program);
	return neww;
}
