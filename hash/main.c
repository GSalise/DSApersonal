#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hash.h"

int main(){
	Dictionary d;
	initDictionary(&d);
	

	
	printf("%d\n", getHash(makeStud(135, "George", true, "BSIT", 2)));
	printf("%d\n", getHash(makeStud(128, "Adriane", true, "BSIS", 2))); //same
	printf("%d\n", getHash(makeStud(101, "Dean", true, "BSIT", 2)));
	printf("%d\n", getHash(makeStud(050, "Peteros", true, "BSIT", 2))); //same
	
	printf("\n\n\n");
	
	addStudent(&d, makeStud(135, "George", true, "BSIT", 2));

	addStudent(&d, makeStud(128, "Adriane", true, "BSIS", 2));

	addStudent(&d, makeStud(101, "Dean", true, "BSIT", 2));

	addStudent(&d, makeStud(050, "Peteros", true, "BSIT", 2));
	
	visualize(d);	
	
	return 0;
}
