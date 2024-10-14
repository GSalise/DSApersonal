#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "MyStack.h"
//#include "MyStack2.h"

int main(){
	
	Stack A;
	initStack(&A);
	
	printf("Is this empty? %d\n", isEmpty(A));
	printf("Is this full? %d\n", isFull(A));
	push(&A, 1);
	push(&A, 2);
	push(&A, 3);
	push(&A, 4);
	push(&A, 5);
	push(&A, 0);
	
	printf("\n");
	visual(A);
	printf("\n\n\n");
	
//	pop(&A);
//	pop(&A);
//	pop(&A);
//	push(&A, 99);
//	push(&A, 88);

	

//	int x=0;
//	printf("Is %d present? %d\n", x, isFound(A, x)); 

	Stack EVEN;
	initStack(&EVEN);
	
	EVEN=removeEven(&A);
	printf("\n");
	visual(EVEN);
	printf("\n");
	
	printf("\n");
	visual(A);
	printf("\n");


//	Name test = createName("George", "Adriane", "Salise"); 
//	Name test1 = createName("Mike", "Hart", "Tomato"); 
//	Name test2 = createName("Vacon", "Lettuc", "Cheese"); 
//	Name test3 = createName("Dean", "Peteros", "Vasq"); 
//	Name test4 = createName("Dominic", "Qeuq", "Matterhorn"); 
//	Name test5 = createName("TEST", "TEST", "TEST"); 
//	
//	Student a = createStudent(100, test, "BSIT", 2023);
//	Student b = createStudent(200, test1, "BSCS", 2020);
//	Student c = createStudent(300, test2, "BSIS", 2016);
//	Student d = createStudent(400, test3, "BSCE", 2015);
//	Student e = createStudent(500, test4, "BSCE", 2022);
//	Student f = createStudent(600, test5, "BSCE", 2024);
//	
//	Stack2 studREC;
//	InitStack(&studREC);
//	printf("Is this empty? %d\n", IsEmpty(studREC));
//	printf("Is this full? %d\n", IsFull(studREC));
//	Push(&studREC, a);
//	Push(&studREC, b);
//	Push(&studREC, c);
//	Push(&studREC, d);
//	Push(&studREC, e);
//	Push(&studREC, f);
//	printf("\n");
//	printf("\n");
//	visualize(studREC);
//	printf("\n");
//	printf("\n");
//	Pop(&studREC); 
//	Pop(&studREC);
//	printf("\n");
//	printf("\n");
//	visualize(studREC);
//	printf("\n");
//	printf("\n");
//	Push(&studREC, f);
//	printf("\n");
//	printf("\n");
//	visualize(studREC);
//	printf("\n");
//	printf("\n");
//	printf("Is %s present? %d\n", test1.lname , IsFound(studREC, test1.lname)); 
//	
//	Name *findstud = getStudentInProgram(studREC, "BSCE");
//	printf("\n\n%s-%s-%s\n\n", findstud->fname, findstud->mname, findstud->lname);
	
	
	return 0;
}
