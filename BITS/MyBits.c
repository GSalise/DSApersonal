#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MyBits.h"



Set createSet(){
	Set neww;
	neww.count=0;
	
	for(int i=0; i<MAX; i++){
		neww.elems[i]=0;
	}
	
	return neww;
}

bool addElement(Set *s, int item){
	if(s->elems[item]!=1){
		s->elems[item]=1;
		s->count++;
	}
}

bool removeElement(Set *s, int item){
	if(s->elems[item]!=0){
		s->elems[item]=0;
		s->count--;
	}
}

void displaySet(Set s){
	int flag=0, i=0;
	
	while(flag<s.count){
		if(s.elems[i]==1){
			printf("%d ", i);
			flag++;
		}
		i++;
	}
}

Set unionSet(Set a, Set b){
	Set neww = createSet();
	
	int i=0;
	while(i<MAX){
		if(a.elems[i] == 1){
			neww.elems[i] = 1;
			neww.count++;
		}else if(b.elems[i] == 1){
			neww.elems[i] = 1;
			neww.count++;
		}
		i++;
	}
	

	
	
	return neww;
}

Set intersectionSet(Set a, Set b){
	Set neww = createSet();
	int i=0;
	
	while(i<MAX){
	if((a.elems[i] && b.elems[i])==1){	
		neww.elems[i]=1;
		neww.count++;
	}
		i++;
	}
	
	return neww;
}
Set differenceSet(Set a, Set b){
	Set neww = createSet();
	int i=0; 
	
	while(i<MAX){
		if(a.elems[i] == 1 && b.elems[i] == 0){
			neww.elems[i]=1;
			neww.count++;
		}
		i++;
	}
	
	return neww;
}

Set symmetricDifferenceSet(Set a, Set b){
	Set A = differenceSet(a, b);
	Set B = differenceSet(b, a);
	Set neww = unionSet(A,B);
	return neww;
	
}

int cardinality(Set s){
	return s.count;
}

bool isElement(Set s, int item){
	return (s.elems[item]==1) ? true : false;
}

