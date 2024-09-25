#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "closeh.h"

int main(){
	
//	makeStud(100, "George", "BSIT", true, 2) - 4
//	makeStud(200, "Adriane", "BSIT", true, 4) - 4
//	makeStud(300, "Dean", "BSIS", false, 1) - 5
//	makeStud(400, "Peteros", "BSCS", false, 3) - 4
//	makeStud(500, "Salise", "BSCS", true, 2) - 7


	StudDictionary sd;
	init(&sd, 5);
	
	insert(&sd, makeStud(100, "George", "BSIT", true, 2));
	insert(&sd, makeStud(200, "Adriane", "BSIT", true, 4));
	insert(&sd, makeStud(300, "Dean", "BSIS", false, 1));
	insert(&sd, makeStud(400, "Peteros", "BSCS", false, 3));
	insert(&sd, makeStud(500, "Salise", "BSCS", true, 2));
	visualize(sd);
//	printf("%d", sd.max);
//	removeStudent(&sd, makeStud(400, "Peteros", "BSCS", false, 3));
//	removeStudent(&sd, makeStud(995, "Salise", "BSCS", true, 2));
//	removeStudent(&sd, makeStud(200, "Adriane", "BSIT", true, 4));
//	removeStudent(&sd, makeStud(500, "Salise", "BSCS", true, 2));
//	removeStudent(&sd, makeStud(156, "Salise", "BSCS", true, 2));
//	visualize(sd);
	
	
	return 0;
}
