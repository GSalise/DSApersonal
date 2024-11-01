#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct{
    int studID;
    char studName[20];
    bool sex; // t - male f- female
    char program[8];
    int level;
}Student;

typedef struct node{
	Student stud;
	struct node *link;
}NodeType, *NodePtr;

typedef struct{
	NodePtr elems[MAX];
	int count;
}Dictionary;

Student makeStud(int ID, const char* name, bool s, const char* program, int lvl) {
    Student neww;
    neww.studID = ID;
    neww.level = lvl;
    neww.sex = s;
    strncpy(neww.studName, name, sizeof(neww.studName) - 1);
    neww.studName[sizeof(neww.studName) - 1] = '\0'; 
    strncpy(neww.program, program, sizeof(neww.program) - 1);
    neww.program[sizeof(neww.program) - 1] = '\0'; 
    return neww;
}

/*
    The hash value is made from the following:
    - Number of 1s in studID
    - First 3 letters of studName
    - Entire program string
*/

int getHash(Student s){
    int hash = 0;

    while(s.studID > 0){
        if(s.studID & 1){
            hash++;
        }
        s.studID>>=1;
    }

    hash += s.studName[0] + s.studName[1] + s.studName[2];

    for(int i = 0; i<strlen(s.program); i++){
        hash += s.program[i];
    }

    return hash %= MAX;

}

void init(Dictionary *d){
    d->count = 0;
    for(int i = 0; i<MAX; i++){
        d->elems[i] = NULL;
    }
}


void add(Dictionary *d, Student s){
    int key = getHash(s);

    NodePtr neww = malloc(sizeof(NodeType));
    neww->link = NULL;
    neww->stud = s;

    if(d->elems[key] == NULL){
        d->elems[key] = neww;
    }else{
        NodePtr curr = d->elems[key];

        if(curr->stud.studID > s.studID){
            neww->link = curr;
            d->elems[key] = neww;
        }else{
            while(curr->link!=NULL && curr->link->stud.studID < s.studID){
                curr = curr->link;
            }
            neww->link = curr->link;
            curr->link = neww;
        }
    }
    d->count++;

}


void visualize(Dictionary d){
    printf("\n");
    for(int i = 0; i<MAX; i++){
        if(d.elems[i] == NULL){
            printf("[%d] = NULL", i);
        }else{
            printf("[%d] = ", i);
            while(d.elems[i]!=NULL){
                printf("{%s - %d} ", d.elems[i]->stud.studName, d.elems[i]->stud.studID);
                d.elems[i] = d.elems[i]->link;
            }
        }
        printf("\n");
    }
}





int main(){
    Dictionary d;
    init(&d);

    add(&d, makeStud(135, "George", true, "BSIT", 2));
	add(&d, makeStud(128, "Adriane", true, "BSIS", 2));
	add(&d, makeStud(101, "Dean", true, "BSIT", 2)); //S2
	add(&d, makeStud(100, "Peteros", true, "BSIT", 2)); //S1
	add(&d, makeStud(120, "Salise", true, "BSIT", 2));
	add(&d, makeStud(121, "Dea", true, "BSB", 2)); //S3 	

    visualize(d);

    return 0;
}