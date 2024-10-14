#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

int main (){
	Stack s;
	initStack(&s);
	Stack t;
	initStack(&t);
	
	Person a;
	Person b;
	Person c;
	Person d;
	Person e;
	
	a.age = 20;
	strcpy(a.name, "J");
	a.sex = 'm';
	
	b.age = 20;
	strcpy(b.name, "C");
	b.sex = 'm';
	
	c.age = 20;
	strcpy(c.name, "F");
	c.sex = 'f';
	
	d.age = 20;
	strcpy(d.name, "B");
	d.sex = 'm';
	
	e.age = 20;
	strcpy(e.name, "D");
	e.sex = 'f';
	
//	push(&s, a);
//	push(&s, b);
//	push(&s, c);
//	push(&s, d);
//	push(&s, e);


//	insertSorted1(&s, a);
////	displayStack(s);
//	insertSorted1(&s, b);
////	displayStack(s);
//	insertSorted1(&s, c);
////	displayStack(s);
//	insertSorted1(&s, d);
////	displayStack(s);
//	insertSorted1(&s, e);
//	displayStack(s);
	

	insertSorted2(&t, a);
	displayStack(t);
	insertSorted2(&t, b);
	displayStack(t);
	insertSorted2(&t, c);
	displayStack(t);
	insertSorted2(&t, d);
	displayStack(t);
	insertSorted2(&t, e);
	displayStack(t);
	
//	displayStack(s);
//	sortStack(&s, true);
//	displayStack(s);
//	sortStack(&s, false);
//	displayStack(s);
	
	return 0;
}
