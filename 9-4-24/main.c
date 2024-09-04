#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "MyData.h"
#include "MyQueue.h"

int main(){
	
	Name s1;
	strcpy(s1.fname, "George");
	strcpy(s1.lname, "Salise");
	Name s2;
	strcpy(s2.fname, "Adriane");
	strcpy(s2.lname, "Dean");
	Name s3;
	strcpy(s3.fname, "Enciodas");
	strcpy(s3.lname, "Silverash");
	Name s4;
	strcpy(s4.fname, "Maria");
	strcpy(s4.lname, "Nearl");
	Name s5;
	strcpy(s5.fname, "Kal'tsit");
	strcpy(s5.lname, "AMA-10");
	

	
	Student stud1;
	stud1.studName = s1;
	stud1.sex = 'm';
	stud1.studID = 1001;
	strcpy(stud1.program, "BSIT");
	
	Student stud2;
	stud2.studName = s2;
	stud2.sex = 'm';
	stud2.studID = 2002;
	strcpy(stud2.program, "BSIT");
	
	Student stud3;
	stud3.studName = s3;
	stud3.sex = 'm';
	stud3.studID = 3003;
	strcpy(stud3.program, "BSCS");
	
	Student stud4;
	stud4.studName = s4;
	stud4.sex = 'f';
	stud4.studID = 4004;
	strcpy(stud4.program, "BSIS");
	
	Student stud5;
	stud5.studName = s5 ;
	stud5.sex = 'f';
	stud5.studID = 5005;
	strcpy(stud5.program, "BSCS");
	
	Queue list;
	initQueue(&list);
	printf("Is queue empty? %d\n\n", isEmpty(list));
	
	
	
	enqueue(&list, stud1);
	enqueue(&list, stud2);
	enqueue(&list, stud3);
	enqueue(&list, stud4);
	enqueue(&list, stud5);
	printf("Is queue empty? %d\n\n", isEmpty(list));
	Name *test = getStudent(list, "BSCS", ' ');
	
	int i=0;
	while(strcmp(test[i].fname, " ") != 0 && strcmp(test[i].lname, " ") != 0){
		printf("%s\n", test[i].fname);
		i++;
	}
	
//	display(list);
//	visualize(list);
	return 0; 	
}
