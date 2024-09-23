#ifndef HASH_H
#define HASH_H

#define MAX 10


typedef struct{
	int studID;
	char studName[20];
	bool sex; // t - male f- female
	char program[8];
	int level;
}Student;

//hash func
//count num of 1 in studId
// first 3 letters in name
// entire program


typedef struct node{
	Student stud;
	struct node *link;
}NodeType, *NodePtr;

typedef struct{
	NodePtr elems[MAX];
	int count;
}Dictionary;
//curr->link!=NULL && strcmp(curr->stud.studName, s.studName) < 0

int getHash(Student s);
void initDictionary(Dictionary *d);
bool addStudent(Dictionary *d, Student s);
bool removeStudent(Dictionary *d, Student s);
Student getStudent(Dictionary d, Student s);
void visualize(Dictionary d);

Student makeStud(int ID, char name[20], bool s, char program[8], int lvl);

#endif
