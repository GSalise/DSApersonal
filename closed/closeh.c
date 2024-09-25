#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "closeh.h"

int hash(Student s, int max){
	int hash=0;
	
	while(s.studID > 0){
		if(s.studID & 1){
			hash++;
		}
		s.studID>>=1;
	}
	
	return (hash +31) % max;
}

void init(StudDictionary *sd, int max){
	
	sd->max = max;
	sd->count = 0;
	sd->data = malloc(sizeof(Student) * max);
	
	for(int i=0; i<max; i++){
		sd->data[i].studID = 0;
	}
	
}
//	int pk = sd->max * .8;
bool insert(StudDictionary *sd, Student s){
	int coll = 0;
	bool free = false;
	
	printf("%d", hash(s, sd->max));
	if((sd->count + 1) < (sd->max * .8)){
		
		if(sd->data[hash(s, sd->max)].studID == 0){
			sd->data[hash(s, sd->max)] = s;
		}else{
			while(!free){
				coll++;
				if(sd->data[(hash(s, sd->max) + coll) % sd->max].studID == 0){
					free = true;
					sd->data[(hash(s, sd->max) + coll) % sd->max] = s;
				}	
			}
		}
		sd->count++;
		return true;
	}else{
		sd->data = realloc(sd->data, sizeof(Student) * (sd->max * 2));
		sd->max *= 2;
		
		for(int i = sd->max/2; i < sd->max; i++){
			sd->data[i].studID = 0;
		}
		
		for(int i = 0; i < sd->max; i++){
			if(sd->data[i].studID > 0){
				insert(sd, sd->data[i]);
			}else if(sd->data[i].studID == 0 || sd->data[i].studID == NULL){
				sd->data[i].studID = 0;
			}else if(sd->data[i].studID == -1){
				sd->data[i].studID == -1;
			}
		}
		
		
	}
	

}

bool removeStudent(StudDictionary *sd, Student s){
	bool exists = true;
	bool found = false;
	int i = 1;
	if(sd->data[hash(s, sd->max)].studID == s.studID){
		sd->data[hash(s, sd->max)].studID = -1;
		return true;
		
	}else{
		
		while(exists == true && found == false){
			if(sd->data[((hash(s, sd->max)) + i) % sd->max].studID == 0){
				exists = false;
			}else if(sd->data[((hash(s, sd->max)) + i) % sd->max].studID == s.studID){
				found = true;
			}		
			i++;
		}
		
		if(found == true){
			sd->data[((hash(s, sd->max)) + i-1) % sd->max].studID = -1;
			return true;
		}
		
		if(exists == false){
			return false;
		}
		
		
		
	}

}

void get(StudDictionary *sd, int studentID){
	
}

void visualize(StudDictionary sd){
	printf("\n--------Count: %d--Max: %d---------\n", sd.count, sd.max);
	for(int i=0; i<sd.max; i++){
		if(sd.data[i].studID == 0){
			printf("SD[%d]: EMPTY\n", i);
		}else if(sd.data[i].studID == -1){
			printf("SD[%d]: DELETED\n", i);
		}else{
			printf("SD[%d]: %s - %d\n", i, sd.data[i].studName, sd.data[i].studID);
		}
	}
	printf("\n-----------------------\n");
}

Student makeStud(int ID, char name[16], char prog[16], bool sex, int lvl){
	Student neww;
	neww.studID = ID;
	strcpy(neww.studName, name);
	strcpy(neww.program, prog);
	neww.sex = sex;
	neww.level = lvl;
	return neww;
}
