#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Queuel.h"


int main(){
	Queue a;
	initQueue(&a);
	
	printf("%d", isEmpty(a));

	
//	enqueue(&a, makeStud(makeName("George", "Salise"), 2, "BSIT", 'M'));
//	enqueue(&a, makeStud(makeName("Adriane", "Dean"), 1, "BSIT", 'M'));
//	enqueue(&a, makeStud(makeName("Enciodas", "Silverash"), 1, "BSCS", 'M'));
//	enqueue(&a, makeStud(makeName("AMA-10", "Kal'tsit"), 5, "BSCS", 'F'));
//	enqueue(&a, makeStud(makeName("Maria", "Nearl"), 1, "BSIS", 'F'));
//	enqueue(&a, makeStud(makeName("Dante", "Dante"), 4, "BSIS", 'M'));
//	enqueue(&a, makeStud(makeName("Virgil", "Virgil"), 4, "BSIS", 'M'));
//	enqueue(&a, makeStud(makeName("Toki", "Doki"), 2, "BSIT", 'F'));
//	enqueue(&a, makeStud(makeName("Beth", "Arabelle"), 2, "BSIS", 'F'));
//	enqueue(&a, makeStud(makeName("Shu", "Sui"), 2, "BSA", 'F'));
//	enqueue(&a, makeStud(makeName("Chongyue", "Sui"), 2, "BPEd", 'M'));
//	enqueue(&a, makeStud(makeName("Ling", "Sui"), 2, "BAH", 'F'));
//	enqueue(&a, makeStud(makeName("Dusk", "Sui"), 2, "BFAP", 'F'));
//	enqueue(&a, makeStud(makeName("Nian", "Sui"), 2, "BSCS", 'F'));
//	
//	displayQ(a);
	
	printf("\n\n%d\n\n", compareName(makeName("George", "Aaaa"), makeName("Adriane", "Dean")));
	
	Queue b;
	initQueue(&b);
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
	displayQ(b);
	
	
	
	return 0;
}
