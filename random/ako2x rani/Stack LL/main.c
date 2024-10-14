#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ArrPracLL.h"


int main(){
	Stack a;
	initS(&a);
	Stack b;
	initS(&b);
	
	push(&a, makeStud(makeName("George", "Salise"), 2, "BSIT", 'M'));
	push(&a, makeStud(makeName("Adriane", "Dean"), 1, "BSIT", 'M'));
	push(&a, makeStud(makeName("Enciodas", "Silverash"), 1, "BSCS", 'M'));
	push(&a, makeStud(makeName("AMA-10", "Kal'tsit"), 5, "BSCS", 'F'));
	push(&a, makeStud(makeName("Maria", "Nearl"), 1, "BSIS", 'F'));
	push(&a, makeStud(makeName("Dante", "Dante"), 4, "BSIS", 'M'));
	push(&a, makeStud(makeName("Virgil", "Virgil"), 4, "BSIS", 'M'));
	push(&a, makeStud(makeName("Toki", "Doki"), 2, "BSIT", 'F'));
	push(&a, makeStud(makeName("Beth", "Arabelle"), 2, "BSIS", 'F'));
	push(&a, makeStud(makeName("Shu", "Sui"), 2, "BSA", 'F'));
	push(&a, makeStud(makeName("Chongyue", "Sui"), 2, "BPEd", 'M'));
	push(&a, makeStud(makeName("Ling", "Sui"), 2, "BAH", 'F'));
	push(&a, makeStud(makeName("Dusk", "Sui"), 2, "BFAP", 'F'));
	push(&a, makeStud(makeName("Nian", "Sui"), 2, "BSCS", 'F'));
	display(a);
	
	
	
	insertSorted(&b, makeStud(makeName("George", "Salise"), 2, "BSIT", 'M'));
	insertSorted(&b, makeStud(makeName("Adriane", "Dean"), 1, "BSIT", 'M'));
	insertSorted(&b, makeStud(makeName("Enciodas", "Silverash"), 1, "BSCS", 'M'));
	insertSorted(&b, makeStud(makeName("AMA-10", "Kal'tsit"), 5, "BSCS", 'F'));
	insertSorted(&b, makeStud(makeName("Maria", "Nearl"), 1, "BSIS", 'F'));
	insertSorted(&b, makeStud(makeName("Dante", "Dante"), 4, "BSIS", 'M'));
	insertSorted(&b, makeStud(makeName("Virgil", "Virgil"), 4, "BSIS", 'M'));
	insertSorted(&b, makeStud(makeName("Toki", "Doki"), 2, "BSIT", 'F'));
	insertSorted(&b, makeStud(makeName("Beth", "Arabelle"), 2, "BSIS", 'F'));
	insertSorted(&b, makeStud(makeName("Shu", "Sui"), 2, "BSA", 'F'));
	insertSorted(&b, makeStud(makeName("Chongyue", "Sui"), 2, "BPEd", 'M'));
	insertSorted(&b, makeStud(makeName("Ling", "Sui"), 2, "BAH", 'F'));
	insertSorted(&b, makeStud(makeName("Dusk", "Sui"), 2, "BFAP", 'F'));
	insertSorted(&b, makeStud(makeName("Nian", "Sui"), 2, "BSCS", 'F'));
	display(b);
	
	return 0;
}
