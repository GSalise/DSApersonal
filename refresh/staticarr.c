#include <stdio.h>
#include "staticarr.h"

void display(List l){
	printf("Count: %d\n", l.count);
	printf("List: ");
	for(int i=0; i<l.count; i++){
		printf("%d ", l.items[i]);
	}
	printf("\n\n");
}

List insertFront(List l, int data){
	if(l.count!=0){
		for(int i=l.count; i>0; i--){
			l.items[i]=l.items[i-1];
		}
		l.items[0]=data;
		l.count++;
	}else{
		l.items[0]=data;
		l.count++;
	}
	
	return l;
}

List insertEnd(List l, int data){
	if(l.count!=0){
		int pos=0;
		while(pos<l.count){
			pos++;
		}
		l.items[pos]=data;
		l.count++;
	}else{
		l.items[0]=data;
		l.count++;
	}
	
	return l;
}

List insertINTO(List l, int data, int pos){
	if(l.count!=0){
		int i=l.count;
		while(i>pos-1){
			l.items[i]=l.items[i-1];
			i--;
		}
		l.items[i]=data;
		l.count++;
	}else{
		l.items[0]=data;
		l.count++;
	}
	
	return l;
}

List deleteAtPos(List l, int pos){
	for(int i=pos-1; i<l.count; i++){
		l.items[i]=l.items[i+1];
	}
	l.count--;
	
	return l;
}

List deleteOccurence(List l, int data){
	for(int i=0; i<l.count; i++){
		if(l.items[i]==data){
			l=deleteAtPos(l, i+1);
			i--;
		}
	}
	
	return l;
}

List deleteFront(List l){
	l=deleteAtPos(l, 1);
	return l;
}

List deleteEnd(List l){
	l=deleteAtPos(l, l.count);
	return l;
}
