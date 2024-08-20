#include <stdio.h>
#include <stdlib.h>
#include "dynamicarr.h"

void DAdisplay(List l){
	printf("Count : %d", l.count);
	printf("\nMax: %d", l.max);
	printf("\nList: ");
	for(int i=0; i<l.count; i++){
		printf("%d ", l.items[i]);
	}
	printf("\n\n");
}

List DAinsertFRONT(List l, int data){
	if(l.count == l.max){
		l.max++;
		l.items=realloc(l.items, l.max * sizeof(int));
		
		for(int i=l.count; i>0; i--){
			l.items[i]=l.items[i-1];
		}
		
		l.count++;
		l.items[0]=data;
	
	}else if(l.count!=0){
		for(int i=l.count; i>0; i--){
			l.items[i]=l.items[i-1];
		}
		l.count++;
		l.items[0]=data;
	
	}else{
		l.items=malloc(l.max*sizeof(int));
		l.items[0]=data;
		l.count++;
	}
	return l;
}

List DAinsertEND(List l, int data){
	if(l.count == l.max){
		l.max++;
		l.items=realloc(l.items, l.max * sizeof(int));
		l.items[l.count]=data;
		l.count++;
	}else{
		l.items[l.count]=data;
		l.count++;
	}
	return l;
}

List DAinsertAtPos(List l, int data, int pos){
	int i=l.count;
	
	if(l.count==l.max){
		l.max++;
		l.items=realloc(l.items, l.max * sizeof(int));
	while(i!=pos-1){
		l.items[i]=l.items[i-1];
		i--;
	}
	l.items[i]=data;
	l.count++;
	
	}else{
	while(i!=pos-1){
		l.items[i]=l.items[i-1];
		i--;
	}
	l.items[i]=data;
	l.count++;
	}


	return l;
}

List DAdeleteAtPos(List l, int pos){
	for(int i=pos-1; i<l.count; i++){
		l.items[i]=l.items[i+1];
	}
	l.count--;
	l.max--;
	l.items=realloc(l.items, l.max * sizeof(int));
	
	return l;
}

List DAdeleteOccurence(List l, int data){
	for(int i=0; i<l.count; i++){
		if(l.items[i]==data){
			l=DAdeleteAtPos(l, i+1);
			i--;
		}
	}
	
	return l;
}

List DAdeleteFront(List l){
	l=DAdeleteAtPos(l, 1);
	return l;
}

List DAdeleteEnd(List l){
	l=DAdeleteAtPos(l, l.count);
	return l;
}
