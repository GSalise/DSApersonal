#ifndef MY_DATA_H
#define MY_DATA_H

typedef struct{
	char fname[20];
	char lname[20];
}Name;

typedef struct{
	int studID;
	Name studName;
	char program[8];
	char sex; //f or m
}Student;

#endif
