#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Queue.h"

int main(){
	NQueue q;
	initNQueue(&q);
	
	Name a;
	Name b;
	Name c;
	Name d;
	Name e;
	Name f;
	Name g;
	
	strcpy(a.fname, "George");
	strcpy(a.lname, "AA");
	
	strcpy(b.fname, "Adriane");
	strcpy(b.lname, "CC");
	
	strcpy(c.fname, "Mark");
	strcpy(c.lname, "FF");
	
	strcpy(d.fname, "Joel");
	strcpy(d.lname, "BB");
	
	strcpy(e.fname, "Test");
	strcpy(e.lname, "EE");
	
	strcpy(f.fname, "Tom");
	strcpy(f.lname, "WW");
	
	strcpy(g.fname, "Jeff");
	strcpy(g.lname, "GG");
	
	
	//printf("%d", isEmpty(a));
	enqueue(&q, a);
	enqueue(&q, b);
	enqueue(&q, c);
	enqueue(&q, d);
	enqueue(&q, e);
	enqueue(&q, f);
	enqueue(&q, g);
	
	displayQueue(q);
	
	
//	printf("\n\n---------------\n");
//	Name *test = filterNames(&q, "FF");
//	int i=0;
//	while(strcmp(test[i].fname, "Sentinel") != 0){
//		printf("%s - %s\n", test[i].fname, test[i].lname);
//		i++;
//	}
//	printf("---------------\n\n");
	
	NQueue z;
	initNQueue(&z);
	insertSorted(&z ,a);
	displayQueue(z);
	insertSorted(&z ,b);
	displayQueue(z);
	insertSorted(&z ,c);
	displayQueue(z);
	insertSorted(&z ,d);
	displayQueue(z);
	insertSorted(&z ,e);
	displayQueue(z);
	
	
	
	
	
	
	return 0;
}
