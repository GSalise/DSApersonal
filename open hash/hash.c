#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hash.h"

int getHash(Student s){
//hash func
//count num of 1 in studId
// first 3 letters in name
// entire program

	int hash=0;
	int temp = s.studID;
	
	while(temp > 0){
		if(temp & 1){
			hash++;
		}
		
		temp>>=1;
	}
	
	
	hash += s.studName[0] + s.studName[1] + s.studName[2];
	
	for(int i=0; s.program[i] != '\0'; i++){
		hash+= s.program[i];
	}
	
	hash %= MAX;


	return hash;
}

void initDictionary(Dictionary *d){
	d->count = 0;
	
	for(int i=0; i<MAX; i++){
		d->elems[i] = NULL;
	}
	
}

bool addStudent(Dictionary *d, Student s){
	int val = getHash(s);
	NodePtr neww = malloc(sizeof(NodeType));
	neww->link = NULL;
	neww->stud = s;
	
	if(d->elems[val] == NULL){
		d->elems[val] = neww;
	}else{
		NodePtr curr = d->elems[val];
		NodePtr prev;
		
		while(curr!=NULL && curr->stud.studID > s.studID){
			prev = curr;
			curr=curr->link;
		}
		
		
		if(prev == d->elems[val]){
			neww->link = d->elems[val];
			d->elems[val] = neww;
		}else{
			prev->link = neww;
		}
	
	}
	
	d->count++;
	
}

bool removeStudent(Dictionary *d, Student s){
	int val = getHash(s);
	
	if(d->elems[val] == NULL){
		return false;
	}else{
		if(d->elems[val]->stud.studID != s.studID){
			NodePtr curr = d->elems[val];
			while(curr->link->stud.studID != s.studID){
				curr=curr->link;
			}
			curr->link = NULL;
		}else{
			d->elems[val] = NULL;
		}
		d->count--;
	}
	
	
}

Student getStudent(Dictionary d, Student s){
	int val = getHash(s);
	
	if(d.elems[val] == NULL){
		
	}else{
		if(d.elems[val]->stud.studID != s.studID){
			NodePtr curr = d.elems[val];
			while(curr->stud.studID != s.studID){
				curr=curr->link;
			}
			return curr->stud;
		}else{
			return d.elems[val]->stud;
		}
	}
}

void visualize(Dictionary d){
	
	printf("\n\n----------Count: %d--------\n", d.count);
	
	for(int i=0; i<MAX; i++){
		
		printf("[%d] = ", i);
		
		if(d.elems[i]==NULL){
			printf("empty");
		}else{
			while(d.elems[i]!=NULL){
				printf("{%s -- %d}", d.elems[i]->stud.studName, d.elems[i]->stud.studID);
				d.elems[i] = d.elems[i]->link;
			}
			
		}

		
		printf("\n");
	}
	
	printf("------------------\n");
	
}
//typedef struct{
//	int studID;
//	char studName[20];
//	bool sex; // t - male f- female
//	char program[8];
//	int level;
//}Student;

Student makeStud(int ID, char name[20], bool s, char program[8], int lvl){
	Student neww;
	neww.studID = ID;
	strcpy(neww.studName, name);
	neww.level = lvl;
	neww.sex = s;
	strcpy(neww.program, program);
	return neww;
}
