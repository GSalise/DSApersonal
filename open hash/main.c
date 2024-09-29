#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hash.h"

int main(){
	Dictionary d;
	initDictionary(&d);
	

	
//	printf("%d\n", getHash(makeStud(135, "George", true, "BSIT", 2)));
//	printf("%d\n", getHash(makeStud(128, "Adriane", true, "BSIS", 2))); 
//	printf("%d\n", getHash(makeStud(101, "Dean", true, "BSIT", 2))); //sqame
//	printf("%d\n", getHash(makeStud(100, "Peteros", true, "BSIT", 2))); //same
//	printf("%d\n", getHash(makeStud(120, "Salise", true, "BSIT", 2))); 
//	printf("%d\n", getHash(makeStud(121, "Dea", true, "BSB", 2))); //same
//	printf("\n\n\n");


	addStudent(&d, makeStud(135, "George", true, "BSIT", 2));
	addStudent(&d, makeStud(128, "Adriane", true, "BSIS", 2));
	addStudent(&d, makeStud(101, "Dean", true, "BSIT", 2)); //S2
	addStudent(&d, makeStud(100, "Peteros", true, "BSIT", 2)); //S1
	addStudent(&d, makeStud(120, "Salise", true, "BSIT", 2));
	addStudent(&d, makeStud(121, "Dea", true, "BSB", 2)); //S3 	
	visualize(d);		
	
	printf("\n{%s - %d}", getStudent(d, makeStud(121, "Dea", true, "BSB", 2)).studName, getStudent(d, makeStud(121, "Dea", true, "BSB", 2)).studID);
	
//	removeStudent(&d, makeStud(121, "Dea", true, "BSB", 2));
//	removeStudent(&d, makeStud(120, "Salise", true, "BSIT", 2));
//	visualize(d);

	

	
	return 0;
}
